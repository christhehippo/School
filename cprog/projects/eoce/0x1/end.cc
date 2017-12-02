#include "end.h"
#include <stdio.h>

end :: end()
{
	eVal = 0;
}

void end :: getMeters(float m)
{
	meters = m;
}

void end :: getUnits()
{
	fprintf(stdout, "Enter destination unit: ");
	fscanf(stdin, "%13s", endUnits);
}

float end :: retEVal()
{
	return(eVal);
}

// rewriting the units
void end :: printUnits()
{
	if (endUnits[0] == 'i')
	{
		fprintf(stdout, "inches");
	}
	else if (endUnits[0] == 'l' && endUnits[3] == 0)
	{
		fprintf(stdout, "lea");
	}
	else if (endUnits[0] == 'f')
	{
		fprintf(stdout, "feet");
	}
	else if (endUnits[0] == 'y')
	{
		fprintf(stdout, "yards");
	}
	else if (endUnits[0] == 'm' && endUnits[1] == 'i')
	{
		fprintf(stdout, "miles");

	}
	else if (endUnits[0] == 'g')
	{
		fprintf(stdout, "Greek stadions");
	}
	else if (endUnits[0] == 'r' && endUnits[6] == 'f')
	{
		fprintf(stdout, "Roman feet");
	}
	else if (endUnits[0] == 'r' && endUnits[6] == 'm')
	{	
		fprintf(stdout, "Roman miles");
	}
	else if (endUnits[0] == 'r' && endUnits[3] == 'l')
	{
		fprintf(stdout, "Roman leagues");
	}
	else if (endUnits[0] == 'l' && endUnits[3] == 'g')
	{
		fprintf(stdout, "leagues");
	}
	else if (endUnits[0] == 'c' && endUnits[1] == 'u')
	{
		fprintf(stdout, "cubits");
	}
	else if (endUnits[0] == 'm' && endUnits[1] == 'm')
	{
		fprintf(stdout, "millimeters");
	}
	else if (endUnits[0] == 'c' && endUnits[1] == 'm')
	{
		fprintf(stdout, "centimeters");
	}
	else if (endUnits[0] == 'd' && endUnits[1] == 'm')
	{
		fprintf(stdout, "decimeters");
	}
	else if (endUnits[0] == 'D' && endUnits[1] == 'm')
	{
		fprintf(stdout, "dekameters");
	}
	else if (endUnits[0] == 'h' && endUnits[1] == 'm')
	{
			fprintf(stdout, "hectometers");
	}
	else if (endUnits[0] == 'k' && endUnits[1] == 'm')
	{
		fprintf(stdout, "kilometers");
	}
	else if (endUnits[0] == 'M' && endUnits[1] == 'm')
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
// the values are converted from meters to the intended unit
void end :: base()
{
	if (endUnits[0] == 'i')
	{
		eVal = inch(meters, 1);
	}
	else if (endUnits[0] == 'l' && endUnits[3] == 0)
	{
		eVal = lea(meters, 1);
	}
	else if (endUnits[0] == 'f')
	{
		eVal = foot(meters, 1);
	}
	else if (endUnits[0] == 'y')
	{
		eVal = yard(meters, 1);
	}
	else if (endUnits[0] == 'm' && endUnits[1] == 'i')
	{
		eVal = mile(meters, 1);
	}
	else if (endUnits[0] == 'g')
	{
		eVal = greekStadion(meters, 1);
	}

	else if (endUnits[0] == 'r' && endUnits[6] == 'f')
	{
		eVal = romanFoot(meters, 1);
	}
	else if (endUnits[0] == 'r' && endUnits[6] == 'm')
	{
		eVal = romanMile(meters, 1);
	}
	else if (endUnits[0] == 'r' && endUnits[3] == 'l')
	{
		eVal = romanLeague(meters, 1);
	}
	else if (endUnits[0] == 'l' && endUnits[3] == 'g')
	{
		eVal = league(meters, 1);
	}
	else if (endUnits[0] == 'c' && endUnits[1] == 'u')
	{
		eVal = cubit(meters, 1);
	}
	else if (endUnits[0] == 'm' && endUnits[1] == 'm')
	{
		eVal = mm(meters, 1);
	}
	else if (endUnits[0] == 'c' && endUnits[1] == 'm')
	{
		eVal = cm(meters, 1);
	}
	else if (endUnits[0] == 'd' && endUnits[1] == 'm')
	{
		eVal = dm(meters, 1);
	}
	else if (endUnits[0] == 'D' && endUnits[1] == 'm')
	{
		eVal = Dm(meters, 1);
	}
	else if (endUnits[0] == 'h' && endUnits[1] == 'm')
	{
		eVal = hm(meters, 1);
	}
	else if (endUnits[0] == 'k' && endUnits[1] == 'm')
	{
		eVal = lea(meters, 1);
	}
	else if (endUnits[0] == 'M' && endUnits[1] == 'm')
	{
		eVal = lea(meters, 1);
	}
	else
	{
		eVal = meters; 
	}
}
