#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
	//variables
	//int x, y, pCheck, show;
	//convert string input to int
	//int max =  atoi(argv[1]);	
	//char* p;
	//int max = strtol(argv[1], &p, 10);
	//int z[max/2] = {0};
	//int number = 0;
	//z[0] = 2;
	//timer stuff
	struct timeval time_start; //starting time
	struct timeval time_end;   //ending time

	//verify correct number of args
	if (argc < 2)
	{
		fprintf(stderr, "Not enough arguments!\n");
		exit(1);
	}
	//variables
	int x, y, pCheck, show;
	//convert string input to int
	//int max =  atoi(argv[1]);	
	char* p;
	int max = strtol(argv[1], &p, 10);
	fprintf(stdout, "%d", max);	 
	int z[max];
	for (x = 0; x <= max; x++)
	{
		z[x] = 0;
	}

	int number = 0;
	z[0] = 2;
	
	//start timer
	gettimeofday(&time_start, 0);
	//print 2 to compensate for 2's removal from loop	
	fprintf(stdout, "2 ");

	//main loop, runs for all numbers in range 2 - max(argv[1])	
	for (x = 3; x <= max; x = x + 2)
	{
		//fprintf(stdout, "x = %d ", x);
		show = 0;	
		//next loop, takes value x and checks to see if it is prime
		
		
		for (y = 3; y <= x; y + 2)
		{
			pCheck = (x % y);
			//if a number is not prime, break
			//fprintf(stdout, "y = %d ", y);
			if (pCheck == 0 && x != 3)
 			{
				break;	
			}
			else
			{
				++show;
			}
		}
		//if a number passed the prime test, show will be equal to x-2
		if (show == (x-1)/2) 
		{
			fprintf(stdout, "%d ", x);
			number++;
			z[number] = x;
		}
	
	}

	//for (x = 0; x <= number; x++)
	//{
	//	fprintf(stdout, "%d ", z[x]);
	//}
	//new line when loop is done
	//fprintf(stdout, "\n");
	//end timer	
	gettimeofday(&time_end, 0);
	//display runtime
	for (x = 0; x <= number; x++)
	{
		fprintf(stdout, "%d ", z[x]);
	}
	fprintf(stdout, "\n");
	fprintf(stderr, "%10.6lf\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));

	return (0);
}

