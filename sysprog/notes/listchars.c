#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c = 0;
	int n = 0;

	while ((c = getchar()) != 'Q')
		fprintf(stdout, "char %3d is '%c' code %d\n", n++, c, c);


	return (0);
}
