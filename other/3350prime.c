// input: as an integer such that n is greater than 3
// output: is "false" if the number is composite, "true" if prime in O(n^1/2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char ** argv)
{
	int i     = 0;
	int n     = atoi(*(argv+1));
	fprintf(stdout, "%d\n", n);


	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			fprintf(stdout, "false\n");
			return(1);
		}
	}

	fprintf(stdout, "true\n");

	return(0);
}
