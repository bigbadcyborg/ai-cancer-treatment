// This script will pick up any diagnosed cancers or possible conclusions in the
//   fact base via piping and then Recommend types of treatment
//   using Forward Chaining Methodology
/*
    Forward Chaining is a method which builds a decision tree based on a
	derived Conclusion from Backchaining as well as future facts via user input.
	It creates a conclusion based on rules and user facts.
    For example, say our decided rule base states that if a and b then c.
	Now, when the user gives values a and b, the system generates c.

    Our rule base will contain cancer symptoms.

    CPS#2-53:
        Rule # = [({Quotient (Clause # / 4)} +1) * 10]


*/
#include "forwardChaining.h"

using namespace std;

int main() {
	    // Read serialized data from stdin (pipe input)
    string serializedStr;
    getline(cin, serializedStr, '\0');  // Read till null character

    // Deserialize the enum value back from the byte stream
    ConclusionType conclusion = EnumSerialization::deserialize<ConclusionType>( serializedStr );
	
	// Print Diagnosis
	if ( conclusion == BRAIN_CANCER )
		cerr << "Serialized Object Recovered: Brain Cancer" << endl;
	
	return 0;
}

// ForwardChaining Constructor
ForwardChaining::ForwardChaining(){
	this->diagnosisPtr = nullptr;
	this->possibleConclusionsPtr = nullptr;
	
}

// ForwardChaining Destructor
ForwardChaining::~ForwardChaining(){
	if ( this->diagnosisPtr != nullptr )
		delete this->diagnosisPtr;
	
	if( this->possibleConclusionsPtr != nullptr )
		delete this->possibleConclusionsPtr;
}

// createDecisionTree()
// pre-condition: no dynamic memory is allocated yet
// recieves:
// description: this->function determines if backwardChaining has made either
//		a possible conclusion or a diagnosis then creates a DecisionTree
// returns: a ptr to dynamically allocated DecisionTree
DecisionTree* ForwardChaining::createDecisionTree(){
	
	return nullptr;
}

// getConclusionFromBackwardChaining()
void ForwardChaining::getConclusionFromBackwardChaining(){
	
	
}
