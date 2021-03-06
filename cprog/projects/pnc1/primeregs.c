/////////////////////////////////////////////////////////////////////////////////////
// Primeregs.c - sqrt() function to calculate primality up to that root
// 
//---REQUIRES 2 ARGUMENTS, ACCEPTS UP TO 4---
//	- argument 1 - number of primes to calculate; if 0 stop calculations at upper bound
//	- argument 2 - set to 1 always, no functionality yet
//  - arguemnt 3 (optional) - lower bound, what number to begin calculations on, if left blank it is 2
//  - argument 4 (optional) - upper bound, what number to stop calculations at
//
//	TO COMPILE: gcc -Wall -o primereg primereg.c
//  TO RUN: ./primereg [number] [number] [number(optional)] [number(optional)]
//
/////////////////////////////////////////////////////////////////////////////////////
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
	int lowerBound = 0;
    int upperBound = 0;
	//check if bounds were supplied by user, if not, use the default values.
	if (argc == 5)
	{
		lowerBound = atoi(argv[3]);
		upperBound = atoi(argv[4]);
		if (upperBound == 0)
		{
			upperBound = 2147483647;
		}
		
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
	int forOne = 0; 		// first loop incremental value
	int forTwo = 0; 		// second loop incremental value
	int primeCheck = 0; // used after calculations to determine if a number is prime
	int primeCount = 0; // each time a number comes out prime, increases by one
	int sqForOne = 0;
	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	
	if (lowerBound == 2)
	{
		lowerBound = 4;
		fprintf(stdout, "2 3 ");
		quanCheck = quanCheck - 2;
	}
	if (lowerBound == 3)
	{
		lowerBound = 4;
		fprintf(stdout, "3 ");
		quanCheck = quanCheck - 2;
	}
	for (forOne = lowerBound; forOne <= upperBound; forOne++)
	{
		sqForOne = sqrt(forOne);
//		fprintf(stdout, "sqForOne: %d ", sqForOne);
		//start second loop at 2, divided into forOne, then increase
		for (forTwo = 2; forTwo <= sqForOne; forTwo++)
		{
			//check if loop is done
			if (forOne % forTwo == 0)
			{
				primeCheck++;
			}
			if (forTwo == sqForOne && primeCheck == 0)
			{
				fprintf(stdout, "%d ", forOne);
				primeCount++;
				break;
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
