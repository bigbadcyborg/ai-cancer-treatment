#ifndef LARYNGEALCANCERTREE_H
#define LARYNGEALCANCERTREE_H

#include "../decisionTree.h"

class LaryngealCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer early-stage (Stage I-II)?");

        root->yes = new DecisionNode("Is voice (larynx) preservation preferred?");
        root->yes->yes = new DecisionNode("Definitive Radiation Therapy or Transoral Laser Microsurgery");
        root->yes->no  = new DecisionNode("Partial Laryngectomy");

        root->no = new DecisionNode("Is larynx preservation feasible?");
        root->no->yes = new DecisionNode("Concurrent Chemoradiation (Cisplatin + Radiation Therapy)");
        root->no->no  = new DecisionNode("Total Laryngectomy + Adjuvant Radiation Therapy +/- Chemotherapy");
    }
};

#endif
