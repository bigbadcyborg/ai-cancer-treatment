#include <iostream>
#include "ruleBase.h"

using namespace std;

enum ClauType {TIRED,ANXIOUS,COLD,BORED,COUGH};
enum ConType {FLU};


int main() {
	RuleBase* myRuleBase = new RuleBase(); 
	
	Rule* myRule = new Rule(); // rule to test against flu
	myRule->clauses.push_back(CHRONIC_COUGH);
	myRule->clauses.push_back(BLOOD_IN_SPUTUM);
	
	Rule* otherRule = new Rule(); // rule with flu formula
	otherRule->clauses.push_back(CHRONIC_COUGH);
	otherRule->clauses.push_back(BLOOD_IN_SPUTUM);
	
	// test overloaded == operator (order of clauses matter)
	bool diagnosis = false;
	diagnosis = ( *myRule == *otherRule );
	if( diagnosis ){
		cout << "Rule/Diagnosis Found!" << endl;
	} else {
		cout << "myRule != otherRule" << endl;
	}
	
	// test RuleBase::ClauseTypeToString
	cout << endl << myRuleBase->ClauseTypeToString(CHRONIC_COUGH) << endl;
	
	// test RuleBase::ConclusionTypeToString
	
	cout << myRuleBase->ConclusionTypeToString(PROSTATE_CANCER) << endl;
	// test RuleBase::ConclusionTypeToResponse
	
	cout << myRuleBase->ConclusionTypeToResponse(PROSTATE_CANCER) << endl;
	
	// test Rule::getConclusion(MyRuleBase)
	myRule->clauses.clear(); //empty vector
	myRule->clauses.push_back(BLOOD_IN_STOOL);
	myRule->clauses.push_back(UNEXPLAINED_WEIGHT_LOSS);
	myRule->clauses.push_back(ABDOMINAL_PAIN);
	try {
		myRule->getConclusion(*(myRuleBase->ruleList)); //check a rule with RuleBase
	} catch ( ConclusionType& e){
		cout << "DIAGNOSIS: " << myRuleBase->ConclusionTypeToString(e) << endl;
		cout << "RESPONSE: " << myRuleBase->ConclusionTypeToResponse(e) << endl;
	}
	
	
	delete otherRule;
	delete myRule;
	return 0;
}