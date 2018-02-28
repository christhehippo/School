#!/usr/bin/tcc -run 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

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
		ret		 = mkdir (argv[index], 0700);
		index	 = index + 1;

		if (ret != 0 )
		{
			perror("[main]");
			exit (2);
		}
	}

	return (0);
}
