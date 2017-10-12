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
	unsigned char digitCount, isoFill;

	fprintf(stderr, "Enter value: "); 	  //Obtain user input
	fscanf(stdin, "%u", &input);

	digitLoop = input;					  //Getting number of input digits
	while (digitLoop != 0) 				  //This is used for input array size
	{
		digitCount++;
		digitLoop = digitLoop / 10;
		fprintf(stdout, "digitLoop: %u\n", digitLoop);
	}
	

	fprintf(stdout, "digitCount: %u\n", digitCount);


	unsigned char isoInput[digitCount];	  //Create array of the input

	isoFill = digitCount;
	while (isoFill > 0)
	{
		isoInput[isoFill] = (unsigned char)(input % 10); //Gives values to 1-N in array
		input = input / 10;;
		fprintf(stdout, "isoInput[%u] is: %u\n", isoFill, isoInput[isoFill]);
		isoFill--;
	}
	
	unsigned char initialSpace = 9 - digitCount;
	fprintf(stdout, "%*u\n", initialSpace, isoInput[1]); //Variable spacing for input
//	fprintf(stdout, "digitCount: %u\n", digitCount);
	

	

	return (0);
}





