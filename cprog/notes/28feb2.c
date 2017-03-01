#include <stdio.h>
#include <stdlib.h>

#define SIZE 12 

//function prototype / declaration
short int sum(char *, short int);

int main(int argc, char **argv)
{
	char numbers[SIZE];
	char input;
	short int qty = 0;
	float avg 	  = 0.0;
	
	// Load our array with user-input values
	for (qty = 0; qty < SIZE; qty++)
	{
		fprintf(stdout, " [%hd] Enter number (-1 to end): ", qty);
		fscanf(stdin, "%hhd", &input);
		if (input == -1)
		{
			break;
		}		
		numbers[qty] = input;
	}
	
	fprintf(stdout, "qty is: %hd\n", qty);

	// Compute the average
	avg = (float) sum(numbers, qty) / qty;
	
	//Display average
//	fprintf(stdout, "The sum of the values is : %hd.\n", sum);
	fprintf(stdout, "The average is : %.2f.\n", avg);

	
	return (0);
}

// sum() function definition
short int sum(char *data, short int qty)
{
	short int x = 0;
	short int total = 0;
	
	// Sum our individual values together
	for (x = 0; x < qty ; x++)
	{ 	
		total = total + data[x];
	}
	return(total);
}








