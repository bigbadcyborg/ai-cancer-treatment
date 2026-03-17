#ifndef MELANOMACANCERTREE_H
#define MELANOMACANCERTREE_H

#include "../decisionTree.h"

class MelanomaCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the melanoma localized (no lymph node or distant spread)?");

        root->yes = new DecisionNode("Is the tumor thin (Breslow depth < 1 mm)?");
        root->yes->yes = new DecisionNode("Wide Local Excision");
        root->yes->no  = new DecisionNode("Wide Local Excision + Sentinel Lymph Node Biopsy");

        root->no = new DecisionNode("Does the tumor harbor a BRAF V600 mutation?");
        root->no->yes = new DecisionNode("BRAF/MEK Targeted Therapy (Dabrafenib + Trametinib)");
        root->no->no  = new DecisionNode("Anti-PD-1 Immunotherapy (Pembrolizumab or Nivolumab)");
    }
};

#endif
