#include "./treeTypes/BreastCancerTree.h"
#include "./treeTypes/LungCancerTree.h"
#include "decisionTree.h" // has ConclusionTypes and ClauseTypes
#include <algorithm>  // For std::transform



using namespace std;


DecisionTree* createDecisionTree(ConclusionType type) {
	DecisionTree* dtPtr = nullptr;
    // Use type traits to determine which tree to create
    if (type == ConclusionType::LUNG_CANCER) {
        dtPtr = new LungCancerTree();
    } else if (type == ConclusionType::BREAST_CANCER) {
        dtPtr = new BreastCancerTree();
    } else {
		cout << "createDecisionTree Error: ";
		cout << "Unable to create decision tree for the selected cancer type." << endl;
    }
	
	return dtPtr;
}


// Helper function to convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


// Traverse tree to make decisions
void DecisionTree::traverseTree() {
    DecisionNode* current = root;
    cout << current->question << " (yes/no): ";
    string answer;
    cin >> answer;

    while (current) {
        // Convert answer to lowercase
        answer = toLowerCase(answer);

        if (answer == "yes" || answer == "y") {
            if (current->yes)
                current = current->yes;  // Move to the "yes" node
            else {
                cout << "Final Recommendation: " << current->question << endl;
                break;
            }
        } else if (answer == "no" || answer == "n") {
            if (current->no)
                current = current->no;  // Move to the "no" node
            else {
                cout << "Final Recommendation: " << current->question << endl;
                break;
            }
        } else {
            cout << "Invalid response. Please answer yes or no.\n";
        }

        if (current) {
            cout << current->question << " (yes/no): ";
            cin >> answer;
        }
    }
}

