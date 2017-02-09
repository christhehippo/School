#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uc;


int main (int argc, char **argv)
{

	uc size = 0;
	char x = 0;
	char y = 0;


	if (argc == 1)
	{
		size = 12;
	}
	else
	{
		size = (uc)atoi(argv[1]);
		
		if (size >= 20)
		{
			size = 20;	
		}
		else if (size < 2)
		{
			size = 2;
		}
	
	}
	
	for (x = 0; x <= size; x++)
	{
		fprintf(stdout, "%-3hhd ", x);
	}
	fprintf(stdout, "\n");

	for (y = 1; y <= size; y++)
	{
		fprintf(stdout, "%-3hhd ", y);	
		for (x = 1; x <= size; x++)
		{
			fprintf(stdout, "%-3hd ", (short int)(x*y));
		}
		fprintf(stdout, "\n");
	}

	return (0);
}
