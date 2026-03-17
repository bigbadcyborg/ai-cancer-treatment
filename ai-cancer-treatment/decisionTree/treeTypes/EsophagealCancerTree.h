#ifndef ESOPHAGEALCANCERTREE_H
#define ESOPHAGEALCANCERTREE_H

#include "../decisionTree.h"

class EsophagealCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the tumor resectable (surgically removable)?");

        root->yes = new DecisionNode("Is the patient fit for major surgery?");
        root->yes->yes = new DecisionNode("Esophagectomy + Perioperative Chemotherapy +/- Radiation Therapy");
        root->yes->no  = new DecisionNode("Definitive Chemoradiation (Cisplatin + Fluorouracil)");

        root->no = new DecisionNode("Does the tumor express HER2?");
        root->no->yes = new DecisionNode("Chemotherapy + Targeted Therapy (Trastuzumab)");
        root->no->no  = new DecisionNode("Chemotherapy + Immunotherapy (Nivolumab)");
    }
};

#endif
