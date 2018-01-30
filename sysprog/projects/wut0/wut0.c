//////////////////////////////////////////////////////
//                 wut0
//          Christian Cattell
//         sysprog - spring2018
//////////////////////////////////////////////////////
// Objective:
// 		Replicate functionality of UNIX function head 
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv)
{
	FILE *fp;  // Open the file designated by argv[1]
	fp              = fopen(argv[1], "r");
	
	int linesWanted; // Checking if we specify how many lines we want
	if (argv[2] == NULL)
		linesWanted = 10;
	else
		linesWanted = atoi(argv[2]); // How many lines we want? Int because atoi wants int
	
	char character;       // Value to store value at file pointer
	char lineCount  = 0;  // How many lines we got?


	do   // Either reach the end of the file or end of line 10
	{	
		character = fgetc(fp); // Read character from fp and put it in character 
		if (character == EOF)
		{
			fclose(fp);        // Check to see if we reached EOF before line 10
			return(0);
		}
	
		putchar(character);    // Write character to stdout

		if (character == 10)   // 10 == ASCII newline, is this the current char?
		{
			lineCount++;       // Tick lineCount up    

			if (lineCount == linesWanted) // Have we reached our goal?
			{
				fclose(fp);
				return(0);      // Then end program
			}
		}
	
	} while (1); // Previously while character != EOF but scrapped that for if statement
		         // inside loop to avoid printing ending garbage value, left it as a do while bc why not

	fclose(fp); // Just in case something doesnt go right
	return(0);  // but we shouldnt reach this 
}
