#ifndef _START_H
#define _START_H

#include "parent.h"

class start : public parent
{
	public:
		start();
		void setStartingVal(float sV); //get initial value from parent function
		float retStartingVal();
		void getStartingType(); // collects the array/prompts for input
		 // return a number value corresponding to type
		void printUnits(); // print the unit for output
		float baseNum(); // convert entry to some unit
		char byteOrBit();		
	private:
		float startingVal;
		char startingTypeAr[6];
		char startingType;

};

#endif
