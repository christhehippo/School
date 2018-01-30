///////////////////////////////////////////////////////////
//			  		   primeregbs.c						 //
//              		comporg							 //
//        		 	Christian Cattell					 //
//compile: gcc -std=c99 -Wall -lm -o primereg primereg.c //
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int main (int argc, char **argv)
{

/////////////////Time things////////////////////////
	struct timeval time_start; // starting time
	struct timeval time_end;   // ending time

	gettimeofday(&time_start, 0); // start timer
////////////////////////////////////////////////////

	
///////////////Variables////////////////////////////		
	int input  	   = atoi(argv[1]); // user input
	int testNum    = 3;      // value to test
	int divisor    = 2;		 // divisor for p checking
	int remainder  = 0;		
	int primeCount = 1;		 // counter for ending loopA
	int primeCheck = 0;
	int    root    = 0;
////////////////////////////////////////////////////


//////////////Find primes///////////////////////////

	fprintf(stderr, "2 "); // skipping 2
	
	for (testNum = 3; primeCount <= input; testNum++)
	{
		root = sqrt(testNum);
		for (divisor = 2; divisor <= root; divisor++)
		{
			remainder = testNum % divisor;
			if (remainder == 0)
			{
				primeCheck++;
				break;
			}
		}

		if (primeCheck == 0)
		{
			fprintf(stderr, "%d ", testNum);
			primeCount++;
		}
		primeCheck = 0;		
	}
	
	fprintf(stderr, "\n"); // new line
////////////////////////////////////////////////////	


/////////////Ending time////////////////////////////
	gettimeofday(&time_end, 0);
	fprintf(stdout, "%8.4lf\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec)/1000000.0));
////////////////////////////////////////////////////


		

	return (0);
}

//////////////////////////////////////////////////////////
// 	Objective:
//		Calculating prime numbers, breaking on finding prime
//		only checking up to sqrt of number
//////////////////////////////////////////////////////////

