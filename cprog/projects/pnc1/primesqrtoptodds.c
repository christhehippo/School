#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main (int argc, char **argv)
{
	//verify correct number of args
	if (argc < 2)
	{
		fprintf(stderr, "Not enough arguments!\n");
		exit(1);
	}	

	//variables
	int x, y, show;
	int square = 3;
	//convert string input to int
	int max =  atoi(argv[1]);	
	//timer stuff
	struct timeval time_start; //starting time
	struct timeval time_end;   //ending time


	//start timer
	gettimeofday(&time_start, 0);
	//include 2 to comp for removing even numbers
	fprintf(stdout, "2 3 ");

	//main loop, runs for all numbers in range 2 - max(argv[1])	
	for (x = 5; x <= max; x = x + 2)
	{		
		//removed if statements, replace with algorithm to 
		//check when x = the sqaure root of 1+square
		square = square + (1 * (x / ((square + 1) * (square + 1))));	
				
		for (y = 3; y <= square; y = y + 2)
		{	
			
			show = x % y;

			if (show == 0)
			{
				break;
			}

			
		}
		// when y loop ends early, show = 0
		if (show != 0) 
		{
			fprintf(stdout, "%d ", x);
			
		}
		
	}
	
	//end timer	
	gettimeofday(&time_end, 0);
	//new line when loop is done
	fprintf(stdout, "\n");
	//display runtime
	fprintf(stderr, "%10.6lf\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));

	return (0);
}

