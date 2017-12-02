#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "start.h"
#include "end.h"

int main()
{
	parent parent;
	start start;
	end end;

	start.setStartingVal(parent.getStartingVal());
	start.getStartingType();
	end.getEndingType();
	fprintf(stdout, "\n%.0f ", start.retStartingVal());
	start.printUnits();
	fprintf(stdout, "%.4f ", end.finalNum(start.baseNum(), start.byteOrBit()));
	end.printUnits();
	fprintf(stdout, "\n");
	
	
	return(0);
}
