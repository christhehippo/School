#include <stdio.h>
#include <stdlib.h>


int main()
{
	int index = 33;
	char x = 33;


	for (index = 33; index < 256; index++)
	{
		fprintf(stdout, "%c   ", x);
		x++;
	}
	fprintf(stdout, "\n");


	 return (0);
}
