#ifndef BONECANCERTREE_H
#define BONECANCERTREE_H

#include "../decisionTree.h"

class BoneCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is this a primary bone tumor (e.g., osteosarcoma, Ewing sarcoma)?");

        root->yes = new DecisionNode("Is limb-salvage surgery possible?");
        root->yes->yes = new DecisionNode("Neoadjuvant Chemotherapy + Limb-Salvage Surgery + Adjuvant Chemotherapy");
        root->yes->no  = new DecisionNode("Neoadjuvant Chemotherapy + Amputation + Adjuvant Chemotherapy");

        root->no = new DecisionNode("Is the patient able to undergo surgery?");
        root->no->yes = new DecisionNode("Surgical Resection + Radiation Therapy");
        root->no->no  = new DecisionNode("Palliative Radiation Therapy + Chemotherapy");
    }
};

#endif
