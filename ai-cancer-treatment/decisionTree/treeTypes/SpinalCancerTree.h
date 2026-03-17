#ifndef SPINALCANCERTREE_H
#define SPINALCANCERTREE_H

#include "../decisionTree.h"

class SpinalCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is this a primary spinal tumor (not metastatic)?");

        root->yes = new DecisionNode("Is surgical resection feasible?");
        root->yes->yes = new DecisionNode("En Bloc or Intralesional Resection + Postoperative Radiation Therapy");
        root->yes->no  = new DecisionNode("Stereotactic Radiosurgery (SRS) +/- Systemic Therapy");

        root->no = new DecisionNode("Is the patient experiencing acute neurological deficits?");
        root->no->yes = new DecisionNode("Emergency Decompressive Surgery + Radiation Therapy");
        root->no->no  = new DecisionNode("Radiation Therapy (SBRT) + Systemic Chemotherapy or Targeted Therapy");
    }
};

#endif
