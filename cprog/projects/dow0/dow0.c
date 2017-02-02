#include <stdio.h>
#include <stdlib.h>


int main ()
{

	/* define first short int, where the input year will be stored */
	unsigned short inputYear;

	fprintf(stderr, "Which year: ");
	fscanf(stdin, "%hu", &inputYear);
		if (inputYear <= 1999 || inputYear >= 2100)
		{
			fprintf(stdout, "Input must be in 21st century\n");
			exit(1);
		}

	unsigned short nYear = (inputYear % 2000);
	unsigned short qYear = ((nYear * .1) + (nYear * .1) + (nYear * .05));
	unsigned short nqYear = (nYear + qYear);
	unsigned short multiple = (nqYear / 7);

	unsigned short dayValue = ((nqYear) - (multiple * 7));
	switch (dayValue)
	{
		case 1:
			fprintf(stdout, "Monday\n");
			break;
		case 2:
			fprintf(stdout, "Tuesday\n");
			break;
		case 3:
			fprintf(stdout, "Wednesday\n");
			break;
		case 4:
			fprintf(stdout, "Thursday\n");
			break;
		case 5:
			fprintf(stdout, "Friday\n");
			break;
		case 6:
			fprintf(stdout, "Saturday\n");
			break;
		default:
			fprintf(stdout, "Sunday\n");
			break;
	}
/* figure out how to account for leap years */





	fprintf(stdout, "%hu\n", inputYear);
	fprintf(stdout, "%hu\n", nYear);
	fprintf(stdout, "%hu\n", qYear);
	fprintf(stdout, "%hu\n", nqYear);
	fprintf(stdout, "%hu\n", multiple);
	fprintf(stdout, "%hu\n", dayValue);



	return (0);
}
