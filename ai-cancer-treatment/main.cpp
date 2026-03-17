// AI Cancer Treatment Expert System — Main Driver
//
// Integrates Backward Chaining (diagnosis) and Forward Chaining
// (treatment recommendation via decision trees) into a single pipeline.
//
// Compile:  make   (or see Makefile for manual g++ command)
// Run:      ./cancer-expert-system

#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>

#include "ruleBase/ruleBase.h"
#include "decisionTree/decisionTree.h"

using namespace std;


// ─────────────────────────────────────────────────────────────────────────────
//  Utility helpers
// ─────────────────────────────────────────────────────────────────────────────

// Returns true if element is already present in vec.
template <typename T>
bool elementExists(const vector<T>& vec, const T& element) {
    return find(vec.begin(), vec.end(), element) != vec.end();
}

// Returns a lowercase copy of str.
string strToLower(string str) {
    for (char& c : str) c = tolower(static_cast<unsigned char>(c));
    return str;
}


// ─────────────────────────────────────────────────────────────────────────────
//  Backward-Chaining helper functions
//  (mirrors backwardChaining.cpp logic without its own main())
// ─────────────────────────────────────────────────────────────────────────────

// Returns true if clause is present (case-insensitive) in rawClauseVect.
// Runtime: O(n), where n = number of user-provided clause strings.
bool isClauseInUserList(const ClauseType& clause,
                        const vector<string>& rawClauseVect,
                        RuleBase& rb) {
    const string strL = strToLower(rb.ClauseTypeToString(clause));
    for (const auto& s : rawClauseVect) {
        if (strL == strToLower(s)) return true;
    }
    return false;
}

// Filters raw string symptoms to ClauseTypes recognized by the RuleBase.
// Runtime: O(n * m * z) — n rules, m clauses/rule, z user strings.
vector<ClauseType> filterRawClauseVect(const vector<string>& rawVect,
                                       RuleBase& rb) {
    vector<ClauseType> valid;
    for (const auto& rule : *rb.ruleList) {
        for (const auto& clause : rule.clauses) {
            if (isClauseInUserList(clause, rawVect, rb) &&
                !elementExists(valid, clause)) {
                valid.push_back(clause);
            }
        }
    }
    return valid;
}

// Parses a comma-separated symptom string and returns valid ClauseTypes.
vector<ClauseType> parseSymptoms(const string& input, RuleBase& rb) {
    vector<string> raw;
    istringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        // Trim leading/trailing whitespace
        size_t start = token.find_first_not_of(" \t");
        size_t end   = token.find_last_not_of(" \t");
        if (start != string::npos)
            raw.push_back(token.substr(start, end - start + 1));
    }
    return filterRawClauseVect(raw, rb);
}

// Generates all 2^n subsets of a clause vector using a bitmask approach.
// Runtime: O(2^n * n).
vector<vector<ClauseType>> generateSubsets(const vector<ClauseType>& clauses) {
    const int n     = static_cast<int>(clauses.size());
    const int total = 1 << n;
    vector<vector<ClauseType>> subsets;
    subsets.reserve(total);

    for (int mask = 0; mask < total; ++mask) {
        vector<ClauseType> subset;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) subset.push_back(clauses[i]);
        subsets.push_back(subset);
    }
    return subsets;
}

// Returns true if every clause in rule is present in subset.
// Runtime: O(n * m) — n rule clauses, m subset elements.
bool checkRuleSatisfaction(const vector<ClauseType>& subset, const Rule& rule) {
    for (const auto& clause : rule.clauses) {
        if (find(subset.begin(), subset.end(), clause) == subset.end())
            return false;
    }
    return true;
}

// Prints every symptom name recognized by the rule base, sorted alphabetically.
void printAvailableSymptoms(RuleBase& rb) {
    vector<string> names;
    for (const auto& kv : *rb.clauseNames)
        names.push_back(kv.second);
    sort(names.begin(), names.end());
    cout << "Recognized symptom names:\n";
    for (const auto& n : names)
        cout << "  - " << n << "\n";
}


