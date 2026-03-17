#ifndef LYMPHOMACANCERTREE_H
#define LYMPHOMACANCERTREE_H

#include "../decisionTree.h"

class LymphomaCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is this Hodgkin Lymphoma (vs. Non-Hodgkin)?");

        root->yes = new DecisionNode("Is the disease early-stage (Stage I or II)?");
        root->yes->yes = new DecisionNode("ABVD Chemotherapy + Involved-Site Radiation Therapy");
        root->yes->no  = new DecisionNode("Escalated BEACOPP or ABVD Chemotherapy");

        root->no = new DecisionNode("Is the lymphoma aggressive (high-grade, e.g., DLBCL)?");
        root->no->yes = new DecisionNode("R-CHOP Immunochemotherapy");
        root->no->no  = new DecisionNode("Rituximab Monotherapy or Watch-and-Wait");
    }
};

#endif
