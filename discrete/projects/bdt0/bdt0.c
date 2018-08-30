#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	
////// File operations///////////////////////////////////////////
	if (argc < 2)
	{
		fprintf(stderr, "%s: no file provided.\n", argv[0]);
		exit(1);
	}

	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "%s: invalid file\n", argv[0]);
		exit(2);
	}
/////////////////////////////////////////////////////////////////
	
	
	

	fclose(fp);
	return(0);
}
