#ifndef _END_H
#define _END_H

#include "parent.h"

class end : public parent
{
	public:
		end();
		void getMeters(float m); // gets start's converted value
		float retEVal(); // Return end Val
		void getUnits(); // Fill endUnits array
		void base(); // Convert meters to end units
		void printUnits(); // fixes units i.e. dm to decimeter
	private:
		float eVal; // start value
		char endUnits[14]; // starting units array
		float meters;
};

#endif


