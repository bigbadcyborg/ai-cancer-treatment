#ifndef FORWARDCHAINING_H
#define FORWARDCHAINING_H

#include <iostream>
#include <vector>
#include "../ruleBase/ruleBase.h"

using namespace std;

class ForwardChaining {
public:
	Rule* diagnosisPtr;
	vector< vector<ClauseType> >* possibleConclusionsPtr;
	
	// Constructor / Destructor
	ForwardChaining();
	~ForwardChaining();
	
	DecisionTree* createDecisionTree();
	void getConclusionFromBackwardChaining();
};





#endif