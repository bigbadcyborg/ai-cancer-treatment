#ifndef DECISIONTREE_H
#define DECISIONTREE_H

#include <iostream>
#include <string>
//#include "../variableList/conclusionTypes.h"
//#include "../variableList/clauseTypes.h"

using namespace std;

class DecisionNode{
public:
	string question;
	DecisionNode* yes;
	DecisionNode* no;
	
	DecisionNode(string q) : question(q), yes(nullptr), no(nullptr) {}
	~DecisionNode() { delete yes; delete no; }
};

class DecisionTree {
protected:
	DecisionNode* root;
	
	
public:
	DecisionTree() : root(nullptr) {} // In-line Constructor
	virtual ~DecisionTree() { delete root; } // In-line Destructor
	
	virtual void buildTree() =0;    // Each subclass will implement this
	void traverseTree();		    // Process yes/no inputs
};



DecisionTree* createDecisionTree(ConclusionType);

#endif