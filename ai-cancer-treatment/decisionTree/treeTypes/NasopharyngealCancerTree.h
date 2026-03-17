#ifndef NASOPHARYNGEALCANCERTREE_H
#define NASOPHARYNGEALCANCERTREE_H

#include "../decisionTree.h"

class NasopharyngealCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer early-stage (Stage I-II)?");

        root->yes = new DecisionNode("Is the tumor confined to the nasopharynx (Stage I)?");
        root->yes->yes = new DecisionNode("Definitive Intensity-Modulated Radiation Therapy (IMRT)");
        root->yes->no  = new DecisionNode("Concurrent Chemoradiation (Cisplatin + IMRT)");

        root->no = new DecisionNode("Is the disease locally advanced (Stage III-IVA)?");
        root->no->yes = new DecisionNode("Induction Chemotherapy (TPF) + Concurrent Chemoradiation");
        root->no->no  = new DecisionNode("Palliative Chemotherapy + Immunotherapy (Anti-PD-1)");
    }
};

#endif
