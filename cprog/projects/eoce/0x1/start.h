#ifndef _START_H
#define _START_H

#include "parent.h"

class start : public parent
{
	public:
		start();
		void getSVal(); // Obtain parent's start val
		float retSVal(); // Return sVal
		void getUnits(); // Fill startUnits array
		void base(); // Convert sVal to meters
		float retMeters(); // return converted num
		void printUnits();
	private:
		float sVal; // start value
		float meters; // converted val
		char startUnits[14]; // starting units array
};

#endif


