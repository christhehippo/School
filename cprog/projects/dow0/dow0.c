/* dow0 by Christian Cattell for cscs1320 */

#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int userInput;
	int rightHalf;
	int halfHalf;
	int addedQuarter;
	int dayValue;
//	I push the slashes for my variable test tools to the left to
//	add contrast from comments	


	//store input year as int
	fprintf(stderr, "Which year: ");
	fscanf(stdin, "%d", &userInput);

	//isolate the right two digits by mod 2000, only works 2000-2099
	rightHalf = userInput % 2000;
//	fprintf(stderr, "%d\n", rightHalf);
	
	//take the half of a half
	halfHalf = ((rightHalf / 2) / 2);
//	fprintf(stderr, "%d\n", halfHalf);

	addedQuarter = rightHalf + halfHalf;
//	fprintf(stderr, "%d\n", addedQuarter);

	//if statement to check for leap year
	if ((rightHalf % 4) == 0)
	{
		dayValue = (addedQuarter % 7) - 1;
	}
	else
	{
		dayValue = addedQuarter % 7;
	}
//	fprintf(stderr, "%d\n", dayValue);

	//first part of the required output goes to stderr
	fprintf(stderr, "January 1st, %d falls on: ", userInput);
	
	//this take the calculated value and selects the correct day and
	//prints to stdout
	if (dayValue == 1)
	{
		fprintf(stdout, "Monday\n");
	}
	if (dayValue == 2)
	{
		fprintf(stdout, "Tuesday\n");
	}
	if (dayValue == 3)
	{
		fprintf(stdout, "Wednesday\n");
	}
	if (dayValue == 4)
	{
		fprintf(stdout, "Thursday\n");
	}
	if (dayValue == 5)
	{
		fprintf(stdout, "Friday\n");
	}
	if (dayValue == 6 || dayValue == -1) // the -1 is there for the year 2000
	{									 // which otherwise wouldnt work
		fprintf(stdout, "Saturday\n");
	}
	if (dayValue == 0 || dayValue >= 7)
	{
		fprintf(stdout, "Sunday\n");
	}


	








	return (0);
}
