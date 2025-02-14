#include <iostream>
#include "ruleBase.h"

// Constructor
// post-condition: clauses and diagnoses enum lists are created dynamically,
//
//
//
RuleBase::RuleBase() {	
	
	// Dynamically allocated rule list
	this->ruleList = new vector<Rule> {
		{ {PERSISTENT_COUGH, WEIGHT_LOSS, CHEST_PAIN}, LUNG_CANCER },
		{ {LUMP_IN_BREAST, NIPPLE_DISCHARGE, SKIN_DIMPLING}, BREAST_CANCER },
		{ {DIFFICULT_SWALLOWING, HOARSENESS, ACID_REFLUX}, ESOPHAGEAL_CANCER },
		{ {BLOOD_IN_STOOL, UNEXPLAINED_WEIGHT_LOSS, ABDOMINAL_PAIN}, COLORECTAL_CANCER },
		{ {FREQUENT_URINATION, BLOOD_IN_URINE, PELVIC_PAIN}, BLADDER_CANCER },
		{ {NIGHT_SWEATS, PAINLESS_SWOLLEN_LYMPH_NODES, PERSISTENT_FATIGUE}, LYMPHOMA },
		{ {UNUSUAL_VAGINAL_BLEEDING, PELVIC_PAIN, PAINFUL_INTERCOURSE}, CERVICAL_CANCER },
		{ {MOLE_CHANGES, IRREGULAR_MOLE_BORDERS, MOLE_BLEEDING}, MELANOMA },
		{ {UNEXPLAINED_BONE_PAIN, FREQUENT_FRACTURES, SWELLING_NEAR_BONE}, BONE_CANCER },
		{ {JAUNDICE, ABDOMINAL_PAIN, UNEXPLAINED_WEIGHT_LOSS}, PANCREATIC_CANCER },
		{ {TROUBLE_SPEAKING, MUSCLE_WEAKNESS, PERSISTENT_HEADACHE}, BRAIN_CANCER },
		{ {BLOOD_IN_SPUTUM, CHRONIC_COUGH, SHORTNESS_OF_BREATH}, LUNG_CANCER },
		{ {UNEXPLAINED_FEVER, FREQUENT_INFECTIONS, BRUISING_EASY}, LEUKEMIA },
		{ {FACIAL_SWELLING, DEEP_VOICE_CHANGE, CHRONIC_COUGH}, THYROID_CANCER },
		{ {DIFFICULT_URINATING, LOWER_BACK_PAIN, WEAK_URINE_FLOW}, PROSTATE_CANCER },
		{ {PERSISTENT_ITCHING, YELLOW_SKIN, ABDOMINAL_PAIN}, LIVER_CANCER },
		{ {SEVERE_NOSEBLEEDS, FACIAL_PAIN, BLOCKED_NOSE_NOT_RESOLVING}, NASOPHARYNGEAL_CANCER },
		{ {PERSISTENT_HICCUPS, UNEXPLAINED_WEIGHT_LOSS, DIFFICULT_SWALLOWING}, STOMACH_CANCER },
		{ {BACK_PAIN, LOSS_OF_BLADDER_CONTROL, UNEXPLAINED_LEG_WEAKNESS}, SPINAL_CANCER },
		{ {BLOOD_IN_SEMEN, PAINFUL_EJACULATION, FREQUENT_URINATION}, PROSTATE_CANCER },
		{ {PERSISTENT_BLOATING, PELVIC_PAIN, FEELING_FULL_QUICKLY}, OVARIAN_CANCER },
		{ {PERSISTENT_SORE_THROAT, DIFFICULTY_CHEWING, EAR_PAIN}, ORAL_CANCER },
		{ {VOICE_HOARSENESS, PERSISTENT_THROAT_LUMP_SENSATION, CHRONIC_SORE_THROAT}, LARYNGEAL_CANCER },
		{ {FREQUENT_HEARTBURN, DIFFICULT_SWALLOWING, CHEST_PAIN}, ESOPHAGEAL_CANCER },
		{ {UNEXPLAINED_HAIR_LOSS, ENLARGED_THYROID, DIFFICULT_SWALLOWING}, THYROID_CANCER },
		{ {NIGHT_SWEATS, HIGH_FEVER, WEIGHT_LOSS}, LYMPHOMA },
		{ {ENLARGED_PROSTATE, DIFFICULT_URINATING, BLOOD_IN_URINE}, PROSTATE_CANCER },
		{ {DIFFICULTY_WALKING, LOSS_OF_BALANCE, PERSISTENT_HEADACHE}, BRAIN_CANCER },
		{ {CHRONIC_SINUS_INFECTIONS, NASAL_BLOCKAGE, FACIAL_SWELLING}, SINONASAL_CANCER },
		{ {SWOLLEN_GUMS, FREQUENT_BLEEDING_GUMS, LOOSE_TEETH}, LEUKEMIA }
	};
	
	
    // Dynamically allocate unordered_map for clause names (key/value hash)
    this->clauseNames = new unordered_map<ClauseType, string>();
    // Initialize the map with values
    (*clauseNames)[PERSISTENT_COUGH] = "Persistent Cough";
	(*clauseNames)[UNEXPLAINED_FEVER] = "Unexplained Fever";
	(*clauseNames)[FREQUENT_INFECTIONS] = "Frequent Infections";
	(*clauseNames)[BRUISING_EASY] = "Bruising Easy";
    (*clauseNames)[WEIGHT_LOSS] = "Weight Loss";
    (*clauseNames)[CHEST_PAIN] = "Chest Pain";
    (*clauseNames)[LUMP_IN_BREAST] = "Lump in Breast";
    (*clauseNames)[NIPPLE_DISCHARGE] = "Nipple Discharge";
    (*clauseNames)[SKIN_DIMPLING] = "Skin Dimpling";
    (*clauseNames)[DIFFICULT_SWALLOWING] = "Difficult Swallowing";
    (*clauseNames)[HOARSENESS] = "Hoarseness";
    (*clauseNames)[ACID_REFLUX] = "Acid Reflux";
    (*clauseNames)[BLOOD_IN_STOOL] = "Blood in Stool";
    (*clauseNames)[UNEXPLAINED_WEIGHT_LOSS] = "Unexplained Weight Loss";
    (*clauseNames)[ABDOMINAL_PAIN] = "Abdominal Pain";
    (*clauseNames)[FREQUENT_URINATION] = "Frequent Urination";
    (*clauseNames)[BLOOD_IN_URINE] = "Blood in Urine";
    (*clauseNames)[PELVIC_PAIN] = "Pelvic Pain";
    (*clauseNames)[NIGHT_SWEATS] = "Night Sweats";
    (*clauseNames)[PAINLESS_SWOLLEN_LYMPH_NODES] = "Painless Swollen Lymph Nodes";
    (*clauseNames)[PERSISTENT_FATIGUE] = "Persistent Fatigue";
    (*clauseNames)[UNUSUAL_VAGINAL_BLEEDING] = "Unusual Vaginal Bleeding";
    (*clauseNames)[PAINFUL_INTERCOURSE] = "Painful Intercourse";
    (*clauseNames)[MOLE_CHANGES] = "Mole Changes";
    (*clauseNames)[IRREGULAR_MOLE_BORDERS] = "Irregular Mole Borders";
    (*clauseNames)[MOLE_BLEEDING] = "Mole Bleeding";
    (*clauseNames)[UNEXPLAINED_BONE_PAIN] = "Unexplained Bone Pain";
    (*clauseNames)[FREQUENT_FRACTURES] = "Frequent Fractures";
    (*clauseNames)[SWELLING_NEAR_BONE] = "Swelling Near Bone";
    (*clauseNames)[JAUNDICE] = "Jaundice";
    (*clauseNames)[TROUBLE_SPEAKING] = "Trouble Speaking";
    (*clauseNames)[MUSCLE_WEAKNESS] = "Muscle Weakness";
    (*clauseNames)[PERSISTENT_HEADACHE] = "Persistent Headache";
    (*clauseNames)[BLOOD_IN_SPUTUM] = "Blood in Sputum";
    (*clauseNames)[CHRONIC_COUGH] = "Chronic Cough";
    (*clauseNames)[SHORTNESS_OF_BREATH] = "Shortness of Breath";
    (*clauseNames)[FACIAL_SWELLING] = "Facial Swelling";
    (*clauseNames)[DEEP_VOICE_CHANGE] = "Deep Voice Change";
    (*clauseNames)[DIFFICULT_URINATING] = "Difficult Urinating";
    (*clauseNames)[LOWER_BACK_PAIN] = "Lower Back Pain";
    (*clauseNames)[WEAK_URINE_FLOW] = "Weak Urine Flow";
    (*clauseNames)[PERSISTENT_ITCHING] = "Persistent Itching";
    (*clauseNames)[YELLOW_SKIN] = "Yellow Skin";
    (*clauseNames)[SEVERE_NOSEBLEEDS] = "Severe Nosebleeds";
    (*clauseNames)[FACIAL_PAIN] = "Facial Pain";
    (*clauseNames)[BLOCKED_NOSE_NOT_RESOLVING] = "Blocked Nose Not Resolving";
    (*clauseNames)[PERSISTENT_HICCUPS] = "Persistent Hiccups";
    (*clauseNames)[BACK_PAIN] = "Back Pain";
    (*clauseNames)[LOSS_OF_BLADDER_CONTROL] = "Loss of Bladder Control";
    (*clauseNames)[UNEXPLAINED_LEG_WEAKNESS] = "Unexplained Leg Weakness";
    (*clauseNames)[BLOOD_IN_SEMEN] = "Blood in Semen";
    (*clauseNames)[PAINFUL_EJACULATION] = "Painful Ejaculation";
    (*clauseNames)[PERSISTENT_BLOATING] = "Persistent Bloating";
    (*clauseNames)[FEELING_FULL_QUICKLY] = "Feeling Full Quickly";
    (*clauseNames)[PERSISTENT_SORE_THROAT] = "Persistent Sore Throat";
    (*clauseNames)[DIFFICULTY_CHEWING] = "Difficulty Chewing";
    (*clauseNames)[EAR_PAIN] = "Ear Pain";
    (*clauseNames)[VOICE_HOARSENESS] = "Voice Hoarseness";
    (*clauseNames)[PERSISTENT_THROAT_LUMP_SENSATION] = "Persistent Throat Lump Sensation";
    (*clauseNames)[CHRONIC_SORE_THROAT] = "Chronic Sore Throat";
    (*clauseNames)[FREQUENT_HEARTBURN] = "Frequent Heartburn";
    (*clauseNames)[UNEXPLAINED_HAIR_LOSS] = "Unexplained Hair Loss";
    (*clauseNames)[ENLARGED_THYROID] = "Enlarged Thyroid";
    (*clauseNames)[HIGH_FEVER] = "High Fever";
    (*clauseNames)[ENLARGED_PROSTATE] = "Enlarged Prostate";
    (*clauseNames)[DIFFICULTY_WALKING] = "Difficulty Walking";
    (*clauseNames)[LOSS_OF_BALANCE] = "Loss of Balance";
    (*clauseNames)[CHRONIC_SINUS_INFECTIONS] = "Chronic Sinus Infections";
    (*clauseNames)[NASAL_BLOCKAGE] = "Nasal Blockage";
    (*clauseNames)[SWOLLEN_GUMS] = "Swollen Gums";
    (*clauseNames)[FREQUENT_BLEEDING_GUMS] = "Frequent Bleeding Gums";
    (*clauseNames)[LOOSE_TEETH] = "Loose Teeth";
    // Access a value to demonstrate usage
    //cout << (*clauseNames)[PERSISTENT_COUGH] << endl;
	
	
    // Dynamically allocate unordered_map
    this->conclusionNames = new unordered_map<ConclusionType, string>();
    // Initialize the map with values
    (*conclusionNames)[LUNG_CANCER] = "Lung Cancer";
    (*conclusionNames)[BREAST_CANCER] = "Breast Cancer";
    (*conclusionNames)[ESOPHAGEAL_CANCER] = "Esophageal Cancer";
    (*conclusionNames)[COLORECTAL_CANCER] = "Colorectal Cancer";
    (*conclusionNames)[BLADDER_CANCER] = "Bladder Cancer";
    (*conclusionNames)[LYMPHOMA] = "Lymphoma";
    (*conclusionNames)[CERVICAL_CANCER] = "Cervical Cancer";
    (*conclusionNames)[MELANOMA] = "Melanoma";
    (*conclusionNames)[BONE_CANCER] = "Bone Cancer";
    (*conclusionNames)[PANCREATIC_CANCER] = "Pancreatic Cancer";
    (*conclusionNames)[BRAIN_CANCER] = "Brain Cancer";
    (*conclusionNames)[LEUKEMIA] = "Leukemia";
    (*conclusionNames)[THYROID_CANCER] = "Thyroid Cancer";
    (*conclusionNames)[PROSTATE_CANCER] = "Prostate Cancer";
    (*conclusionNames)[LIVER_CANCER] = "Liver Cancer";
    (*conclusionNames)[NASOPHARYNGEAL_CANCER] = "Nasopharyngeal Cancer";
    (*conclusionNames)[STOMACH_CANCER] = "Stomach Cancer";
    (*conclusionNames)[SPINAL_CANCER] = "Spinal Cancer";
    (*conclusionNames)[OVARIAN_CANCER] = "Ovarian Cancer";
    (*conclusionNames)[ORAL_CANCER] = "Oral Cancer";
    (*conclusionNames)[LARYNGEAL_CANCER] = "Laryngeal Cancer";
    (*conclusionNames)[SINONASAL_CANCER] = "Sinonasal Cancer";

    // Access a value to demonstrate usage
    //cout << (*conclusionNames)[LUNG_CANCER] << endl;
	
	
	// Dynamically allocate unordered_map for treatments
	this->responseTypes = new unordered_map<ConclusionType, string>();
	// Initialize the map with values
	(*responseTypes)[LUNG_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy, immunotherapy.";
	(*responseTypes)[BREAST_CANCER] = "Surgery (lumpectomy, mastectomy), chemotherapy, radiation therapy, hormone therapy, targeted therapy.";
	(*responseTypes)[ESOPHAGEAL_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy, immunotherapy.";
	(*responseTypes)[COLORECTAL_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy, immunotherapy.";
	(*responseTypes)[BLADDER_CANCER] = "Surgery (TURBT, cystectomy), chemotherapy, radiation therapy, immunotherapy, targeted therapy.";
	(*responseTypes)[LYMPHOMA] = "Chemotherapy, radiation therapy, immunotherapy, targeted therapy, stem cell transplant.";
	(*responseTypes)[CERVICAL_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, immunotherapy.";
	(*responseTypes)[MELANOMA] = "Surgery, immunotherapy, targeted therapy, chemotherapy, radiation therapy.";
	(*responseTypes)[BONE_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy.";
	(*responseTypes)[PANCREATIC_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy, immunotherapy.";
	(*responseTypes)[BRAIN_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, tumor-treating fields (TTF).";
	(*responseTypes)[LEUKEMIA] = "Chemotherapy, targeted therapy, immunotherapy, radiation therapy, stem cell transplant.";
	(*responseTypes)[THYROID_CANCER] = "Surgery, radioactive iodine therapy, hormone therapy, targeted therapy, chemotherapy.";
	(*responseTypes)[PROSTATE_CANCER] = "Surgery, radiation therapy, hormone therapy, chemotherapy, immunotherapy, targeted therapy.";
	(*responseTypes)[LIVER_CANCER] = "Surgery, liver transplant, targeted therapy, immunotherapy, radiation therapy, embolization therapy.";
	(*responseTypes)[NASOPHARYNGEAL_CANCER] = "Radiation therapy, chemotherapy, targeted therapy, immunotherapy.";
	(*responseTypes)[STOMACH_CANCER] = "Surgery, chemotherapy, radiation therapy, targeted therapy, immunotherapy.";
	(*responseTypes)[SPINAL_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, stereotactic radiosurgery.";
	(*responseTypes)[OVARIAN_CANCER] = "Surgery, chemotherapy, targeted therapy, hormone therapy, radiation therapy.";
	(*responseTypes)[ORAL_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, immunotherapy.";
	(*responseTypes)[LARYNGEAL_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, immunotherapy.";
	(*responseTypes)[SINONASAL_CANCER] = "Surgery, radiation therapy, chemotherapy, targeted therapy, immunotherapy.";

	
	
}

string RuleBase::ClauseTypeToString(const ClauseType & CT){
	string tmpStr;
	tmpStr = (*clauseNames)[CT];
	return tmpStr;
}

string ClauseTypeToString(const ClauseType & CT,
							const unordered_map<ClauseType, string>& cNames) {
	string tmpStr;
	tmpStr = cNames.at(CT);
	return tmpStr;
}

string RuleBase::ConclusionTypeToString(const ConclusionType & CT){
	string tmpStr;
	tmpStr = (*conclusionNames)[CT];
	return tmpStr;
}

string RuleBase::ConclusionTypeToResponse(const ConclusionType& CT){
	string tmpStr;
	tmpStr = (*responseTypes)[CT];
	return tmpStr;
}


RuleBase::~RuleBase(){
	delete conclusionNames;
	delete clauseNames;
	delete ruleList;
	delete responseTypes;
}

void RuleBase::print() const {
	cout << "Testing RuleBase ..." << endl;
	cout << "Rules:\n";
	
    for (const Rule& rule : *ruleList) {
        cout << "IF ";
		// loop through each symptom and print its correpsonding string
        for (size_t i = 0; i < rule.clauses.size(); ++i) {
            cout << (*clauseNames)[rule.clauses[i]];
            if (i < rule.clauses.size() - 1) {
                cout << ", ";
            }
        }
        cout << " THEN " << (*conclusionNames)[rule.conclusion] << endl; //print conclusion
		cout << " TREATMENTS:" << endl << (*responseTypes)[rule.conclusion];
    }
	
}


// Overload the == operator to compare two Rule objects' ClauseType vectors (pairwise)
bool Rule::operator==(const Rule& other) const {
	bool flag = false;

    // First, check if the sizes of the clause lists are the same
	cout << "Comparing Rules... " << endl;
    if (clauses.size() != other.clauses.size()) {
        return flag;
    }
	
    // Check if both clause lists are identical
    for (size_t i = 0; i < clauses.size(); ++i) {
		cout << "This Rule's Clauses:" << endl;
		cout << this->clauses[i] << endl;
		cout << "Other Rule's Clauses:" << endl;
		cout << other.clauses[i] << endl;
        if (clauses[i] != other.clauses[i]) {
            return flag;
        }
    }

	// both rules match clauses
	flag = true;
    return flag;
}

// Rule::getConclusion()
// Pre-condition: subset has not been tested vs. each rule
// Recieves: RuleBase's ruleList vector by reference
// Description: the calling Rule object pairwise compares its clause vector to the
//     RuleBase ruleList vector then throws an Exception if match is found
// Post-condition: if a rule is matched, then a ConclusionType is thrown
//				  -if a rule is not matched then nothing is returned.
void Rule::getConclusion(vector<Rule>& myRuleList) {
	// loop through each Rule within RuleBase's ruleList vector
	for( int i = 0; i < myRuleList.size(); i++ ){
		if( *this == myRuleList[i] ){
			cout << "getConclusion match found!" << endl;
			throw myRuleList[i].conclusion;
		}
	}
	
}