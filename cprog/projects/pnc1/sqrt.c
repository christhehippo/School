#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)
{

	int x, sq;
	int input = atoi(argv[1]);
	
//	fprintf(stdout, "input: %d\n", input);
	for (x=1; x <= input; x++)
	{
		sq = sqrt(x);
		fprintf(stdout, "[%2d] %-3d\n", sq, x);
	}
	



return (0);

}
