#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// arguments (optional):
// argv[1]: number of children
// argv[2]: range (number of values, from 0-(range-1))
//
int main(int argc, char **argv)
{
	int    numpids  = 3; // default # of processes: parent + 2 children
	int    range    = 1000;
	int    start    = 0;
	int    stop     = 0;
	int    index    = 0;
	int    rank     = 0;
	int    remain   = 0;
	int    addone   = 0;
	int    offset   = 0;
	int    unit     = 0;
	pid_t *pidlist  = NULL;

	if (argc       >  1)
	{
		numpids     = atoi (argv[1]);
		numpids     = numpids + 1; // include the parent
	}

	if (argc       >  2)
	{
		range       = atoi (argv[2]);
	}

	if (numpids    <  0)
	{
		fprintf (stderr, "ERROR: Must specify 0 or more child processes\n");
		exit (1);
	}

	if (range      <= 0)
	{
		fprintf (stderr, "ERROR: Non-existant range; must be > 0\n");
		exit (2);
	}

	// allocate our pidlist array
	pidlist = (pid_t *) malloc (sizeof (pid_t) * numpids);

	// calculate remainder
	remain          = range % (numpids - 1);

	unit			= range / (numpids -1);
	// calculate work unit size
//	unit          	= range % (numpids - 1);

	// spawn some children
	pidlist[0]              = getpid(); // record parent PID in pidlist array
	for (index = 1; index < numpids; index++)
	{
		// calculate the child's starting position
		start               = (range  / (numpids - 1)) * (index - 1) + offset;

		// divvy up the remainders until there are no more
		if (remain         >  0)
		{
			addone          = 1 + offset; // account for existing offset
			remain          = remain - 1;
			offset          = offset + 1;
		}

		// calculate the child's ending position (including remainder)
		stop                = start + unit + addone - 1;

		// spawn a child process
		pidlist[index]      = fork();
		if (pidlist[index] == 0)
		{
			rank            = index;
			break;
		}
		else if (pidlist[index] == -1)
		{
			fprintf (stderr, "ERROR spawning child\n");
			exit (3);
		}

		addone              = 0;
	}
	
	// do the deed (if child, display start and end values)
	if (rank               >  0)
	{
		// perform child work unit (display its sub-range)
		fprintf (stdout, "[child%2d] start: %4d, stop: %4d\n",
		                 (rank-1),   start,     stop);
	}
	else
	{
		for (index = 1; index < numpids; index++)
		{
			// wait for all the children to die
			wait(NULL);
		}
	}

	return (0);
}
