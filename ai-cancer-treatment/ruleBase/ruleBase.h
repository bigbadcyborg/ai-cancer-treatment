#ifndef RULEBASE_H
#define RULEBASE_H

#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum ClauseType {PERSISTENT_COUGH, WEIGHT_LOSS, CHEST_PAIN, LUMP_IN_BREAST, NIPPLE_DISCHARGE, SKIN_DIMPLING, CHRONIC_SORE_THROAT, DIFFICULT_SWALLOWING, HOARSENESS, ACID_REFLUX, BLOOD_IN_STOOL, UNEXPLAINED_WEIGHT_LOSS, FREQUENT_URINATION, BLOOD_IN_URINE, PELVIC_PAIN, NIGHT_SWEATS, PAINLESS_SWOLLEN_LYMPH_NODES, PERSISTENT_FATIGUE, FREQUENT_INFECTIONS, UNUSUAL_VAGINAL_BLEEDING, PAINFUL_INTERCOURSE, MOLE_CHANGES, IRREGULAR_MOLE_BORDERS, MOLE_BLEEDING, UNEXPLAINED_BONE_PAIN, FREQUENT_FRACTURES, SWELLING_NEAR_BONE, JAUNDICE, ABDOMINAL_PAIN, TROUBLE_SPEAKING, MUSCLE_WEAKNESS, PERSISTENT_HEADACHE, BLOOD_IN_SPUTUM, CHRONIC_COUGH, SHORTNESS_OF_BREATH, UNEXPLAINED_FEVER, BRUISING_EASY, FACIAL_SWELLING, DEEP_VOICE_CHANGE, DIFFICULT_URINATING, LOWER_BACK_PAIN, WEAK_URINE_FLOW, PERSISTENT_ITCHING, YELLOW_SKIN, SEVERE_NOSEBLEEDS, FACIAL_PAIN, BLOCKED_NOSE_NOT_RESOLVING, PERSISTENT_HICCUPS, BACK_PAIN, LOSS_OF_BLADDER_CONTROL, UNEXPLAINED_LEG_WEAKNESS, BLOOD_IN_SEMEN, PAINFUL_EJACULATION, PERSISTENT_BLOATING, FEELING_FULL_QUICKLY, PERSISTENT_SORE_THROAT, DIFFICULTY_CHEWING, EAR_PAIN, VOICE_HOARSENESS, PERSISTENT_THROAT_LUMP_SENSATION, FREQUENT_HEARTBURN, UNEXPLAINED_HAIR_LOSS, ENLARGED_THYROID, HIGH_FEVER, ENLARGED_PROSTATE, DIFFICULTY_WALKING, LOSS_OF_BALANCE, CHRONIC_SINUS_INFECTIONS, NASAL_BLOCKAGE, SWOLLEN_GUMS, FREQUENT_BLEEDING_GUMS, LOOSE_TEETH};
enum ConclusionType {LUNG_CANCER, BREAST_CANCER, ESOPHAGEAL_CANCER, COLORECTAL_CANCER, BLADDER_CANCER, LYMPHOMA, CERVICAL_CANCER, MELANOMA, BONE_CANCER, PANCREATIC_CANCER, BRAIN_CANCER, LEUKEMIA, THYROID_CANCER, PROSTATE_CANCER, LIVER_CANCER, NASOPHARYNGEAL_CANCER, STOMACH_CANCER, SPINAL_CANCER, OVARIAN_CANCER, ORAL_CANCER, LARYNGEAL_CANCER, SINONASAL_CANCER};

// Prototype(s)
string ClauseTypeToString(const ClauseType & CT,
									const unordered_map<ClauseType, string>&);


// A Rule consists of a set of clauses and the associated conclusion
struct Rule {
    vector<ClauseType> clauses;
    ConclusionType conclusion;
	
	// throws ConclusionType object if Rule is satisfied 
	// within the RuleBase ruleList, false otherwise.
	void getConclusion(vector<Rule>& rList); //throws ConclusionType
	
    // Overload the == operator to compare two Rule objects' ClauseType vector (pairwise)
    bool operator==(const Rule& other) const;
	
};


class RuleBase{
public:
	//*A list of rules, each containing clauses and the corresponding conclusion/treatments
    vector<Rule>* ruleList;
	// Type-to-String Mappings using hashing for key/value functionality
    unordered_map<ClauseType, string>* clauseNames;
    unordered_map<ConclusionType, string>* conclusionNames;
	unordered_map<ConclusionType, string>* responseTypes;
	
	
	// Constructor
    RuleBase();
	~RuleBase();
	
	ClauseType getClauseName(string);
	//ConclusionType getConclusionName(string);
	//ConclusionType getResponseString(string);
	string ClauseTypeToString(const ClauseType&);
	string ConclusionTypeToString(const ConclusionType&);
	string ConclusionTypeToResponse(const ConclusionType&);
    void print() const;
};

#endif
