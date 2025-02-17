// factBase is a Global Object in a Shared Library and is saved as
//  persistent and serialized data if handled properly
//    Note: uses Automatic Linking with g++
#ifndef FACTBASE_H
#define FACTBASE_H

#include <string>
#include <iostream>

using namespace std;

struct Fact {
	
};

// a rule is a fact so factBase inherits a ruleBase?
class FactBase {
private:
	// Private Static Attributes
	
	FactBase() = delete; // Prevent instantiation( this is a Global Static Class )
	
	
public: 
	// Public Static Functions:
	static string toString() { return "factBase calls toString() ..."; }
	
	static void saveFactBase();    // save FactBase object as a JSON binary file
	static void loadFactBase();    // load a copy of the FactBase object from binary file

};

#endif