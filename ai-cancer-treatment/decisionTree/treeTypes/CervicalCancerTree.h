#ifndef CERVICALCANCERTREE_H
#define CERVICALCANCERTREE_H

#include "../decisionTree.h"

class CervicalCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer early-stage (Stage I-IIA)?");

        root->yes = new DecisionNode("Is surgical resection the preferred treatment?");
        root->yes->yes = new DecisionNode("Radical Hysterectomy + Pelvic Lymph Node Dissection");
        root->yes->no  = new DecisionNode("Definitive Radiation Therapy (EBRT + Brachytherapy)");

        root->no = new DecisionNode("Is the patient eligible for concurrent chemotherapy?");
        root->no->yes = new DecisionNode("Concurrent Chemoradiation (Cisplatin-based) + Brachytherapy");
        root->no->no  = new DecisionNode("Palliative Radiation Therapy +/- Immunotherapy");
    }
};

#endif
