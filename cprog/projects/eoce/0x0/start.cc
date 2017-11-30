#include "start.h"
#include <stdio.h>

//constructor
start :: start()
{
	startingVal = 0;
	int index = 0;
	for (index = 0; index < 6; index++)
		startingTypeAr[index] = 0;
}

// Kind of just forcing more parent/child interaction with this
// 100% not needed at all
void start :: setStartingVal(float sV)
{
	startingVal = sV;
}

// I cant remember if I used this but its staying in case I did
float start :: retStartingVal()
{
	return((long)startingVal);
}

//store array of user input for source units
void start :: getStartingType()
{
	fprintf(stdout, "Enter source units: ");
	fscanf(stdin, "%5s", startingTypeAr);
}

// print the units for output
void start :: printUnits()
{
	int	index = 0;
	for (index = 0; startingTypeAr[index] != 0; index++)
	{
		fprintf(stdout, "%c", startingTypeAr[index]);
	}
	fprintf(stdout, " == ");
}

// return a value to determine if initial value is in bytes/bits
char start :: byteOrBit()
{
	int index = 0;
	for (index = 0; startingTypeAr[index] != 0; index++)
	{
		if ((char)startingTypeAr[index] == 'B') 
		{
			return(1);
		}
	}
}

// This function converts the entered number into either bits or bytes
// The various dibi/giga functions come from parent
float start :: baseNum()
{
	float baseNum = startingVal;

	if (startingTypeAr[0] == 98)
	{
		return(baseNum);
	}
	if (startingTypeAr[0] == 68)
	{
		if (startingTypeAr[1] == 105)
		{
			return(dibi(baseNum, 1));
		}
		else
		{
			return(deka(baseNum, 1));
		}
	}
	if (startingTypeAr[0] == 72)
	{
		if (startingTypeAr[1] == 105)
		{
			return(hibi(baseNum, 1));
		}
		else
		{
			return(hecto(baseNum, 1));
		}
	}
	if (startingTypeAr[0] == 107)
	{
		if (startingTypeAr[1] == 105)
		{
			return(kibi(baseNum, 1));
		}
		else
		{
			return(kilo(baseNum, 1));
		}
	}
	if (startingTypeAr[0] == 77)
	{
		if (startingTypeAr[1] == 105)
		{
			return(mibi(baseNum, 1));
		}
		else
		{
			return(mega(baseNum, 1));
		}
	}
	if (startingTypeAr[0] == 71)
	{
		if (startingTypeAr[1] == 105)
		{
			return(gibi(baseNum, 1));
		}
		else
		{
			return(giga(baseNum, 1));
		}
	}
	if (startingTypeAr[0] == 84)
	{
		if (startingTypeAr[1] == 105)
		{
			return(tibi(baseNum, 1));
		}
		else
		{
			return(tera(baseNum, 1));
		}
	}	
}

