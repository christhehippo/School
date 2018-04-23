////////////////////////////////////////////
//		0x1_process_fork
// program to show understanding of forking
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int index      = 0;
	int rank       = 0; 
	int numpids    = 0;
	if (argc < 2)      // check for provided arg
	{
		numpids    = 11;
	}
	else
	{
		numpids    = atoi(argv[1]);
	}

	pid_t *pidlist = (pid_t *) malloc(sizeof(pid_t)*numpids);
	pidlist[0]     = getpid(); // parent pid
		
	for (index = 1; index < numpids; index++)
	{
		pidlist[index]      = fork();  // spawn child
		if (pidlist[index] == 0)
		{
			rank = index;
			break;
		}
		else if (pidlist[index] ==  -1)
		{
			fprintf(stderr, "ERROR spawning child.\n");
		}
	}
	if (rank > 0)  // go here if child
	{
		fprintf(stdout, "Child #%2d's pid is: %d\n", rank, pidlist[rank]);
	}
	else  // go here if parent
	{
		fprintf(stdout, "Parent's pid is : %d\n", pidlist[rank]);
		for (index = 1; index < numpids; index ++)
		{
			wait(NULL);
		}
	}


	


	return(0);
}


