#ifndef PROSTATECANCERTREE_H
#define PROSTATECANCERTREE_H

#include "../decisionTree.h"

class ProstateCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer localized to the prostate?");

        root->yes = new DecisionNode("Is active surveillance appropriate (low-risk, slow-growing)?");
        root->yes->yes = new DecisionNode("Active Surveillance with Regular PSA Monitoring and Biopsies");
        root->yes->no  = new DecisionNode("Radical Prostatectomy or Definitive Radiation Therapy (EBRT/Brachytherapy)");

        root->no = new DecisionNode("Is the cancer metastatic?");
        root->no->yes = new DecisionNode("Androgen Deprivation Therapy (ADT) + Chemotherapy or Targeted Therapy");
        root->no->no  = new DecisionNode("Radiation Therapy + Androgen Deprivation Therapy (ADT)");
    }
};

#endif
