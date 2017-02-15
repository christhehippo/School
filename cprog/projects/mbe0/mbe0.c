#include <stdio.h>
#include <stdlib.h>

int main ()
{

	unsigned int userInput;
	unsigned char sum10000;
	unsigned char carry1000;
	unsigned char sum1000;
	unsigned char carry100;
	unsigned char sum100;
	unsigned char carry10;
	unsigned char sum10;
	unsigned char carry1;
	unsigned char sum1;



	fprintf(stderr, "Enter value: ");
	fscanf(stdin, "%u", &userInput);
    
	

	//***NOTE I MAY HAVE SOME USELESS STUFF IN HERE, I CUT AND OPTIMIZED SO I
	//MAY HAVE MISSED SOME STUFF BUT HEY IT WORKS***
	
	//if input is 2 digits, else assume input is 3 digits
	if (userInput < 100)
	{
	
		unsigned char d2 = (userInput % 10);
		unsigned char d1 = ((userInput-d2) / 10);
		//d1d2 not needed just for easy typing out d1 + d2
		unsigned char d1d2 = (d1 + d2);
		
		//not needed, only to conform to the specifications..?
		sum1 = d2;
		carry1 = (sum1 / 10);
		//check if a carry is needed for 10s spot
		if (d1d2 >= 10)
		{
			sum10 = (d1d2 - 10);
			carry10 = (d1d2 / 10);
		}
		else 
		{
			sum10 = d1d2;
			//repeating this step not needed just for personal clarity
			carry10 = (d1d2 / 10);
		}
		//now doing 100s spot and 100s carry if needed
		sum100 = (carry10 + d1);
		if (sum100 >= 10)
		{
			carry100 = 1;
		}
		else
		{
			carry100 = 0;
		}
		
		sum1000 = carry100;

		//now print output
		fprintf(stderr, "%u x 11 = ", userInput);
		fprintf(stderr, "    %4hhu", d1);
		fprintf(stderr, "   (%hhu+%hhu)", d1, d2);
		fprintf(stderr, "%4hhu\n", sum1);
		//next line of output
		fprintf(stderr, "        =");
		fprintf(stderr, "    %5hhu", d1);
		fprintf(stderr, "%6hhu", d1d2);
		fprintf(stderr, "%6hhu\n", sum1);
		//check if more lines are needed for more carrying 
		if (carry10 >= 1)
		{
		fprintf(stderr, "        =");
		fprintf(stderr, "      (%hhu+%hhu)", d1, carry10);
		fprintf(stderr, "%4hhu", sum10);
		fprintf(stderr, "%6hhu\n", sum1);
		//next line
		fprintf(stdout, "        =");
		fprintf(stdout, "%9hhu", sum100);
		fprintf(stdout, "%6hhu", sum10);
		fprintf(stdout, "%6hhu\n", sum1);
		}
		//next line
		fprintf(stderr, "        =  %hhu%hhu%hhu\n", sum100, sum10, sum1);		
	}
	//3 digit userInput 
	else
	{
		unsigned char d1 = (userInput / 100);
		unsigned char d2 = ((userInput - ((d1 * 100))) / 10);
		unsigned char d1d2 = (d1 + d2);
		unsigned char d3 = (userInput - ((d1 * 100) + (d2 * 10)));
		unsigned char d2d3 = (d2 + d3);
		//pointless BUT helps me clarify what I am working with while conforming to specs
		sum1 = d3;
		carry1 = (d3 / 10);
		//check for carry	
		if (d2d3 >= 10)
		{
			sum10 = (d2d3 - 10);
		}
		else 
		{
			sum10 = d2d3;
		}
		carry10 = (d2d3 / 10);
		//another check for carry
		if (d1d2 >= 10)
		{
			sum100 = ((d1d2 - 10) + carry10);
		}
		else
		{
			sum100 = (d1d2 + carry10);
		}
		carry100 = (d1d2 / 10);
		//check 'em
		if ((d1 >= 9) && (carry100 >= 1)) 
		{
			sum1000 = 0;
			carry1000 = 1;
		}
		else
		{
			sum1000 = (d1 + carry100);
			carry1000 = 0;
		}
		sum10000 = carry1000;
		//math done, ready for output
		fprintf(stderr, "%u x 11 = ", userInput);
			


		fprintf(stderr, "d1: %hhu, d2: %hhu, d3: %hhu\n", d1, d2, d3);
		fprintf(stderr, "%hhu %hhu %hhu %hhu %hhu", sum10000, sum1000, sum100, sum10, sum1);
	}
	
	return (0);
}
