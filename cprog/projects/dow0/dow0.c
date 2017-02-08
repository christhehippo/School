/*CHRISTIAN CATTELL CPROG*/
/* dow0 week3 project*/



#include <stdio.h>
#include <stdlib.h>


int main ()
{

	/* define first short int, where the input year will be stored */
	unsigned short inputYear;

	fprintf(stderr, "Which year: ");
	fscanf(stdin, "%hu", &inputYear);
		/* if the input year doesnt fall within 21st cen, end program*/
		if (inputYear <= 1999 || inputYear >= 2100)
		{
			fprintf(stderr, "Input must be in 21st century\n");
			exit(1);
		}
	/* variables used in the steps to calculate the dayValue */

	unsigned short nYear = (inputYear % 2000);
	/* 25% of the last two digits of the input year */ 
	unsigned short qYear = ((nYear * .1) + (nYear * .1) + (nYear * .05));
	/* adds the 25% to the original value of last two characters */
	unsigned short nqYear;
	/* determines if the year is a leap year */
	if ((nYear % 4) == 0 && (inputYear != 2000)/* cheating to work around year 2000 messing up calculation */)
	{
		nqYear = (nYear + (qYear - 1)); /* leap year value */
	}
	else
	{
		nqYear = (nYear + qYear); /* else not leap year value */
	}
	unsigned short multiple = (nqYear / 7);
	/* trims off the remainder to get the highest 7 multiple */
	unsigned short multipleL = (multiple * 7);
	/* this value is used to determine the day of Jan 1 */
	unsigned short dayValue = ((nqYear) - (multipleL));
	/* switch case to print the day that corresponds to dayValue 0-7 */
	fprintf(stdout,"January 1st, %hu falls on: ", inputYear);
	switch (dayValue)
	{
		case 0:
			fprintf(stdout, "Saturday\n");
			break;
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
		case 7:
			fprintf(stdout, "Sunday\n");
			break;
	}
/* used to test program while designing it:

	fprintf(stdout, "%hu\n", inputYear);
	fprintf(stdout, "%hu\n", nYear);
	fprintf(stdout, "%hu\n", qYear);
	fprintf(stdout, "%hu\n", nqYear);
	fprintf(stdout, "%hu\n", multiple);
	fprintf(stdout, "%hu\n", multipleL);
	fprintf(stdout, "%hu\n", dayValue);
*/

	/*end*/
	return (0);
}
