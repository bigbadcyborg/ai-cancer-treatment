#ifndef LUNGCANCERTREE_H
#define LUNGCANCERTREE_H

#include "../decisionTree.h"

class LungCancerTree : public DecisionTree {
public:
    void buildTree() override {  // Ensure proper override
        root = new DecisionNode("Is the cancer localized?");
        root->yes = new DecisionNode("Is the tumor resectable?");
        root->yes->yes = new DecisionNode("Surgery + Adjuvant Chemotherapy ± Radiation Therapy");
        root->yes->no = new DecisionNode("Definitive Chemoradiation");
		
        root->no = new DecisionNode("Does the tumor have actionable mutations?");
        root->no->yes = new DecisionNode("Targeted Therapy");
        root->no->no = new DecisionNode("Immunotherapy ± Chemotherapy");
    }
};

#endif
