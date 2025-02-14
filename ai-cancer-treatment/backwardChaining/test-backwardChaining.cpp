// Diagnose the specific Cancer (if any) using Backward Chaining 
//   Technology
//
// Goal: determine if the patient has cancer.
// Description: search through the clause list to form a diagnosis conclusion w/ RuleBase
// Post-condition: diagnosed Cancer (if any) is sent 
//   to the fowardChaining via piping and stored in 
//   fact base

//#include "backwardChaining.h"
#include "../ruleBase/ruleBase.h"
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Template function(s)
template <typename T>
bool elementExists(const vector<T>& vec, const T& element){ // find element in a vector
	return find(vec.begin(), vec.end(), element) != vec.end();
}

// Prototype(s)
vector<ClauseType>* convertVariableListToValidClauseVector(const string &str,
															const RuleBase* myRBasePtr);
string toLower(string & str);															

int main() {
	RuleBase* myRuleBase = new RuleBase(); // most-effiecient???
	
	// Retrieve all of the user's clauses and store in variableList[]
	string variableList;
	cout << "Enter Patient's Symptoms as Comma Seperated Values (A,B,C,D,E,...):" << endl;
	getline(cin,variableList);
	
	// parse into list of valid clauses
	// -implement spellchecking here
	vector<ClauseType>* userValidClauseList = convertVariableListToValidClauseVector(variableList, myRuleBase);
	cout << "User's Valid Clauses: " << userValidClauseList->size() << endl;
	for( int i = 0; i < userValidClauseList->size(); i++ ){
		cout << ClauseTypeToString((*userValidClauseList)[i], *(myRuleBase->clauseNames) ) << endl;
	}
	
	// Create Rule from userClauseList
	// Create all subset rules of clauses: O(2^n)
	
	
	// For each subset, check each rule with myRuleBase->ruleList[i]->getConclusion("subset")
	
	
	
	delete userValidClauseList;
	//return myGoal;
}

// compareClauseStrToClauseType()
// recieves: a string and ClauseType
// description: compare string with ClauseType using ClauseTypeToString(ClauseType)
// returns: true if both arguments are equal, false otherwise
bool compareClauseStrToClauseType(const string& str, ClauseType ct, const RuleBase* myRBase){
	string ctStr = ClauseTypeToString(ct, *(myRBase->clauseNames)); // conver ct to string
	bool flag = false;
	
	if( ctStr == str )
		flag = true;
	
	return flag;
}

// toLower()
// note: uses <cctype> library
// recieves: string
// description: converts str to all lowercase
// returns: nothing
string toLower(string & str) {
	string lowerStr = str;
    for ( char& c : lowerStr ){
		c = tolower(c);
	}
	
	return lowerStr;
}

// isClauseInUserList()
// recieves: const ClauseType clause,
// 			 const vector<string> & rawClauseVect
// runtime: O( n ), where n is total # of user clauses
// description:
//		initialize flag to false
//		iterate through each element in rawClauseVect
//		    compare to return val of ClauseTypeToString(clause) (spell checking???)
//			   set flag to true if equal
// returns:
//		true flag if clause exists in users rawClauseVect, false otherwise
bool isClauseInUserList( const ClauseType& clause, 
							const vector<string> & rawClauseVect,
							const RuleBase* myRBasePtr){
	bool flag = false;
	
	string strL = ClauseTypeToString(clause, *(myRBasePtr->clauseNames));
	strL = toLower( strL );
	string strR;
	for( int i = 0; i < rawClauseVect.size(); i++ ){
		// -implement spellchecking here
		strR = rawClauseVect[i]; 
		strR = toLower(strR);
		if( strL == strR ){
			flag = true;
			 			// break out of this for loop
		}
	}
	
	return flag;
}



// filter rawClauseVect into a valid list of clauses(clauses recognized in ClauseType)
// recieves: a referenced vector of string clauses 
// for each Rule's "clauses" in ruleList:
//     for each Rule (i to n)
//	       for each ClauseType in Rule's clauses vector (j to m)
//				    if clause[j] is found in userClauseList,
//					    then add clause[j] to validClauseVect	    
//
//    Run-time: O( n * m * z ), where n is the total # of Rules,
//								m is the total # clause vectors (Per Rule),
//								z is the # of elements (in user's clause list)
//
// return: vector of valid/recognized ClauseTypes
vector<ClauseType>* filterRawClauseVect(const vector<string>& rClauseVect, const RuleBase* myRBasePtr) {
    vector<ClauseType>* validClauseVectPtr = new vector<ClauseType>();
    
    // Iterate through each Rule in myRuleBase
    for (const auto& rule : *(myRBasePtr->ruleList)) {
        // Iterate through each ClauseType in the Rule's clauses vector
        for (const auto& clause : rule.clauses) {
            // Check if clause exists in within user-provided list
			// implement spell checking here
            if ( isClauseInUserList( clause, rClauseVect, myRBasePtr ) ) {
				//cout << ClauseTypeToString(clause, *(myRBasePtr->clauseNames)) << " EXISTS IN RULEBASE!" << endl;
                // if clause is not already in validClauseVect, then push to it
				if( !elementExists(*validClauseVectPtr, clause) )
				    validClauseVectPtr->push_back(clause);
				
            } //else
				//cout << ClauseTypeToString(clause, *(myRBasePtr->clauseNames)) << " DOES NOT EXIST IN RULEBASE!" << endl;
        }
    }
    
    return validClauseVectPtr;
}


// convertVariableListToVectorClauses()
// recieves: a string, str, representing the CSV list of the user's clauses
// pre-condition:
// description: parse through each comma seperated value to create rawClauseVect
//		compare ClauseType within ruleList -each clause from str
// post-condition: a dynamically allocated vector of ClauseType has been created.
// run-time: O(n * m) where n is total # of Rules and m is # of (valid) user clauses
vector<ClauseType>* convertVariableListToValidClauseVector(const string &str, const RuleBase* myRBasePtr){
	// parse CSV str into a vector of strings
	vector<string>* rawClauseVect = new vector<string>();
	istringstream ss(str);
	string token;
	while ( getline(ss, token, ',') ){
		cout << "Adding {" << token << "} to rawClauseVect ..." << endl;
		rawClauseVect->push_back(token);
	}
	cout << endl << endl;
	
	
	// Note: filterRawClauseVect() dynamically allocates and returns memory.
	vector<ClauseType>* usrValidClauseVect = filterRawClauseVect(*rawClauseVect, myRBasePtr);
	
	delete rawClauseVect;
	return usrValidClauseVect;
}



/*Process::Process(Goal){
	this->Goal* myGoal = new Goal();
	
	// create matchedClauses array
	
	do {
		
		
	} while( !myGoal->getIfReached() );
	
}

~Process(){
	
}*/


