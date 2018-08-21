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
#include <string.h>

int main (int argc, char **argv)
{
	struct timeval time_start;
	struct timeval time_end;
	gettimeofday(&time_start, 0);

//////////// VAR /////////////////////////////////
	int    pc      = 1; // prime count
	int    index   = 0; // looper
	int    index2  = 0;
//	int    inStart = 2; // start popit
	int    toDo    = 0;
	int    numpids = atoi(argv[1]);
	int    pnum    = atoi(argv[2]);
	int    max     = 0; // number to check up to
	int    start   = 0; // where to start for kid
	int    stop    = 0; // where to stop
	int    rank    = 0; // kid rank
	int    div     = 0; // divisor
	char   fn [10];
	char   buf[10];
	char   fc [255];
	char   c;
	FILE  *fp;
//	int    test    = 0; // num to test
	pid_t *pidlist = NULL; // pid stuff
///////////// ERR ////////////////////////////////
	if (argc <= 2)
	{
		fprintf(stderr, "Gimme prime num and child count.\n");
		exit(1);
	}
//////////////// ASSIGN //////////////////////////
	//allocate pidlist arrau
	pidlist = (pid_t *) malloc(sizeof(pid_t) * numpids);

	// spawn children 
	pidlist[0] = getpid(); // parent pid
	for (index = 1; index < numpids; index++)
	{
		// getting range for each child
		max   = pnum * 12;
		toDo  = (max / (numpids - 1));
//		printf("max: %d  toDo: %d\n", max, toDo);	
		start = 2 + (toDo * (index - 1));
		stop  = 2 + (toDo * index);
		
		// odd leftovers
		if ((index + 1) == numpids)
		{
			if ((((max - 2) + 1) % (numpids - 1)) != 0)
			{
				stop = stop + (((max - 2) + 1) % (numpids - 1));
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

//	if (rank > 0)
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
				fprintf(stdout, "2 ");
			}
			wait(NULL);	
			sprintf(fn, "%d", index);	// fc - file contents
			fp = fopen(fn, "r");		// fp - file pointer
			fgets(fc, sizeof(fc), fp);	// fn - file name
			for (index2 = 0; index2 < 10000000; index2++)
			{
				c = fc[index2];
				if (c == EOF)
				{
					break;
				}
				fprintf(stdout, "%c", c);
				if (c == ' ')
				{
					pc++; // pc - primecount
					if (pc == pnum)
					{
						fprintf(stdout, "\n");
						fclose(fp);
						gettimeofday(&time_end, 0);
						fprintf(stdout, "%8.4f\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec)/1000000.0));
						return(0);
					}
				}
			}
			fclose(fp);
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
