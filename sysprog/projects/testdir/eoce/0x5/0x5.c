//////////////////////////////////////////////
//			0x6
//	range based primeregb ft. kids
//	argv[1] = pid num, [2] = start, [3] = end
//						or omit 3 and 2 is end

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

int main (int argc, char **argv)
{
//////////// VAR /////////////////////////////////
	struct timeval time_start;
	struct timeval time_end;
	
	gettimeofday(&time_start, 0);

	int    index   = 0; // looper
	int    inStart = 2; // start popit
	int    inEnd   = 0; // end point 
	int    toDo    = 0;
	int    numpids = atoi(argv[1]);
	int    start   = 0; // where to start for kid
	int    stop    = 0; // where to stop
	int    rank    = 0; // kid rank
	int    div     = 0; // divisor
	char   fn [10];
	char   buf[10];
	char   fc [255];
	FILE  *fp;
//	int    test    = 0; // num to test
	pid_t *pidlist = NULL; // pid stuff
///////////// ERR ////////////////////////////////
	if (argc <= 2)
	{
		fprintf(stderr, "Gimme start/end and child count.\n");
		exit(1);
	}
	else if (argc == 3)
	{
		inEnd = atoi(argv[2]);	
	}
	else if (argc == 4)
	{
		inStart = atoi(argv[2]);
		inEnd   = atoi(argv[3]);
	}
//////////////// ASSIGN //////////////////////////
	//allocate pidlist arrau
	pidlist = (pid_t *) malloc(sizeof(pid_t) * numpids);

	// spawn children 
	pidlist[0] = getpid(); // parent pid
	for (index = 1; index < numpids; index++)
	{
		// getting range for each child
		toDo  = ((inEnd - inStart) + 1) / (numpids - 1); // number to do "each"

		start = inStart + (toDo * (index -1));
		
		stop  = start + toDo - 1;
	
		// odd leftovers
		if ((index + 1) == numpids)
		{
			if ((((inEnd - inStart) + 1) % (numpids - 1)) != 0)
			{
				stop = stop + (((inEnd - inStart) + 1) % (numpids - 1));
			}
		}

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

///	if (rank > 0)
//	{
//		fprintf(stdout, "child %d: %d - %d\n", rank, start, stop);
//	}
//	
////////////////// PRIME CALC ////////////////////
//	FILE 
	if (rank == 0)
	{
		for (index = 1; index < numpids; index++)
		{
			if (index == 1)
			{
				if (inStart == 2)
					fprintf(stdout, "2 ");
			}
			wait(NULL);	
			sprintf(fn, "%d", index);	// fc - file contents
			fp = fopen(fn, "r");		// fp - file pointer
			fgets(fc, sizeof(fc), fp);	// fn - file name
			fprintf(stdout, "%s", fc);
		
			if ((index + 1) == numpids)
			{
				fprintf(stdout, "\n");
				gettimeofday(&time_end, 0);
				fprintf(stdout, "%8.4f\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec)/1000000.0));
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
//					fprintf(stdout, "child %d: %d ",rank, start);
					
				}
			}
			start++;
		}
		fclose(fp);
	}
	return(0);
}	
