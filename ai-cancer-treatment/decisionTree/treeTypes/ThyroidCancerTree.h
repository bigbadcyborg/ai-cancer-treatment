#ifndef THYROIDCANCERTREE_H
#define THYROIDCANCERTREE_H

#include "../decisionTree.h"

class ThyroidCancerTree : public DecisionTree {
public:
    void buildTree() override {
        root = new DecisionNode("Is the cancer differentiated (papillary or follicular)?");

        root->yes = new DecisionNode("Is the tumor > 1 cm or multifocal/high-risk?");
        root->yes->yes = new DecisionNode("Total Thyroidectomy + Radioactive Iodine (RAI) Therapy");
        root->yes->no  = new DecisionNode("Thyroid Lobectomy + Thyroid Hormone Suppression Therapy");

        root->no = new DecisionNode("Is this medullary thyroid cancer?");
        root->no->yes = new DecisionNode("Total Thyroidectomy + Targeted Therapy (Vandetanib or Cabozantinib)");
        root->no->no  = new DecisionNode("Surgery + External Beam Radiation Therapy + Chemotherapy");
    }
};

#endif
