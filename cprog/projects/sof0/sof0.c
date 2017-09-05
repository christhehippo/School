/* sof0 by Christian Cattell */
/* for cscs1320 fall 2017 */

#include <stdio.h>

int main ()
{
	//variable for user input
	int userInput;
	//store the five here
	int fivesPlace;
	// where the 25 will go
	int rightOutput;
	//remaining digits go here
	int increment;
	//the other value that is calculated goes here
	int leftOutput;

	//collecting the user input
	fprintf(stderr, "Enter value: ");
	fscanf(stdin, "%d", &userInput);
	fprintf(stderr, "%-3d x %-3d = ", userInput, userInput);
	
	//math for isolating left digits	
	increment = userInput / 10;
//	fprintf(stderr, "\n %d\n", leftOutput); /* test tool */
	
	//calculating left side output
	leftOutput = increment * (increment + 1);
//	fprintf(stderr, "\n %d \n", leftOutput); /* test tool */

	//calculating right side output
	fivesPlace = userInput - (increment * 10);
	rightOutput = fivesPlace * fivesPlace;
//	fprintf(stderr, "\n %d \n", rightOutput); /* test tool */

	fprintf(stdout, "%4d%d\n", leftOutput, rightOutput);


	return(0);
}
