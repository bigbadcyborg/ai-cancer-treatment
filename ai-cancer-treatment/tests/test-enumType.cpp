#include <iostream>
#include <unordered_map>

using namespace std;

class RuleBase {
public:
    enum DiagnosisType {
        PROSTATE_CANCER,
        LUNG_CANCER
        // other diagnosis types...
    };

    unordered_map<DiagnosisType, string> diagnosisNames = {
        {PROSTATE_CANCER, "Prostate Cancer"},
        {LUNG_CANCER, "Lung Cancer"}
        // other mappings...
    };
};

int main() {
    RuleBase ruleBase;
    cout << ruleBase.diagnosisNames[RuleBase::PROSTATE_CANCER];  // Should print "Prostate Cancer"
    return 0;
}

