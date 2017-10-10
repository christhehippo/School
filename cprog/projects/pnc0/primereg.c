#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	struct timeval  ts;                   // time start
	struct timeval  te;                   // time elapsed

	//////////////////////////////////////////////////////////////////
	//
	// Argument processing
	//
	if (argc <  3)
	{
		fprintf (stderr, "%s: insufficient number of arguments\n", argv[0]);
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
	
	// quantity of primes to stop at, if 0, goes until upper bound
	int quanCheck = atoi(argv[1]);
	// error if value of number of primes is less than 0 
	if (quanCheck < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit (2);
	}
	if (quanCheck == 0)
	{
		quanCheck = quanCheck - 1;
		// error if you dont put a number of primes to stop at without an upper bound
		if (argc != 5)
		{
			fprintf(stderr, "%s: upper bound needed when quantity of primes = 0!\n", argv[0]);
			exit (3);
		}
	}
	
	// unused variable for later
	int unusedVariable = atoi(argv[2]);
	// error for unused variable
	if (unusedVariable != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		exit (4);
	}
	
	// variables to store upper and lower bounds
	int lowerBound;
    int upperBound;
	//check if bounds were supplied by user, if not, use the default values.
	if (argc == 5)
	{
		lowerBound = atoi(argv[3]);
		upperBound = atoi(argv[4]);
		
	}
	else if (argc == 4)
	{
		lowerBound = atoi(argv[3]);
		upperBound = 2147483647;
	}
	else 
	{
		lowerBound = 2;
		upperBound = 2147483647;
	}

	//upper and lower bound errors
	if (lowerBound < 2)
		{
			fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
			exit (5);
		}
	if (upperBound <= lowerBound)
	{
		fprintf(stderr, "%s: invalid upper bound!\n", argv[0]);
		exit (6);
	}

	//LOOP VARIABLES
	int forOne; 		// first loop incremental value
	int forTwo; 		// second loop incremental value
	int primeCheck = 0; // used after calculations to determine if a number is prime
	int primeCount = 0; // each time a number comes out prime, increases by one

	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	
	for (forOne = lowerBound; forOne <= upperBound; forOne++)
	{
		for (forTwo = 2; forTwo < forOne; forTwo++)
		{
			//if a number isnt prime, the prime check becomes greater than 0
			if (forOne % forTwo == 0)
			{
				primeCheck++;
			}
			//if the prime check is 0, that means no numbers divided evenly into the value being tested in the first loop
			if (forTwo == forOne - 1 && primeCheck == 0)
			{
				fprintf(stdout, "%d ", forOne);
				//add a tick to the count of primes, this lets you stop at "quanCheck" prime numbers printed
				primeCount++;
			}
		}
		// if you have printed "quanCheck" prime numbers, the loop ends
		if (primeCount == quanCheck)
		{
			break;
		}
	//reset the value of the prime check to 0 for next time the second loop is used
	primeCheck = 0;
	}
	//done calculating primes, print new line for time	
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
	fprintf (stderr, "%8.4lf\n",
			te.tv_sec - ts.tv_sec + ((te.tv_usec - ts.tv_usec) / 1000000.0));

	return (0);
}
