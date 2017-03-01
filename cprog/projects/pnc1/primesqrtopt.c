#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main (int argc, char **argv)
{
	//variables
	int x, y, pCheck, show, sqPlusCheck, sqCheck;
	int square = 2;
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
	fprintf(stdout, "2 ");

	//main loop, runs for all numbers in range 2 - max(argv[1])	
	for (x = 3; x <= max; x++)
	{
		sqCheck = (square * square);
		sqPlusCheck = ((square + 1) * (square + 1));
//		fprintf(stdout, "square = %d, x = %d, sqCheck = %d\n", square, x, sqCheck);

//-------------------------------------------------------------------------------
//***I have included these if statements containing continue to skip calculating 
//***the squared sums of 2 through the square root of argv.
//-------------------------------------------------------------------------------

		//if x = square * square, it isnt prime, go to next value for x
		if (sqCheck == x)
		{
			continue;
		}
		//show determines if a number will be printed
		show = 0;	
		pCheck = 0;
		// if x has reached the next inc for square, square +1 and skip prime check loop	
		if (sqPlusCheck == x)
		{
			++square;
			continue;
		}
		//The values of square in the y loop match up with the values of square in 
		//primesqrt's calculation.
		for (y = 2; y <= square; y++)
		{	
//			fprintf(stdout, "x = %d y = %d\n", x, y);
			//pCheck should execute x-2 times if prime, break at first sign of composite 
			pCheck = (x % y);
			//if a number is not prime, break	
			if (pCheck != 0)
			{
				++show;	
			}
			else
			{
				show = 0;
				break;
			}
		}
		//if a number passed the prime test, show will be equal to x-2
		if (show > 0) 
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

