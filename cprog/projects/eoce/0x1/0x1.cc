#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "end.h"

int main()
{
	start start;
	start.getSVal();
	start.getUnits();
	start.base();

	end end;
	end.getUnits();
	end.getMeters(start.retMeters());
	end.base();

	fprintf(stdout, "%.0f ", start.retSVal());
	start.printUnits();
	fprintf(stdout, " == ");

	fprintf(stdout, "%.4f ", end.retEVal());
	end.printUnits();
	fprintf(stdout, "\n");
	


	return(0);

}
