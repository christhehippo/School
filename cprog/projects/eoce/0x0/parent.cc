#include "parent.h"
#include <stdio.h>

parent :: parent()
{
	startingVal = 0;
}

float parent :: getStartingVal()
{
	fprintf(stdout, "Enter source value: ");
	fscanf(stdin, "%f", &startingVal);
	return(startingVal);
}

float parent :: bitsToBytes(float val)
{
	float bytes = val / 8;
	return(bytes);
}

// name says it all for bitsToBytes and bytesToBits
// maybe didnt need a function but hey, inherite(a?)nce
float parent :: bytesToBits(float val)
{
	float bits = val * 8;
	return(bits);
}

// All functions that follow are conversions for each supported type
// They go both to the type from b/B and go from the type to bits(bytes)
float parent :: deka(float val, char i)
{
	if (i == 0)
	{
		val = val / 10;
	}
	else 
	{
		val = val * 10;
	}
	return(val);
}
float parent :: dibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 16;
	}
	else 
	{
		val = val * 16;
	}
	return(val);
}
float parent :: hecto(float val, char i)
{
	if (i == 0)
	{
		val = val / 100;
	}
	else 
	{
		val = val * 100;
	}
	return(val);
}
float parent :: hibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 128;
	}
	else 
	{
		val = val * 128;
	}
	return(val);
}

float parent :: kilo(float val, char i)
{
	if (i == 0)
	{
		val = val / 1000;
	}
	else 
	{
		val = val * 1000;
	}
	return(val);
}
float parent :: kibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 1024;
	}
	else 
	{
		val = val * 1024;
	}
	return(val);
}
float parent :: mega(float val, char i)
{
	if (i == 0)
	{
		val = val / 1000000;
	}
	else 
	{
		val = val * 1000000;
	}
	return(val);
}
float parent :: mibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 1048576;
	}
	else 
	{
		val = val * 1048576;
	}
	return(val);
}

float parent :: giga(float val, char i)
{
	if (i == 0)
	{
		val = val / 1000000000;
	}
	else 
	{
		val = val * 1000000000;
	}
	return(val);
}
float parent :: gibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 1073741824;
	}
	else 
	{
		val = val * 1073741824;
	}
	return(val);
}
float parent :: tera(float val, char i)
{
	if (i == 0)
	{
		val = val / 1000000000000;
	}
	else 
	{
		val = val * 1000000000000;
	}
	return(val);
}
float parent :: tibi(float val, char i)
{
	if (i == 0)
	{
		val = val / 1099511627776;
	}
	else 
	{
		val = val * 1099511627776;
	}
	return(val);
}

