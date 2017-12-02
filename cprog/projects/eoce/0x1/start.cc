#include "start.h"
#include <stdio.h>

start :: start()
{
	sVal = 0;
}

void start :: getSVal()
{
	this->sVal = parent::retSVal();
}

float start :: retSVal()
{
	return(sVal);
}

void start :: getUnits()
{
	fprintf(stdout, "Enter source unit: ");
	fscanf(stdin, "%13s", startUnits);
}

float start :: retMeters()
{
	return(meters);
}

// properly writes units out
void start :: printUnits()
{
	if (startUnits[0] == 'i')
	{
		fprintf(stdout, "inches");
	}
	else if (startUnits[0] == 'l' && startUnits[3] == 0)
	{
		fprintf(stdout, "lea");
	}
	else if (startUnits[0] == 'f')
	{
		fprintf(stdout, "feet");
	}
	else if (startUnits[0] == 'y')
	{
		fprintf(stdout, "yards");
	}
	else if (startUnits[0] == 'm' && startUnits[1] == 'i')
	{
		fprintf(stdout, "miles");
	}
	else if (startUnits[0] == 'g')
	{
		fprintf(stdout, "Greek stadion");
	}

	else if (startUnits[0] == 'r' && startUnits[6] == 'f')
	{
		fprintf(stdout, "Roman feet");
	}
	else if (startUnits[0] == 'r' && startUnits[6] == 'm')
	{
		fprintf(stdout, "Roman miles");
	}
	else if (startUnits[0] == 'r' && startUnits[3] == 'l')
	{
		fprintf(stdout, "Roman leagues");
	}
	else if (startUnits[0] == 'l' && startUnits[3] == 'g')
	{
		fprintf(stdout, "leagues");
	}
	else if (startUnits[0] == 'c' && startUnits[1] == 'u')
	{
		fprintf(stdout, "cubits");
	}
	else if (startUnits[0] == 'm' && startUnits[1] == 'm')
	{
		fprintf(stdout, "millimeters");
	}
	else if (startUnits[0] == 'c' && startUnits[1] == 'm')
	{
		fprintf(stdout, "centimeters");
	}
	else if (startUnits[0] == 'd' && startUnits[1] == 'm')
	{
		fprintf(stdout, "decimeters");
	}
	else if (startUnits[0] == 'D' && startUnits[1] == 'm')
	{
		fprintf(stdout, "dekameters");
	}
	else if (startUnits[0] == 'h' && startUnits[1] == 'm')
	{
		fprintf(stdout, "hectometers");
	}
	else if (startUnits[0] == 'k' && startUnits[1] == 'm')
	{
		fprintf(stdout, "kilometers");
	}
	else if (startUnits[0] == 'M' && startUnits[1] == 'm')
	{
		fprintf(stdout, "megameters");
	}
	else
	{
		fprintf(stdout, "meters");
	}
}

// Here is the conversion function that calls the various functions
// that are in parent based on what some array checking
// the values are converted to meters as a base, and then converted
// to the end destination in end's function
void start :: base()
{
	if (startUnits[0] == 'i')
	{
		meters = inch(sVal, 0);
	}
	else if (startUnits[0] == 'l' && startUnits[3] == 0)
	{
		meters = lea(sVal, 0);
	}
	else if (startUnits[0] == 'f')
	{
		meters = foot(sVal, 0);
	}
	else if (startUnits[0] == 'y')
	{
		meters = yard(sVal, 0);
	}
	else if (startUnits[0] == 'm' && startUnits[1] == 'i')
	{
		meters = mile(sVal, 0);
	}
	else if (startUnits[0] == 'g')
	{
		meters = greekStadion(sVal, 0);
	}

	else if (startUnits[0] == 'r' && startUnits[6] == 'f')
	{
		meters = romanFoot(sVal, 0);
	}
	else if (startUnits[0] == 'r' && startUnits[6] == 'm')
	{
		meters = romanMile(sVal, 0);
	}
	else if (startUnits[0] == 'r' && startUnits[3] == 'l')
	{
		meters = romanLeague(sVal, 0);
	}
	else if (startUnits[0] == 'l' && startUnits[3] == 'g')
	{
		meters = league(sVal, 0);
	}
	else if (startUnits[0] == 'c' && startUnits[1] == 'u')
	{
		meters = cubit(sVal, 0);
	}
	else if (startUnits[0] == 'm' && startUnits[1] == 'm')
	{
		meters = mm(sVal, 0);
	}
	else if (startUnits[0] == 'c' && startUnits[1] == 'm')
	{
		meters = cm(sVal, 0);
	}
	else if (startUnits[0] == 'd' && startUnits[1] == 'm')
	{
		meters = dm(sVal, 0);
	}
	else if (startUnits[0] == 'D' && startUnits[1] == 'm')
	{
		meters = Dm(sVal, 0);
	}
	else if (startUnits[0] == 'h' && startUnits[1] == 'm')
	{
		meters = hm(sVal, 0);
	}
	else if (startUnits[0] == 'k' && startUnits[1] == 'm')
	{
		meters = lea(sVal, 0);
	}
	else if (startUnits[0] == 'M' && startUnits[1] == 'm')
	{
		meters = lea(sVal, 0);
	}
	else
	{
		meters = sVal;
	}
}
