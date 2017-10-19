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
	unsigned char digitCount = 0, isoFill = 0, initialSpace = 0, isoPrint = 0, sumLoop = 0;


	fprintf(stderr, "Enter value: "); 	  //Obtain user input
	fscanf(stdin, "%u", &input);
	

	digitLoop = input;					  //Getting number of input digits
	for (digitLoop = input; digitLoop > 0; digitLoop = digitLoop / 10)  //This is used for input array size
	{
		digitCount++;
//		fprintf(stderr, "digitLoop: %hhu\n", digitLoop);
	}
	
//	fprintf(stderr, "digitCount: %u\n", digitCount);

	unsigned char isoInput[digitCount];	  //Create array with a size of the number of digits of input

	isoFill = digitCount;

	do
	{
		isoFill--;
		isoInput[isoFill] = (unsigned char)(input % 10); //Gives values to 1-N in array
		input = input / 10;
//		fprintf(stderr, "isoInput[%hhu] is: %hhu\n", isoFill, isoInput[isoFill]);
	}
	while (isoFill != 0);


	initialSpace = 9 - digitCount; 						 	 //Adds this number of spaces,
	fprintf(stderr, "%*hhu", initialSpace, isoInput[0]);     //changes based on input, supports up to 8
	
	for (isoPrint = 1; isoPrint < digitCount; isoPrint++)
	{
		fprintf(stderr, "%hhu", isoInput[isoPrint]);		 //Print the rest of the individual digits
	}
	
	
	fprintf(stderr, " x 11 =");
	
	unsigned char calcSpace = 0;
	calcSpace = 60 - ((digitCount + 1) * 6);				 //Print the number of needed spaces for LINE ONE
	unsigned char calcSpaceLoop = 0;
	for (calcSpaceLoop = 0; calcSpaceLoop <=calcSpace; calcSpaceLoop++)
	{
		fprintf(stderr, " ");
	}
	
	unsigned char lineOneLoop = 0;

	for (lineOneLoop = 0; lineOneLoop < digitCount; lineOneLoop++)
	{
		if (lineOneLoop == 0)								//LINE ONE output
		{
			fprintf(stderr, "%3hhu   ", isoInput[lineOneLoop]);
			fprintf(stderr, "(%hhu+%hhu) ", isoInput[lineOneLoop], isoInput[lineOneLoop + 1]);
		}
		else if (lineOneLoop == digitCount - 1)
		{
			fprintf(stderr, "%3hhu   \n", isoInput[lineOneLoop]);
		}
		else 
		{
			fprintf(stderr, "(%hhu+%hhu) ", isoInput[lineOneLoop], isoInput[lineOneLoop + 1]);
		}
	}


	unsigned char sumArray[digitCount + 2];				     //Create array of the sums of digits
	sumArray[0] = 0; //Initializing the first two elements
	sumArray[digitCount + 1] = isoInput[digitCount - 1];
	sumArray[1] = isoInput[0];
	for (sumLoop = 2; sumLoop < digitCount + 1; sumLoop++)
	{
		sumArray[sumLoop] = (isoInput[sumLoop - 2] + isoInput[sumLoop - 1]);
	}

	fprintf(stderr, "              =");
	for (calcSpaceLoop = 0; calcSpaceLoop <=calcSpace; calcSpaceLoop++)
	{
		fprintf(stderr, " ");
	}


	unsigned char lineTwoLoop = 1;							 //The first two lines will always be the same so do them outside
															 //the 'main' loop
	for (lineTwoLoop = 1; lineTwoLoop <= digitCount + 1; lineTwoLoop++)
	{
		fprintf(stderr, "%3hhu   ", sumArray[lineTwoLoop]);
	}
	fprintf(stderr, "\n");

	unsigned char carryArray[digitCount + 2]; //I tried my best to keep the variables organized at the top
	unsigned char carryLoop = digitCount + 2; //but that actually seems like it would make the code more 
	unsigned char carryCount = 0;			  //confusing so I ended up giving up on that
	
	do										  		
	{
		carryLoop--;						  //Calculate if there will be initial carries
		if (sumArray[carryLoop] > 9)          //if not it skips MANY steps
		{
			carryArray[carryLoop] = 1;
			carryCount++;
		}
		else 
		{
			carryArray[carryLoop] = 0;   
		}
	}while (carryLoop != 0);

	if (carryCount != 0)                                            
	{
		carryCount = 0;
		unsigned char updateLoop = digitCount + 1;
		do
		{
			updateLoop--;
			sumArray[updateLoop] = sumArray[updateLoop] + carryArray[updateLoop + 1];
			carryArray[updateLoop] = 0;
			if (sumArray[updateLoop] > 9)       //Making sure the arrays carry and sum are 
			{									//are shifted around correctly
				sumArray[updateLoop] = sumArray[updateLoop] - 10;
				carryArray[updateLoop] = 1;
				carryCount++;
			}
		}while (updateLoop != 0);
		
		fprintf(stderr, "              =");
		unsigned char spaceVar = 60 - ((digitCount + 2) * 6);
		unsigned char spaceLoop = 0;
		for (spaceLoop = 0; spaceLoop < spaceVar + 1; spaceLoop++)  //spacing tool
		{
			fprintf(stderr, " ");
		}
		unsigned char lineLoop = 0;
		for (lineLoop = 0; lineLoop < digitCount + 2; lineLoop++)
		{
			if (lineLoop == 0)
			{
				fprintf(stderr, "      "); 		  //skip possible [0] element being > 0 for now

			}
			else if (lineLoop == digitCount + 1)
			{
				fprintf(stderr, "%3hhu   \n", sumArray[lineLoop]);
			}
//			else if (sumArray[lineLoop + 1] == )
//			{
//
//			}
			else
			{
				if (sumArray[lineLoop] == 0)
				{
					if (carryArray[lineLoop + 1] == 1)
					{ 
						fprintf(stderr, "(9+%hhu) ", carryArray[lineLoop + 1]); //0 - 1 isnt 9
					}															//account for this with if
					else
					{
						
						fprintf(stderr, "%3hhu   ", sumArray[lineLoop]);
					}
				}
				else if (sumArray[lineLoop + 1] == 0 && carryArray[lineLoop+2] == 1)
				{
					fprintf(stderr, "  %hhu   ", sumArray[lineLoop] - 1);
				}
				else
				{
					if (carryArray[lineLoop + 1] == 1) 	//The output is really just a lot of conditions
					{									//but if I did this without arrays it would be way more
						fprintf(stderr, "(%hhu+%hhu) ", sumArray[lineLoop] - 1, carryArray[lineLoop + 1]);
					}
					else
					{
						fprintf(stderr, "%3hhu   ", sumArray[lineLoop]);
					}
				}
			}
		}
		
		fprintf(stderr, "              =");
		spaceLoop = 0;
		for (spaceLoop = 0; spaceLoop < spaceVar + 1; spaceLoop++) //Starting another line
		{
			fprintf(stderr, " ");
		}
		lineLoop = 0;
		carryCount = 0;
		for (lineLoop = 0; lineLoop < digitCount + 2; lineLoop++)
		{
			if (lineLoop == 0)
			{
				fprintf(stderr, "      ");
			}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////fix this///////////////////////////////////////////////////////////////
//			else if (sumArray[lineLoop + 1] == 0)
//			{
//				fprintf(stderr, " 10   ");
//				carryCount++;
//			}
/////////////////////////////////////////////////////////////////////////////////////////////////			
//			else if (sumArray[in
//			{
//			
//			}
			else
			{
				if (lineLoop == 1 && sumArray[1] == 0)
				{
					fprintf(stderr, " 10   ");
				}
				
				else
				{
					fprintf(stderr, "%3hhu   ", sumArray[lineLoop]);
				}
			}
		}
		
		fprintf(stderr, "\n");							 //No more additions unless [0] > 0
											
		if (sumArray[0] > 0)							 //Now a seperate condition for [0] > 0
		{
			fprintf(stderr, "              =");
			spaceLoop = 0;
			for (spaceLoop = 0; spaceLoop < spaceVar + 1; spaceLoop++)
			{
				fprintf(stderr, " ");
			}
			fprintf(stderr, "(0+1) ");
			lineLoop = 1;
			for (lineLoop = 1; lineLoop < digitCount + 2; lineLoop++)
			{
				fprintf(stderr, "%3hhu   ", sumArray[lineLoop]);
			}
			fprintf(stderr, "\n");

			fprintf(stderr, "              =");
			spaceLoop = 0;
			for (spaceLoop = 0; spaceLoop < spaceVar + 1; spaceLoop++)
			{
				fprintf(stderr, " ");
			}
			lineLoop = 0;
			for (lineLoop = 0; lineLoop < digitCount + 2; lineLoop++)
			{
				fprintf(stderr, "%3hhu   ", sumArray[lineLoop]);
			}
			fprintf(stderr, "\n");
		}	

		fprintf(stderr, "              = ");
		lineLoop = 1;
		if (sumArray[0] > 0)					//If [0] is 0, it shouldnt be printed 
		{										//so print here if it is greater than 0
			fprintf(stdout, "%hhu", sumArray[0]);
		}
		for (lineLoop = 1; lineLoop < digitCount + 2; lineLoop++)
		{
			fprintf(stdout, "%hhu", sumArray[lineLoop]); //The rest of the output
			
		}
		fprintf(stdout, "\n");

	}
	else
	{
		fprintf(stderr, "              = "); //Final output if there are no carries 
		unsigned char lastLineLoop = 1;			
		for (lastLineLoop = 1; lastLineLoop < digitCount + 2; lastLineLoop++)
		{				
			fprintf(stdout, "%hhu", sumArray[lastLineLoop]);
		}
		fprintf(stdout, "\n");
	}
	return (0);
}