// ─────────────────────────────────────────────────────────────────────────────
//  main()
// ─────────────────────────────────────────────────────────────────────────────
int main() {
    // ── Welcome banner ──────────────────────────────────────────────────────
    cout << "\n";
    cout << "======================================================\n";
    cout << "   AI Cancer Treatment Expert System\n";
    cout << "   Rule-Based Intelligent Diagnosis & Treatment\n";
    cout << "======================================================\n\n";

    auto rb = unique_ptr<RuleBase>(new RuleBase());


    // ── STEP 1: Backward Chaining — Diagnosis ────────────────────────────────
    cout << "--- STEP 1: DIAGNOSIS (Backward Chaining) ---\n";
    cout << "Enter the patient's symptoms as comma-separated values.\n";
    cout << "Example: persistent cough, weight loss, chest pain\n\n";
    cout << "Symptoms: ";

    string input;
    getline(cin, input);
    cout << "\n";

    // Parse and validate symptoms
    vector<ClauseType> validClauses = parseSymptoms(input, *rb);

    if (validClauses.empty()) {
        cout << "No recognized symptoms were found.\n\n";
        printAvailableSymptoms(*rb);
        cout << "\nPlease re-run and enter symptom names from the list above.\n";
        return 1;
    }

    cout << "Recognized symptoms (" << validClauses.size() << "):\n";
    for (const auto& c : validClauses)
        cout << "  - " << rb->ClauseTypeToString(c) << "\n";
    cout << "\n";

    // Generate all subsets of valid clauses (power set)
    const int numSubsets = 1 << static_cast<int>(validClauses.size());
    cout << "Evaluating " << numSubsets
         << " symptom subsets against the rule base...\n\n";

    vector<vector<ClauseType>> subsets = generateSubsets(validClauses);

    // Find the first rule satisfied by any subset (goal-driven search)
    // Runtime: O(2^t) where t = number of valid clauses.
    // Early termination via diagnosisFound ensures we stop as soon as a rule
    // is satisfied; diagnosis is only read after diagnosisFound is true.
    bool diagnosisFound = false;
    ConclusionType diagnosis{};  // zero-initialized; only used when diagnosisFound == true

    for (const auto& subset : subsets) {
        for (const auto& rule : *rb->ruleList) {
            if (checkRuleSatisfaction(subset, rule)) {
                diagnosis      = rule.conclusion;
                diagnosisFound = true;
                break;
            }
        }
        if (diagnosisFound) break;
    }

    if (!diagnosisFound) {
        // Show possible conclusions from partial symptom matches (deduplicated).
        cout << "No definitive diagnosis could be made.\n";
        cout << "Possible conditions based on your symptoms:\n";
        set<ConclusionType> seen;
        for (const auto& rule : *rb->ruleList) {
            for (const auto& clause : validClauses) {
                if (find(rule.clauses.begin(), rule.clauses.end(), clause)
                    != rule.clauses.end()) {
                    if (seen.find(rule.conclusion) == seen.end()) {
                        cout << "  - Possible: "
                             << rb->ConclusionTypeToString(rule.conclusion) << "\n";
                        seen.insert(rule.conclusion);
                    }
                    break;
                }
            }
        }
        cout << "\nPlease provide more symptoms for a definitive diagnosis.\n";
        return 0;
    }

    cout << "DIAGNOSIS: " << rb->ConclusionTypeToString(diagnosis) << "\n\n";

    // Standard treatment options from the RuleBase knowledge
    cout << "--- STANDARD TREATMENT OPTIONS ---\n";
    cout << rb->ConclusionTypeToResponse(diagnosis) << "\n\n";


    // ── STEP 2: Forward Chaining — Personalized Treatment Decision Tree ───────
    cout << "--- STEP 2: PERSONALIZED TREATMENT PLAN (Forward Chaining) ---\n";
    auto dt = unique_ptr<DecisionTree>(createDecisionTree(diagnosis));

    if (dt) {
        dt->buildTree();
        cout << "Answer the questions below (yes/no) for a personalized\n";
        cout << "treatment recommendation:\n\n";
        dt->traverseTree();
    } else {
        cout << "No personalized decision tree is available for this cancer type.\n";
        cout << "Please consult an oncologist for individualized treatment options.\n";
    }


    // ── Footer ───────────────────────────────────────────────────────────────
    cout << "\n";
    cout << "======================================================\n";
    cout << "  DISCLAIMER: This system is for educational purposes\n";
    cout << "  only. Always consult a qualified medical professional\n";
    cout << "  for actual diagnosis and treatment decisions.\n";
    cout << "======================================================\n\n";

    return 0;
}