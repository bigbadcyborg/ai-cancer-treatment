#ifndef STOMACHCANCERTREE_H
#define STOMACHCANCERTREE_H

#include "../decisionTree.h"

class StomachCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable?");

        root->yes = new DecisionNode("Is perioperative chemotherapy appropriate?");
        root->yes->yes = new DecisionNode("Perioperative FLOT Chemotherapy + Gastrectomy");
        root->yes->no  = new DecisionNode("Total or Subtotal Gastrectomy + D2 Lymphadenectomy");

        root->no = new DecisionNode("Does the tumor overexpress HER2?");
        root->no->yes = new DecisionNode("Chemotherapy (Cisplatin + Fluorouracil) + Targeted Therapy (Trastuzumab)");
        root->no->no  = new DecisionNode("Chemotherapy + Immunotherapy (Nivolumab)");
    }
};

#endif
