#include "../variableList/conclusionTypes.h"
#include "decisionTree.h" // has ConclusionTypes and ClauseTypes
#include "./treeTypes/BreastCancerTree.h"
#include "./treeTypes/LungCancerTree.h"
#include "./treeTypes/EsophagealCancerTree.h"
#include "./treeTypes/ColorectalCancerTree.h"
#include "./treeTypes/BladderCancerTree.h"
#include "./treeTypes/LymphomaCancerTree.h"
#include "./treeTypes/CervicalCancerTree.h"
#include "./treeTypes/MelanomaCancerTree.h"
#include "./treeTypes/BoneCancerTree.h"
#include "./treeTypes/PancreaticCancerTree.h"
#include "./treeTypes/BrainCancerTree.h"
#include "./treeTypes/LeukemiaCancerTree.h"
#include "./treeTypes/ThyroidCancerTree.h"
#include "./treeTypes/ProstateCancerTree.h"
#include "./treeTypes/LiverCancerTree.h"
#include "./treeTypes/NasopharyngealCancerTree.h"
#include "./treeTypes/StomachCancerTree.h"
#include "./treeTypes/SpinalCancerTree.h"
#include "./treeTypes/OvarianCancerTree.h"
#include "./treeTypes/OralCancerTree.h"
#include "./treeTypes/LaryngealCancerTree.h"
#include "./treeTypes/SinonasalCancerTree.h"
#include <algorithm>  // For std::transform



using namespace std;


DecisionTree* createDecisionTree(ConclusionType type) {
	DecisionTree* dtPtr = nullptr;
    // Use type traits to determine which tree to create
    if (type == ConclusionType::LUNG_CANCER) {
        dtPtr = new LungCancerTree();
    } else if (type == ConclusionType::BREAST_CANCER) {
        dtPtr = new BreastCancerTree();
    } else if (type == ConclusionType::ESOPHAGEAL_CANCER) {
        dtPtr = new EsophagealCancerTree();
    } else if (type == ConclusionType::COLORECTAL_CANCER) {
        dtPtr = new ColorectalCancerTree();
    } else if (type == ConclusionType::BLADDER_CANCER) {
        dtPtr = new BladderCancerTree();
    } else if (type == ConclusionType::LYMPHOMA) {
        dtPtr = new LymphomaCancerTree();
    } else if (type == ConclusionType::CERVICAL_CANCER) {
        dtPtr = new CervicalCancerTree();
    } else if (type == ConclusionType::MELANOMA) {
        dtPtr = new MelanomaCancerTree();
    } else if (type == ConclusionType::BONE_CANCER) {
        dtPtr = new BoneCancerTree();
    } else if (type == ConclusionType::PANCREATIC_CANCER) {
        dtPtr = new PancreaticCancerTree();
    } else if (type == ConclusionType::BRAIN_CANCER) {
        dtPtr = new BrainCancerTree();
    } else if (type == ConclusionType::LEUKEMIA) {
        dtPtr = new LeukemiaCancerTree();
    } else if (type == ConclusionType::THYROID_CANCER) {
        dtPtr = new ThyroidCancerTree();
    } else if (type == ConclusionType::PROSTATE_CANCER) {
        dtPtr = new ProstateCancerTree();
    } else if (type == ConclusionType::LIVER_CANCER) {
        dtPtr = new LiverCancerTree();
    } else if (type == ConclusionType::NASOPHARYNGEAL_CANCER) {
        dtPtr = new NasopharyngealCancerTree();
    } else if (type == ConclusionType::STOMACH_CANCER) {
        dtPtr = new StomachCancerTree();
    } else if (type == ConclusionType::SPINAL_CANCER) {
        dtPtr = new SpinalCancerTree();
    } else if (type == ConclusionType::OVARIAN_CANCER) {
        dtPtr = new OvarianCancerTree();
    } else if (type == ConclusionType::ORAL_CANCER) {
        dtPtr = new OralCancerTree();
    } else if (type == ConclusionType::LARYNGEAL_CANCER) {
        dtPtr = new LaryngealCancerTree();
    } else if (type == ConclusionType::SINONASAL_CANCER) {
        dtPtr = new SinonasalCancerTree();
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
    if (!root) {
        cout << "Error: decision tree has not been built.\n";
        return;
    }

    DecisionNode* current = root;
    string answer;

    while (current) {
        // Leaf node: both children are null — this is the final recommendation.
        if (!current->yes && !current->no) {
            cout << "Final Recommendation: " << current->question << endl;
            break;
        }

        cout << current->question << " (yes/no): ";
        cin >> answer;
        answer = toLowerCase(answer);

        if (answer == "yes" || answer == "y") {
            if (current->yes) {
                current = current->yes;
            } else {
                cout << "Final Recommendation: " << current->question << endl;
                break;
            }
        } else if (answer == "no" || answer == "n") {
            if (current->no) {
                current = current->no;
            } else {
                cout << "Final Recommendation: " << current->question << endl;
                break;
            }
        } else {
            cout << "Invalid response. Please answer yes or no.\n";
        }
    }
}

