#ifndef BRAINCANCERTREE_H
#define BRAINCANCERTREE_H

#include "../decisionTree.h"

class BrainCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable?");

        root->yes = new DecisionNode("Is the tumor a high-grade glioma (e.g., Glioblastoma)?");
        root->yes->yes = new DecisionNode("Maximal Safe Resection + Temozolomide Chemotherapy + Radiation + Tumor-Treating Fields (TTF)");
        root->yes->no  = new DecisionNode("Surgical Resection + Observation or Adjuvant Radiation");

        root->no = new DecisionNode("Is stereotactic radiosurgery (SRS) feasible?");
        root->no->yes = new DecisionNode("Stereotactic Radiosurgery (Gamma Knife or CyberKnife)");
        root->no->no  = new DecisionNode("Whole Brain Radiation Therapy + Chemotherapy");
    }
};

#endif
