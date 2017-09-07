#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char **argv)
{
	fprintf(stdout, "%s was run with %u arguements\n", argv[0], argc);

	if (argc >= 2)
	{
		fprintf(stdout, "argv[1] is: %s\n", argv[1]);
		fprintf(stdout, "argv[1][2] is: '%c'\n", argv[1][2]);
	}
	if (argc >= 3)
	{
		fprintf(stdout, "argv[2] is: %s\n", argv[2]);
	}
	if (argc >= 4)
	{
		fprintf(stdout, "argv[3] is: %s\n", argv[3]);
	}
	if (argc >= 5)
	{
		fprintf(stdout, "argv[4] is: %s\n", argv[4]);
	}

	



	return(0);
}
