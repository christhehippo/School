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
	// Start our timing
	//
	gettimeofday (&ts, 0);
	
	//////////////////////////////////////////////////////////////////
	//
	// Initialize important variables
	//
	int max   = 0;
	int res   = 0;
	int lower = 0;
	unsigned int upper = 0;

	if (argc < 3)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n", argv[0]);
		return(5);
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

		if (lower == 2)
			lower = 3;

		if (lower < 2)
		{
			fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
			return(3);
		}
	}
	else
	{
		lower = 3;
		
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
	

	int div   	   = 0;
	int primeFlag  = 0;
	int primeCount = 1;
	int sqrt       = 2;
//	int index = 0;
	while ((sqrt * sqrt) < lower)
		sqrt++;

	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	
	if (lower == 3)
		fprintf(stdout, "2 "); // if lower not set, print 2
	else
		primeCount = 0;
	while (lower <= upper)
	{
		primeFlag = 0;
		for (div  = 2; div <= sqrt; div++)
		{
			if ((lower % div) == 0)
			{
				primeFlag++;
				break;
			}
		}
		if (primeFlag == 0)
		{
			fprintf(stdout, "%d ", lower);
			primeCount++;
			
			if (primeCount == max)
				break;
		}
		lower++;
		if ((sqrt * sqrt) <= lower)
			sqrt++;
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
