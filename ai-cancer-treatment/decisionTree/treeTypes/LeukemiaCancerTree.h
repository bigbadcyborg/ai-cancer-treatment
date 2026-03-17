#ifndef LEUKEMIACANCERTREE_H
#define LEUKEMIACANCERTREE_H

#include "../decisionTree.h"

class LeukemiaCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the leukemia acute (vs. chronic)?");

        root->yes = new DecisionNode("Is the patient eligible for intensive induction chemotherapy?");
        root->yes->yes = new DecisionNode("Induction Chemotherapy + Consolidation + Stem Cell Transplant (if high-risk)");
        root->yes->no  = new DecisionNode("Low-Intensity Chemotherapy or Targeted Therapy (e.g., Venetoclax)");

        root->no = new DecisionNode("Is the disease Chronic Myeloid Leukemia (CML)?");
        root->no->yes = new DecisionNode("Tyrosine Kinase Inhibitor (Imatinib, Dasatinib, or Nilotinib)");
        root->no->no  = new DecisionNode("Targeted Therapy + Watch-and-Wait or Chemoimmunotherapy");
    }
};

#endif
