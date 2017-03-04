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
	int x, y, show, squareD;
	int square = 2;
	//convert string input to int
	int max =  atoi(argv[1]);	
	//timer stuff
	struct timeval time_start; //starting time
	struct timeval time_end;   //ending time


	//start timer
	gettimeofday(&time_start, 0);
	//include 2 to comp for removing even numbers
	fprintf(stdout, "2 ");

	//main loop, runs for all numbers in range 2 - max(argv[1])	
	for (x = 3; x <= max; x++)
	{		
		//removed if statements, replace with algorithm to 
		//check when x = the sqaure root of 1+square
		squareD = (square + 1) * (square + 1);	
		square = square + (1 * (x / squareD));
	
		for (y = 2; y <= square; y++)
		{	
			
			show = (x % y);
			if (show == 0)
			{
				break;
			}

			
		}
		//show default set to 1, if a number is shown to be comp, show is set to 0 and it isnt printed
		if (show != 0) 
		{
			fprintf(stdout, "%d ", x);
			show = 0;
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

