#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
//////////// VAR /////////////////////////////////
	int    index   = 0; // looper
	int    range   = atoi(argv[1]); // max number to go to
	int    numpids = atoi(argv[2]) + 1; // number of kids + 1
	int    start   = 0; // where to start
	int    stop    = 0; // where to stop
	int    rank    = 0; // kid rank
	int    div     = 0; // divisor
	char   fn [10];
	char   buf[10];
	FILE  *fp;
//	int    test    = 0; // num to test
	pid_t *pidlist = NULL; // pid stuff
///////////// ERR ////////////////////////////////
	if (argc < 2)
	{
		fprintf(stderr, "Provide prime count and child count.\n");
		exit(1);
	}
	if (argc < 3)
	{
		fprintf(stderr, "Provide child count.\n");
		exit(2);
	}
//////////////// ASSIGN //////////////////////////
	//allocate pidlist arrau
	pidlist = (pid_t *) malloc(sizeof(pid_t) * numpids);

	// spawn children 
	pidlist[0] = getpid(); // parent pid
	for (index = 1; index < numpids; index++)
	{
		// getting range for each child
		start = ((range / (numpids - 1)) * (index - 1));
		
		stop  = (start + (range / (numpids - 1)) - 1);
		
		//fork it 
		pidlist[index]       = fork();
		if (pidlist[index] == 0)
		{	// if child then rank it by index
			rank            = index;
			break;
		}
		else if (pidlist[index] == -1)
		{	// if error then bye
			fprintf(stderr, "ERROR spawning child\n");
			exit(3);
		}
	}
/*
	if (rank > 0)
	{
		fprintf(stdout, "child %d: %d - %d\n", rank, start, stop);
	}
*/	
////////////////// PRIME CALC ////////////////////
//	FILE 
	if (rank == 0)
	{
		for (index = 1; index < numpids; index++)
		{
			wait(NULL);
			if ((index + 1) == numpids)
			{
				fprintf(stdout, "2 ");

			}
		}
	}
	else
	{
		sprintf(fn, "%d", rank);
		fp = fopen(fn, "w");
		
		while (start <= stop)
		{
			for (div = 2; div < start; div++)
			{
				if ((start % div) == 0)
				{
					break;
				}
				if (div + 1 == start)
				{
					// write to file
					sprintf(buf, "%d ", start);
					fputs(buf, fp);
					fprintf(stdout, "child %d: %d ",rank, start);
					
				}
			}
			start++;
		}
		fclose(fp);
	}
	printf("\n");
	return(0);
}	
