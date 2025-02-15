// Diagnose the specific Cancer (if any) using Backward Chaining 
//   Technology
/*
		Backward Chaining is a goal driven method that adds rule base and fact base to the stack in order to reach the user's goal.

		knowledge base will contain the conditional rules

		variable list: will contain the elements to be tested

		conclusion stack: will contain rule number with is assocated clause number

		Clause variable list: a list that contains elements or statements associated with each clause in the rules. Each clause in the rule base can have up to
		4 statements that need to be tested to determine if the rule is satisfied.

		conclusion list: which is added to after rules are determined to be satisfied.

		CPS#2-25:
			CLAUSE NUMBER = 4* (RULE NUMBER  / 10 - 1) + 1
*/
//
// Goal: determine if the patient has cancer.
// Description: search through the clause list to form a diagnosis conclusion w/ RuleBase
// Post-condition: diagnosed Cancer (if any) is sent 
//   to the fowardChaining via piping and stored in 
//   fact base

//#include "backwardChaining.h"
#include "../ruleBase/ruleBase.h"
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <limits>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

// Template function(s)
template <typename T>
bool elementExists(const vector<T>& vec, const T& element){ // find element in a vector
	return find(vec.begin(), vec.end(), element) != vec.end();
}

// Prototype(s)
vector<ClauseType>* convertVariableListToValidClauseVector(const string &str,
															const RuleBase* myRBasePtr);
string toLower(string & str);
vector<vector<ClauseType>>* generateSubsets(const vector<ClauseType>& userValidClauseList, const RuleBase*);
							


// checkRuleSatisfaction()
// recieves: ClauseType subset and a rule to compare it to. Also recieves pointer to RuleBase object in case needed for testing.
// description: checks whether all clauses of the given rule exist within the subset
// runtime: O( n * m ) , where n is # of clauses in the rule and m is size of the subset
bool checkRuleSatisfaction(const vector<ClauseType>& subset, const Rule& rule, const RuleBase* myRBase) {
    // Iterate through each clause in the rule
    for (const auto& clause : rule.clauses) {
        // Check if the clause is in the subset
        if (find(subset.begin(), subset.end(), clause) == subset.end()) {
            // Clause not found in subset, rule is not satisfied
            return false;
        }
    }
    // All clauses in the rule are satisfied by the subset
    return true;
}

