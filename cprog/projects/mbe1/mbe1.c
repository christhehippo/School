/////////////////////////////////////////////////////////////////////////
//							      MBE1								   //
//							Christian Cattell 						   //
//				    Compile: gcc -Wall -o mbe1 mbe1.c				   //
//				             Exectue: ./mbe1						   //
//																	   //
//																	   //
//																	   //
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>


int main()
{
	//Initial Variables
	unsigned int input, digitLoop;
	unsigned char digitCount, isoFill, initialSpace, isoPrint;

	fprintf(stderr, "Enter value: "); 	  //Obtain user input
	fscanf(stdin, "%u", &input);
	digitLoop = input;					  //Getting number of input digits
	for (digitLoop = input; digitLoop > 0; digitLoop = digitLoop / 10)  //This is used for input array size
	{
		digitCount++;
//		fprintf(stdout, "digitLoop: %hhu\n", digitLoop);
	}
	
//	fprintf(stdout, "digitCount: %u\n", digitCount);

	unsigned char isoInput[digitCount];	  //Create array with a size of the number of digits of input

	isoFill = digitCount;
	for (isoFill = digitCount; isoFill > 0; isoFill--)
	{
		isoInput[isoFill] = (unsigned char)(input % 10); //Gives values to 1-N in array
		input = input / 10;;
		fprintf(stdout, "isoInput[%hhu] is: %hhu\n", isoFill, isoInput[isoFill]);
	}
	
	initialSpace = 9 - digitCount; 						 //Adds this number of spaces,
	fprintf(stdout, "%*hhu", initialSpace, isoInput[1]); //changes based on input, supports up to 8.
	
////////////////////////////////////////////////////////////////
//					Breaks here
//
//	for (isoPrint = 2; isoPrint <= digitCount; isoPrint++)
//	{
//		fprintf(stdout, "%hhu", isoInput[isoPrint]);
//	}
///////////////////////////////////////////////////////////////	
	fprintf(stdout, "\n");	
	
	

	

	return (0);
}





