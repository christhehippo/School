#include "end.h"
#include <stdio.h>

end :: end()
{
	int index = 0;
	for (index = 0; index < 6; index++)
		endingTypeAr[index] = 0;
}

void end :: getEndingType()
{
	fprintf(stdout, "Enter destination units: ");
	fscanf(stdin, "%5s", endingTypeAr);
//	int index = 0;
//	for (index = 0; index < 5; index++)
//	{
//		fprintf(stdout, "%c\n", endingTypeAr[index]);
//	}
}

void end :: printUnits()
{
	int	index = 0;
	for (index = 0; endingTypeAr[index] != 0; index++)
	{
		fprintf(stdout, "%c", endingTypeAr[index]);
	}
	
}


float end :: finalNum(float bits,  char bob)
{
	int index = 0;
	endingType = 0;
	for (index = 0; endingTypeAr[index] != 0; index++)
	{
		if (endingTypeAr[index] == 'B')
		{
			endingType = 1;
		}
	}

	if (bob == 0 && endingType == 1)
	{
		bits = bits / 8;
	}
	else if (bob == 1 && endingType == 0)
	{
		bits = bits * 8;
	}
	
	if (endingTypeAr[0] == 98)
	{
		return(bits);
	}
	if (endingTypeAr[0] == 68)
	{
		if (endingTypeAr[1] == 105)
		{
			return(dibi(bits, 0));
		}
		else
		{
			return(deka(bits, 0));
		}
	}
	if (endingTypeAr[0] == 72)
	{
		if (endingTypeAr[1] == 105)
		{
			return(hibi(bits, 0));
		}
		else
		{
			return(hecto(bits, 0));
		}
	}
	if (endingTypeAr[0] == 107)
	{
		if (endingTypeAr[1] == 105)
		{
			return(kibi(bits, 0));
		}
		else
		{
			return(kilo(bits, 0));
		}
	}
	if (endingTypeAr[0] == 77)
	{
		if (endingTypeAr[1] == 105)
		{
			return(mibi(bits, 0));
		}
		else
		{
			return(mega(bits, 0));
		}
	}
	if (endingTypeAr[0] == 71)
	{
		if (endingTypeAr[1] == 105)
		{
			return(gibi(bits, 0));
		}
		else
		{
			return(giga(bits, 0));
		}
	}
	if (endingTypeAr[0] == 84)
	{
		if (endingTypeAr[1] == 105)
		{
			return(tibi(bits, 0));
		}
		else
		{
			return(tera(bits, 0));
		}
	}	
}

