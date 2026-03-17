#ifndef PANCREATICCANCERTREE_H
#define PANCREATICCANCERTREE_H

#include "../decisionTree.h"

class PancreaticCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable?");

        root->yes = new DecisionNode("Is the patient fit for major pancreatic surgery?");
        root->yes->yes = new DecisionNode("Whipple Procedure (Pancreaticoduodenectomy) + Adjuvant FOLFIRINOX Chemotherapy");
        root->yes->no  = new DecisionNode("Gemcitabine + nab-Paclitaxel Chemotherapy");

        root->no = new DecisionNode("Is the tumor locally advanced (no distant metastasis)?");
        root->no->yes = new DecisionNode("Induction Chemotherapy + Chemoradiation");
        root->no->no  = new DecisionNode("Palliative Chemotherapy (FOLFIRINOX or Gemcitabine-based)");
    }
};

#endif
