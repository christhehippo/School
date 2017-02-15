#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	short int x = 0;

	fprintf(stdout, "This program (%s) was run with %d arguments\n", *(argv+0), argc);
	//argv[0]
	fprintf(stdout, "Those arguements are: \n");
	for (x = 0; x < argc; x++)
	{
		fprintf(stdout, "*(argv+%hd): %s\n", x, *(argv+x));
	}
	return (0);

}
