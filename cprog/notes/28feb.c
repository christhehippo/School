#include <stdio.h>
#include <stdlib.h>

#define SIZE 12 


int main()
{
	char numbers[SIZE];
	char input;
	short int x	  = 0;
	short int qty = 0;
	short int sum = 0;
	float avg 	  = 0.0;
	
	// Load our array with user-input values
	for (qty - 0; qty < SIZE; qty++)
	{
		fprintf(stdout, " [%hd] Enter number (-1 to end): ", qty);
		fscanf(stdin, "%hhd", &input);
		if (input == -1)
		{
			break;
		}		
		numbers[qty] = input;
	}

	// Sum our individual values together
	for (x = 0; x < 12 ; x++)
	{ 	
		sum = sum + numbers[x];
	}

	//compute the average
	avg = (float) sum / SIZE;
	
	//Display average
	fprintf(stdout, "The sum of the values is : %hd\n.", sum);
	fprintf(stdout, "The average is : %.2f\n.", avg);
	
	
	return (0);
}
