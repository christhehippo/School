#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	FILE           *timing     = stderr;  // file pointer for timing data display
	struct timeval  ts;                   // time start
	struct timeval  te;                   // time elapsed

	//////////////////////////////////////////////////////////////////
	//
	// Argument processing
	//

	//////////////////////////////////////////////////////////////////
	//
	// Start our timing
	//
	gettimeofday (&ts, 0);
	
	//////////////////////////////////////////////////////////////////
	//
	// Initialize important variables
	//
	//     and 
	//
	// Argument processing
	//


	int max   		   = 0;
	int res   		   = 0;
	int lower 		   = 0;
	unsigned int upper = 0;
	int div   	   	   = 0;
	int primeFlag  	   = 0;
	int primeCount     = 0;
	int ticker         = 0; // helps with main loop of 6 map 
	int lowerStore     = 0; // used to tell program not to print a prime if its less than
							// original argv4
	if (argc == 1)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n", argv[0]);
		return(5); 
	}
	else if (argc == 2)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n", argv[0]);
		return(6); 

	}


	max = atoi(argv[1]);
	if (max < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		return (1);
	}
	else if (max == 0)
	{
	max = 2147000000;
	}
	res = atoi(argv[2]);
	if (res != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		return(2);
	}

	if (argc >= 4)
	{
		lower = atoi(argv[3]);
		lowerStore = lower;

		if (lower <= 6)
		{
			if (lower < 2)
			{
				fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
				return(3);
			}
			fprintf(stdout, "2 3 ");
			primeCount = 2;

			lower = 5;
		}
		else if (lower < 2)
		{
			fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
			return(3);
		}
		else // find the closest multiple of 6 to the lower bound then subtract 1
		{
			
			while ((lower % 6) != 0)
			{
				lower++;
			}
			lower--;
		}
	}
	else
	{
		lower = 5;
		fprintf(stdout, "2 3 ");
		primeCount = 2;
	}

	if (argc == 5) // if upper specified:
	{
		upper = atoi(argv[4]);
		if (upper == 0)
		{
			upper = 2147000000;
		}
		else if(upper <= lower)
		{
			fprintf(stderr, "%s: invalid upper bound!\n", argv[0]);
			return(4);
		}
	}
	else 		  // else if it isnt, set it to max size of int
	{
		upper = 2147000000;
	}
	

	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	if (lowerStore > lower) // if you enter 24 for lower bound, this prints 23
	{						// --  this solves that issue
		lower++;
		ticker++;
	}
	while (lower <= upper)
	{
		primeFlag = 0;
		for (div  = 2; div < lower; div++)
		{
			if ((lower % div) == 0)
			{
				primeFlag++;
			}
		}
		if (primeFlag == 0)
		{
			fprintf(stdout, "%d ", lower);
			primeCount++;
			
			if (primeCount == max)
				break;
		}
		ticker++;
		if (ticker == 3)
		{
			ticker = 0;
			lower = lower + 3;
		}

		lower++;
	}
	fprintf(stdout, "\n");

	//////////////////////////////////////////////////////////////////
	//
	// Stop our timing
	//
	gettimeofday (&te, 0);

	//////////////////////////////////////////////////////////////////
	//
	// Display timing information
	//
	fprintf (timing, "%8.4lf\n",
			te.tv_sec - ts.tv_sec + ((te.tv_usec - ts.tv_usec) / 1000000.0));

	return (0);
}
