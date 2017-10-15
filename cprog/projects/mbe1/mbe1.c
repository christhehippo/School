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
	unsigned int input = 0, digitLoop = 0;
	unsigned char digitCount = 0, isoFill = 0, initialSpace = 0, isoPrint = 0, sumLoop = 0, carryDigit = 0;


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

	do
	{
		isoFill--;
		isoInput[isoFill] = (unsigned char)(input % 10); //Gives values to 1-N in array
		input = input / 10;
//		fprintf(stdout, "isoInput[%hhu] is: %hhu\n", isoFill, isoInput[isoFill]);
	}
	while (isoFill != 0);


	initialSpace = 9 - digitCount; 						 	 //Adds this number of spaces,
	fprintf(stdout, "%*hhu", initialSpace, isoInput[0]);     //changes based on input, supports up to 8
	
	for (isoPrint = 1; isoPrint < digitCount; isoPrint++)
	{
		fprintf(stdout, "%hhu", isoInput[isoPrint]);		 //Print the rest of the individual digits
	}
	
	
	fprintf(stdout, " x 11 = ");
	
	unsigned char calcSpace = 0;
	calcSpace = (11 - (digitCount + 1)) * 6;				 //Print the number of needed spaces for LINE ONE
	unsigned char calcSpaceLoop = 0;
	for (calcSpaceLoop = 0; calcSpaceLoop <=calcSpace; calcSpaceLoop++)
	{
		fprintf(stdout, " ");
	}
	
	unsigned char lineOneLoop = 0;

	for (lineOneLoop = 0; lineOneLoop < digitCount; lineOneLoop++)
	{
		if (lineOneLoop == 0)								//LINE ONE output
		{
			fprintf(stdout, "%3hhu   ", isoInput[lineOneLoop]);
			fprintf(stdout, "(%hhu+%hhu) ", isoInput[lineOneLoop], isoInput[lineOneLoop + 1]);
		}
		else if (lineOneLoop == digitCount - 1)
		{
			fprintf(stdout, "%3hhu   \n", isoInput[lineOneLoop]);
		}
		else 
		{
			fprintf(stdout, "(%hhu+%hhu) ", isoInput[lineOneLoop], isoInput[lineOneLoop + 1]);
		}
	}


	unsigned char sumArray[digitCount + 2];				     //Create array of the sums of digits
	sumArray[0] = 0; //Initializing the first two elements
	sumArray[digitCount + 1] = isoInput[digitCount - 1];
	sumArray[1] = isoInput[0];
	for (sumLoop = 2;sumLoop < digitCount + 1; sumLoop++)
	{
		sumArray[sumLoop] = (isoInput[sumLoop - 2] + isoInput[sumLoop - 1]);
	}
		
	fprintf(stdout, "              = ");
	for (calcSpaceLoop = 0; calcSpaceLoop <=calcSpace; calcSpaceLoop++)
	{
		fprintf(stdout, " ");
	}


	unsigned char lineTwoLoop = 1;							 //The first two lines will always be the same so do them outside
															 //the 'main' loop
	for (lineTwoLoop = 1; lineTwoLoop <= digitCount + 1; lineTwoLoop++)
	{
		fprintf(stdout, "%3hhu   ", sumArray[lineTwoLoop]);
	}
	fprintf(stdout, "\n");

	unsigned char carryArray[digitCount + 2];
	unsigned char carryLoop = digitCount + 2;
	unsigned char carryCount = 0;

	do
	{
		carryLoop--;
		if (sumArray[carryLoop] > 9)
		{
			carryArray[carryLoop] = 1;
			carryCount++;
		}
		else 
		{
			carryArray[carryLoop] = 0;
		}
		fprintf(stdout, "carryArray[%hhu]: %hhu\n", carryLoop, carryArray[carryLoop]);
	}while (carryLoop != 0);

	do
	{
		fprintf(stdout, "              = ");
		

	}while (carryCount != 0)
	

	return (0);
}





