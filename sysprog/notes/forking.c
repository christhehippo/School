#!/usr/bin/tcc -run
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t  parent  = getpid();
	pid_t  me[8];
	int rank  = 1;
	int index = 0;

	for (index = 0; index < 8; index++)
	{
		if (me        == 0)
		{
			dprintf (1, "CHILD: I am the child, my PID is %lu\n", getpid());
			dprintf (1, "CHILD: My parent's PID is: %lu\n", parent);
			dprintf (1, "CHILD: My rankis: %d\n", rank);

			sleep (60);

		}
		else
		{
			me[rank]  = fork();
			rank++;	
		}
	}

	if (me != 0)
	{
		dprintf (1, "PARENT: I am the parent, my PID is: %lu\n", parent);
		dprintf (1, "PARENT: My child's PIDs are: ");
		for (index = 0; index < 8; index ++)
			dprintf (1, "%lu ", me[index]);
		dprintf (1, "\nPress ENTER to exit\n");
		getchar ();
	}	

	return (0);
}
