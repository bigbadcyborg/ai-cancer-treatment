#ifndef ORALCANCERTREE_H
#define ORALCANCERTREE_H

#include "../decisionTree.h"

class OralCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer early-stage (Stage I-II)?");

        root->yes = new DecisionNode("Is surgery the preferred primary treatment?");
        root->yes->yes = new DecisionNode("Wide Local Excision +/- Elective Neck Dissection");
        root->yes->no  = new DecisionNode("Definitive Radiation Therapy");

        root->no = new DecisionNode("Is combined modality treatment feasible?");
        root->no->yes = new DecisionNode("Surgery + Adjuvant Chemoradiation (Cisplatin-based)");
        root->no->no  = new DecisionNode("Palliative Chemotherapy + Immunotherapy (Pembrolizumab)");
    }
};

#endif