int main() {
	RuleBase* myRuleBase = new RuleBase(); // most-effiecient???
	
    // Retrieve all of the user's clauses and store in variableList[]
    string variableList;
    cout << "Enter Patient's Symptoms as Comma Separated Values (A,B,C,D,E,...):" << endl;
    getline(cin, variableList);

    // Parse into list of valid clauses
    vector<ClauseType>* userValidClauseList = convertVariableListToValidClauseVector(variableList, myRuleBase);
    cout << "User's Valid Clauses: " << userValidClauseList->size() << endl;
    for (int i = 0; i < userValidClauseList->size(); i++) {
        cout << ClauseTypeToString((*userValidClauseList)[i], myRuleBase->clauseNames) << endl;
    }

    // Create all subsets of userValidClauseList
    int numSubsets = pow(2, userValidClauseList->size());
    cout << "\n\nCreating all subsets of userValidClauseList ... ( " << numSubsets << " )" << endl;
    vector<vector<ClauseType>>* subsetsPtr = generateSubsets(*userValidClauseList, myRuleBase);
	

    // Description: Iterate through each subset and compare with each rule in ruleList
	// Runtime: O( S * R * n * m ) where S is # of subsets,
	//							         R is # of rules,
	//									 n is # of clauses in a rule,
	//									 m is # of clauses in the subset.
	//
	//	S = O(2^t), where t is # of user's valid clauses
	//  R = constant (***for now***!!!???)
	//  n < 3 (for now)
	//  m < total # of ClauseTypes
	//  
	//	Because 3 < R < total # of ClauseTypes < O(2^t)
	//  Then, the total runtime is: O(2^t), where t is # of user's valid clauses entered
    bool conclusionFound = false;
    for (const auto& subset : *subsetsPtr) {
        for (const auto& rule : *(myRuleBase->ruleList)) {
            if (checkRuleSatisfaction(subset, rule, myRuleBase)) {
                cout << "\n\nConclusion found with subset: \n{\n";
                for (const auto& clause : subset) {
                    cout << ClauseTypeToString(clause, myRuleBase->clauseNames) << endl;
                }
                cout << "}" << endl;
                conclusionFound = true;
				cout << "Diagnosis: " << myRuleBase->ConclusionTypeToString(rule.conclusion) << endl;
				
                break; // Exit loop if a conclusion is found
            }
        }
        if (conclusionFound) {
            break; // Exit loop if a conclusion is found
        }
    }
	
	
	// If there is no conclusion found, print all rules containing each of user's valid clauses
	//    to alert the user of possible conclusions
	// runtime: O( n * m ), where n is # of rules and m is # of valid clauses
	string str;
	if (!conclusionFound && userValidClauseList->size()) {
		// Iterate through each rule
		for (const auto& rule : *(myRuleBase->ruleList)) {
			// Flag to check if the rule contains any valid clause
			bool ruleContainsValidClause = false;
			
			// Iterate through each user valid clause
			for (const auto& validClause : *userValidClauseList) {
				// Check if the rule contains the valid clause
				if (find(rule.clauses.begin(), rule.clauses.end(), validClause) != rule.clauses.end()) {
					ruleContainsValidClause = true;
					str = myRuleBase->ClauseTypeToString(validClause);
					break; // No need to check further once a valid clause is found
				}
			}
			
			// If the rule contains any valid clause, print the rule and the valid clauses and conclusion
			if (ruleContainsValidClause) {
				cout << "\n\nRule contains " << str <<": \n{\n";
				for (const auto& clause : rule.clauses) {
					cout << myRuleBase->ClauseTypeToString(clause) << endl;
				}
				cout << "}" << endl;
				cout << "Possible Conclusion: " << myRuleBase->ConclusionTypeToString(rule.conclusion) << endl;
			}
		}
	}

    delete userValidClauseList;
    delete subsetsPtr;

    // Return the result to forwardChainings


    return 0;
}

// compareClauseStrToClauseType()
// recieves: a string and ClauseType
// description: compare string with ClauseType using ClauseTypeToString(ClauseType)
// returns: true if both arguments are equal, false otherwise
bool compareClauseStrToClauseType(const string& str, ClauseType ct, const RuleBase* myRBase){
	string ctStr = ClauseTypeToString(ct, myRBase->clauseNames); // conver ct to string
	bool flag = false;
	
	if( ctStr == str )
		flag = true;
	
	return flag;
}

// toLower()
// note: uses <cctype> library
// recieves: string
// description: converts str to all lowercase
// returns: nothing
string toLower(string & str) {
	string lowerStr = str;
    for ( char& c : lowerStr ){
		c = tolower(c);
	}
	
	return lowerStr;
}

// isClauseInUserList()
// recieves: const ClauseType clause,
// 			 const vector<string> & rawClauseVect
// runtime: O( n ), where n is total # of user clauses
// description:
//		initialize flag to false
//		iterate through each element in rawClauseVect
//		    compare to return val of ClauseTypeToString(clause) (spell checking???)
//			   set flag to true if equal
// returns:
//		true flag if clause exists in users rawClauseVect, false otherwise
bool isClauseInUserList( const ClauseType& clause, 
							const vector<string> & rawClauseVect,
							const RuleBase* myRBasePtr){
	bool flag = false;
	
	string strL = ClauseTypeToString(clause, myRBasePtr->clauseNames);
	strL = toLower( strL );
	string strR;
	for( int i = 0; i < rawClauseVect.size(); i++ ){
		// -implement spellchecking here
		strR = rawClauseVect[i]; 
		strR = toLower(strR);
		if( strL == strR ){
			flag = true;
			 			// break out of this for loop
		}
	}
	
	return flag;
}



