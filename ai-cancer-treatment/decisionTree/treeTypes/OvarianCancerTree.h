#ifndef OVARIANCANCERTREE_H
#define OVARIANCANCERTREE_H

#include "../decisionTree.h"

class OvarianCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer early-stage (Stage I-II)?");

        root->yes = new DecisionNode("Is fertility preservation desired?");
        root->yes->yes = new DecisionNode("Fertility-Sparing Surgery (Unilateral Salpingo-Oophorectomy) + Staging");
        root->yes->no  = new DecisionNode("Total Abdominal Hysterectomy + Bilateral Salpingo-Oophorectomy + Staging");

        root->no = new DecisionNode("Is optimal cytoreduction (debulking) achievable?");
        root->no->yes = new DecisionNode("Primary Debulking Surgery + Platinum/Taxane Chemotherapy +/- Bevacizumab");
        root->no->no  = new DecisionNode("Neoadjuvant Chemotherapy + Interval Debulking Surgery");
    }
};

#endif
