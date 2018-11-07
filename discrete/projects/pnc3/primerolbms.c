#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	FILE           *primelist  = stdout;  // file pointer for prime number display
	FILE           *timing     = stderr;  // file pointer for timing data display
	struct timeval  ts;                   // time start
	struct timeval  te;                   // time elapsed

	//////////////////////////////////////////////////////////////////
	//
	// Argument processing
	//
	if (argc <  3)
	{
		fprintf (stderr, "%s: insufficient number of arguments!\n", argv[0]);
		exit (1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// Start our timing
	//
	gettimeofday (&ts, 0);
	
	//////////////////////////////////////////////////////////////////
	//
	// Initialize important variables
	//
	
	int 	  upper      = 0;
	int		  lower      = 0;
	int		  value	     = 0;
	int       quantity   = 0;
	int       index	   	 = 0;
	int       primeCount = 0;
	int		  div		 = 2;
	int       prime_flag = 0;
	int       helper	 = 0;
	int       ticker	 = 0;

	quantity = atoi(argv[1]);
	if (quantity == 0)
	{
		quantity = 2147483111;
	}
	else if (quantity < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit (2);
	}
	value = atoi(argv[2]);
	if (value != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		exit (3);
	}
	if (argc >= 4)
	{
		lower = atoi(argv[3]);
		if (lower < 2)
		{
			fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
			exit (4);
		}
		else if (lower == 2 || lower == 0)
		{
			lower = 5;
			fprintf(stdout, "2 3 ");
			primeCount = 2;
		}
		else
		{
			helper = lower / 6;
			lower  = (helper * 6) + 5;
		}
		if (argc >=5)
		{
			upper = atoi(argv[4]);
			if (upper == 0)
			{
				upper =  2147483647;

			}
			else if (upper <= lower)
			{
				fprintf(stderr, "%s: invalid upper bound!\n", argv[0]);
				exit (5);
			}
		}
		else
		{
			upper = 2147483647;
		}
	}
	else
	{
		lower = 5;
		upper = 2147483647;
		fprintf(primelist, "2 3 ");
		primeCount = 2;
	}

	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	index = lower;
	while (index != upper && primeCount != quantity)
	{
		if (div == index)
		{
			if (prime_flag == 0)
			{
				fprintf(primelist, "%d ", index);
				primeCount = primeCount + 1;
			}
			index = index + 1;
			ticker++;
			if (ticker == 3)
			{
				index = index + 3;
			}
			div   = 2;
			prime_flag = 0;
		}
		else
		{
			if (index % div == 0)
			{
				prime_flag = prime_flag + 1;
				div = index - 1;
			}

			if (div >= sqrt(index))
			{
				div = index - 1;
			}

			div = div + 1;
		}
	}
	fprintf(primelist, "\n");
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
