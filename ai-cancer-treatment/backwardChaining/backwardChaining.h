#ifndef BACKWARDCHAINING_H
#define BACKWARDCHAINING_H

#include <iostream>

using namespace std;

class Process {
private:
	// Private Goal class within Proces
	class Goal {
	private:
		bool reached;
	public:
		Goal() { reached = false; }
		bool isReached() { return reached; }// Return true if reached, false otherwise
	};
	
	
public:	
	// Constructor
	Process();
	~Process();
	
	void setGoalReached(bool);
	bool getGoalReached();
};

#endif