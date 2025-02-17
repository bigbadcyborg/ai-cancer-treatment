#ifndef BREASTCANCERTREE_H
#define BREASTCANCERTREE_H

#include "../decisionTree.h"

class BreastCancerTree : public DecisionTree {
    void buildTree() override {
        this->root = new DecisionNode("Is the disease early-stage and localized?");
        
        this->root->yes = new DecisionNode("Can breast-conserving surgery be performed?");
        this->root->yes->yes = new DecisionNode("Lumpectomy + Radiation Therapy ± Chemotherapy");
        this->root->yes->no = new DecisionNode("Mastectomy + Adjuvant Chemotherapy ± Radiation Therapy");

        this->root->no = new DecisionNode("Systemic Chemotherapy ± Targeted/Immunotherapy");
    }
};


#endif