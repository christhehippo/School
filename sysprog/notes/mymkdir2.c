#!/usr/bin/tcc -run 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int index 	 = 1;
	int ret		 = 0;

	if (argc    == 1)
	{
		fprintf(stderr, "ERROR: missing operand. Gimmeh dirs\n");
		exit (1);
	}

	while (index < argc)
	{
		ret		 = open (argv[index], 0_CREATIO_DIRECTORY, 0700);
		index	 = index + 1;

		if (ret != 0 )
		{
			perror("[main]");
			exit (2);
		}
	}

	return (0);
}
