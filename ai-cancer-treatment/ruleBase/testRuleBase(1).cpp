#include <iostream>
#include "clauseList/clauseList.h"
#include "conclusionList/conclusionList.h"
#include "knowledgeBase/knowledgeBase.h"
#include "ruleBase/ruleBase.h"
#include "variableList/variableList.h"

using namespace std;

int main(){
	// Test ClauseList
	ClauseList* myClauseList = new ClauseList();
	myClauseList->print();
	
	delete myClauseList;
	
	
	// Test ConclusionList
	ConclusionList* myConclusionList = new ConclusionList();
	myConclusionList->print();
	
	delete myConclusionList;
		
	
	// Test KnowledgeBase
	KnowledgeBase* myKnowledgeBase = new KnowledgeBase();
	myKnowledgeBase->print();
	
	delete myKnowledgeBase;
		

	// Test RuleBase
	RuleBase* myRuleBase = new RuleBase();
	myRuleBase->print();
	
	delete myRuleBase;
		
	
	// Test VariableList
	VariableList* myVariableList = new VariableList();
	myVariableList->print();
	
	delete myVariableList;
	
	return 0;
}