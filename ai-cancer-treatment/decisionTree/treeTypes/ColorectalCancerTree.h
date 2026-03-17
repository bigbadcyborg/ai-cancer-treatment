#ifndef COLORECTALCANCERTREE_H
#define COLORECTALCANCERTREE_H

#include "../decisionTree.h"

class ColorectalCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer localized (no distant metastasis)?");

        root->yes = new DecisionNode("Is surgical resection possible?");
        root->yes->yes = new DecisionNode("Surgical Resection +/- Adjuvant Chemotherapy (FOLFOX/CAPOX)");
        root->yes->no  = new DecisionNode("Neoadjuvant Chemoradiation + Delayed Resection");

        root->no = new DecisionNode("Is the tumor MSI-High or mismatch repair deficient (dMMR)?");
        root->no->yes = new DecisionNode("Immunotherapy (Pembrolizumab)");
        root->no->no  = new DecisionNode("Chemotherapy + Targeted Therapy (Bevacizumab or Cetuximab)");
    }
};

#endif
