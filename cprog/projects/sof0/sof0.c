/* sof0 Project for C/C++ class */
/* Christian Cattell | ccattell | ccattell@corning-cc.edu */


/* imports libraray stdio.h */
#include <stdio.h>
#include <stdlib.h>


/*Starts the program. */
int main() 
{
	/* Where the user input will be stored. */
	unsigned short userInput; 
	
	
 	/*  "LOOP:" is where the program is sent if an unsupported value is entered. Prompts user to enter their value with instructions. */
	LOOP:fprintf(stderr, "Enter value: "); 
	
	/* scanf takes the user entered value and sets the value of the short int userInput to that collected value. */
	fscanf(stdin, "%hu", &userInput); 
	/* If the value of userInput is above 995 OR below 5, then the body of this loop will be executed. The body prints the error message, then has the program go back to the above user prompt. */
	if (userInput > 995 | userInput < 5 | userInput % 5 > 0)
	{
		
		fprintf (stdout, "Invalid response, try again.(MIN:5 MAX:955, NO DECIMALS)\n");

		
		goto LOOP; 

		
	}
	
	/* Define variables used in calculating and displying expected output. */	
	unsigned short n = userInput - 5;
	unsigned short inc =  n / 10;
	unsigned short half1 =  inc * (inc + 1); 
	unsigned short x = userInput - n;
	unsigned short half2 = x * x;



	/*I used the below code for debug*/
	/* printf ("%hu, %hu, %hu, %hu\n", userInput, inc, half1, half2);*/
	fprintf(stderr, "%-3hu x %-3hu = ", userInput, userInput);
	fprintf(stdout, "%4hu%2hu\n", half1, half2);
	

 


	return (0); 		


}

