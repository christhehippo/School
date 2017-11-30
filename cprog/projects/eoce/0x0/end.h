#ifndef _END_H
#define _END_H

#include "parent.h"

class end : public parent
{
	public:
		end();
		void getEndingType(); // collects the array/prompts for input
		 // return a number value corresponding to type
		void printUnits(); // print the unit for output
		float finalNum(float bits, char bob); // convert entry to bits, ensures no rounding issues 
	private:
		char endingTypeAr[6];
		char endingType;

};

#endif
