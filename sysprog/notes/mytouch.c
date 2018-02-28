#!/usr/bin/tcc -run 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int index 	 = 1;
	int fd		 = 0;

	if (argc    == 1)
	{
		fprintf(stderr, "ERROR: missing operand. Gimmeh dirs\n");
		exit (1);
	}

	while (index < argc)
	{
		fd		 = open (argv[index], O_RDONLY|O_CREAT, 0600);
		index	 = index + 1;
		close (fd);
		
		if (fd == -1)
		{
			perror("[main]");
			exit (2);
		}
	}
	

	return (0);
}
