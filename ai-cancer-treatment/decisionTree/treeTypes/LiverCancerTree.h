#ifndef LIVERCANCERTREE_H
#define LIVERCANCERTREE_H

#include "../decisionTree.h"

class LiverCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable with adequate liver reserve?");

        root->yes = new DecisionNode("Is liver function adequate (Child-Pugh A)?");
        root->yes->yes = new DecisionNode("Hepatic Resection (Surgical Removal)");
        root->yes->no  = new DecisionNode("Liver Transplantation (Milan Criteria assessment)");

        root->no = new DecisionNode("Is the tumor amenable to locoregional therapy?");
        root->no->yes = new DecisionNode("Trans-Arterial Chemoembolization (TACE) or Thermal Ablation (RFA)");
        root->no->no  = new DecisionNode("Systemic Targeted Therapy (Atezolizumab + Bevacizumab or Sorafenib)");
    }
};

#endif
