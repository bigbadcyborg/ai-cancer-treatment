#ifndef BLADDERCANCERTREE_H
#define BLADDERCANCERTREE_H

#include "../decisionTree.h"

class BladderCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer muscle-invasive?");

        root->yes = new DecisionNode("Is the patient eligible for radical cystectomy?");
        root->yes->yes = new DecisionNode("Neoadjuvant Chemotherapy (Cisplatin-based) + Radical Cystectomy");
        root->yes->no  = new DecisionNode("Trimodal Therapy: TURBT + Concurrent Chemoradiation");

        root->no = new DecisionNode("Is carcinoma in situ (CIS) present?");
        root->no->yes = new DecisionNode("TURBT + Intravesical BCG Immunotherapy");
        root->no->no  = new DecisionNode("TURBT + Intravesical Chemotherapy (Mitomycin C)");
    }
};

#endif
