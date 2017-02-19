#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
	//start timer
	clock_t start = clock();

	int x = 0;
	//main loop, runs for each entered value
	for (x = 1; x < argc; x++)
	{
		//print value of input
		fprintf(stdout, "%s\n", argv[x]);
		
		int input = atoi (argv[x]);
//		fprintf(stdout, "%d\n", input);
		
		int y = 0;
		for (y = 2; y < input; y++)
		{
			//fprintf(stdout, "%d\n", y);
			int pCheck = (input % y);
			fprintf(stdout, "%d %c %d = %d\n", input, '%',  y, pCheck);	
		}
	
	}
	
	clock_t end = clock();
	long double timeTaken = ((end - start) / CLOCKS_PER_SEC);
	fprintf(stdout, "Time taken: %Lf seconds\n", timeTaken );

	return (0);
}

