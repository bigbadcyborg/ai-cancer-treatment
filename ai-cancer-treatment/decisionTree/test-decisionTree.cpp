#include "decisionTree.h"
#include "./treeTypes/BreastCancerTree.h"
#include "./treeTypes/LungCancerTree.h"

int main() {
    cout << "Select Cancer Type:\n1. Lung Cancer\n2. Breast Cancer\n";
    int choice;
    cin >> choice;

    ConclusionType type;
    if (choice == 1) {
        type = ConclusionType::LUNG_CANCER;
    } else if (choice == 2) {
        type = ConclusionType::BREAST_CANCER;
    } else {
        cout << "Invalid choice. Exiting program.\n";
        return 1;  // Exit program if invalid choice
    }

    // Create the decision tree based on the selected type
    DecisionTree* myDecisionTreePtr = createDecisionTree(type);
    if (myDecisionTreePtr) {
        myDecisionTreePtr->buildTree();  // Build tree specific to cancer type
        myDecisionTreePtr->traverseTree();  // Traverse tree and make decisions
    } else {
        cout << "Error: Unable to create decision tree for the selected cancer type.\n";
    }
	
	
	delete myDecisionTreePtr;

    return 0;
}