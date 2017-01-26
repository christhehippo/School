/* sof0 Project for C/C++ class */
/* Christian Cattell | ccattell | ccattell@corning-cc.edu */


/* imports libraray stdio.h */
#include <stdio.h>



/*Starts the program. */
int main() 
{
	/* Initializes and creates memory addresses for the variables used in the program. The scope of these variables is everything in intMain. */
	unsigned short userInput;
	unsigned short onesPlace; 
	unsigned short increment;


	/* "LOOP:" is where the program is sent if an unsupported value is entered. Prompts user to enter their value with instructions. */
	LOOP: printf ("This program calculates the square root of a number ending in 5, up to 955. Enter a a number ending in 5:\n"); 
	
	/* scanf takes the user entered value and sets the value of the short int userInput to that collected value. */
	scanf ("%d", &userInput);
	
	/* If the value of userInput is above 995 OR below 5, then the body of this loop will be executed. The body prints the error message, then has the program go back to the above user prompt. */
	if (userInput > 995 || userInput < 5) 
	{
		/* Tells the system to print the following string, given that one of the conditions in the if statement is true. */
		printf ("Invalid response, try again.(MIN:5 MAX:955, NO DECIMALS)\n");

		/* Tells the program to go back to the step labeled "LOOP" and continue on from there. */
		goto LOOP;

	}



	return (0); 		


}

