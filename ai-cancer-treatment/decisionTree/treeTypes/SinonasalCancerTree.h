#ifndef SINONASALCANCERTREE_H
#define SINONASALCANCERTREE_H

#include "../decisionTree.h"

class SinonasalCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable?");

        root->yes = new DecisionNode("Is the tumor confined to the sinonasal cavity?");
        root->yes->yes = new DecisionNode("Endoscopic or Open Surgical Resection");
        root->yes->no  = new DecisionNode("Surgical Resection + Postoperative Radiation Therapy");

        root->no = new DecisionNode("Is concurrent chemoradiation feasible?");
        root->no->yes = new DecisionNode("Concurrent Chemoradiation (Cisplatin-based)");
        root->no->no  = new DecisionNode("Palliative Chemotherapy + Targeted Therapy");
    }
};

#endif
