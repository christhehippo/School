#include <stdio.h>
#include <stdlib.h>


int main ()
{

	/* define first short int, where the input year will be stored */
	unsigned short inputYear;

	fprintf(stderr, "Which year: ");
	fscanf(stdin, "%hu", &inputYear);
		if (inputYear < 95)
		{
			fprintf(stdout, "Input must be higher than 95\n");
			exit(1);
		}

	unsigned short nYear = (inputYear % 100);
	unsigned short quarternYear = ((nYear * .1) + (nYear * .1) + (nYear * .05));
	unsigned short 












	fprintf(stdout, "%hu\n", inputYear);
	fprintf(stdout, "%hu\n", nYear);
	fprintf(stdout, "%hu\n", quarternYear);
	return (0);
}
