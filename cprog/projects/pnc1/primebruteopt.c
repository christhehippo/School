#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
	//variables
	int x, y, pCheck, show;
	//convert string input to int
	int max =  atoi(argv[1]);	
	//timer stuff
	struct timeval time_start; //starting time
	struct timeval time_end;   //ending time

	//verify correct number of args
	if (argc < 2)
	{
		fprintf(stderr, "Not enough arguments!\n");
		exit(1);
	}
	
	//start timer
	gettimeofday(&time_start, 0);
	//include 2 to comp for removing even numbers
	//fprintf(stdout, "2 ");

	//main loop, runs for all numbers in range 2 - max(argv[1])	
	for (x = 2; x <= max; x++)
	{
		//show determines if a number will be printed
		show = 0;	
		pCheck = 0;
		//next loop, takes value x and checks to see if it is prime
		for (y = 2; y < x; y++)
		{	
			//pCheck should execute x-2 times if prime, break at first sign of composite 
			pCheck = (x % y);
			//if a number is not prime, break	
			if (pCheck != 0)
			{
				++show;	
			}
			else
			{
				break;
			}
		}
		//if a number passed the prime test, show will be equal to x-2
		if (show == (x - 2)) 
		{
			fprintf(stdout, "%d ", x);
		}
	
	}

		
	

	//new line when loop is done
	fprintf(stdout, "\n");
	//end timer	
	gettimeofday(&time_end, 0);
	//display runtime
	fprintf(stderr, "%10.6lf\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));

	return (0);
}

