#!/usr/bin/tcc -run
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	pid_t   mypid   = 0;
	pid_t   myppid  = 0;

	mypid 			= getpid();
	myppid			= getppid();

	dprintf(1, "mypid:  %lu\n", mypid);
	dprintf(1, "myppid: %lu\n", myppid);
	dprintf(1, "Press ENTER to exit.\n");
	getchar();



	return (0);
}