// filter rawClauseVect into a valid list of clauses(clauses recognized in ClauseType)
// recieves: a referenced vector of string clauses 
// for each Rule's "clauses" in ruleList:
//     for each Rule (i to n)
//	       for each ClauseType in Rule's clauses vector (j to m)
//				    if clause[j] is found in userClauseList,
//					    then add clause[j] to validClauseVect	    
//
//    Run-time: O( n * m * z ), where n is the total # of Rules,
//								m is the total # clause vectors (Per Rule),
//								z is the # of elements (in user's clause list)
//
// return: vector of valid/recognized ClauseTypes
vector<ClauseType>* filterRawClauseVect(const vector<string>& rClauseVect, const RuleBase* myRBasePtr) {
    vector<ClauseType>* validClauseVectPtr = new vector<ClauseType>();
    
    // Iterate through each Rule in myRuleBase
    for (const auto& rule : *(myRBasePtr->ruleList)) {
        // Iterate through each ClauseType in the Rule's clauses vector
        for (const auto& clause : rule.clauses) {
            // Check if clause exists in within user-provided list
			// implement spell checking here
            if ( isClauseInUserList( clause, rClauseVect, myRBasePtr ) ) {
				//cout << ClauseTypeToString(clause, myRBasePtr->clauseNames) << " EXISTS IN RULEBASE!" << endl;
                // if clause is not already in validClauseVect, then push to it
				if( !elementExists(*validClauseVectPtr, clause) )
				    validClauseVectPtr->push_back(clause);
				
            } //else
				//cout << ClauseTypeToString(clause, myRBasePtr->clauseNames) << " DOES NOT EXIST IN RULEBASE!" << endl;
        }
    }
    
    return validClauseVectPtr;
}


// convertVariableListToVectorClauses()
// recieves: a string, str, representing the CSV list of the user's clauses
// pre-condition:
// description: parse through each comma seperated value to create rawClauseVect
//		compare ClauseType within ruleList -each clause from str
// post-condition: a dynamically allocated vector of ClauseType has been created.
// run-time: O(n * m) where n is total # of Rules and m is # of (valid) user clauses
vector<ClauseType>* convertVariableListToValidClauseVector(const string &str, const RuleBase* myRBasePtr){
	// parse CSV str into a vector of strings
	vector<string>* rawClauseVect = new vector<string>();
	istringstream ss(str);
	string token;
	cout << "Adding {" << token << "} to rawClauseVect ..." << endl;
	rawClauseVect->push_back(token);
	while ( getline(ss, token, ',') ){
		cout << "Adding {" << token << "} to rawClauseVect ..." << endl;
		rawClauseVect->push_back(token);
	}
	cout << endl << endl;
	
	
	// Note: filterRawClauseVect() dynamically allocates and returns memory.
	vector<ClauseType>* usrValidClauseVect = filterRawClauseVect(*rawClauseVect, myRBasePtr);
	
	delete rawClauseVect;
	return usrValidClauseVect;
}

// generateSubsets()
// recieves: userValidClauseList by reference
// description: uses a bitmask iterative approach where each subset is generated
//			using a binary expression (2^n subsets), iterating through m elements
//			per subset.
// runtime: O( 2^n * m ), where n is # of subsets, m elements per subset
// returns: pointer to dynamically allocated vector of vector subsets
vector<vector<ClauseType>>* generateSubsets(const vector<ClauseType>& userValidClauseList, const RuleBase* myRBase) {
    int n = userValidClauseList.size();
    int totalSubsets = 1 << n;  // 2^n subsets

    // Dynamically allocate a vector of vector subsets
    auto* subsets = new vector<vector<ClauseType>>;

    for (int mask = 0; mask < totalSubsets; ++mask) {
        vector<ClauseType> subset;
        string subsetStr = "{ ";  // String representation of the subset for printing

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // Check if the i-th bit is set
                subset.push_back(userValidClauseList[i]);
                subsetStr += ClauseTypeToString(userValidClauseList[i], myRBase->clauseNames) + ", ";
            }
        }

        subsetStr += "}";
        cout << subsetStr << endl;  // Print the complete subset

        subsets->push_back(subset);
    }

    return subsets;  // Return pointer to dynamically allocated memory
}



/*Process::Process(Goal){
	this->Goal* myGoal = new Goal();
	
	// create matchedClauses array
	
	do {
		
		
	} while( !myGoal->getIfReached() );
	
}

~Process(){
	
}*/


