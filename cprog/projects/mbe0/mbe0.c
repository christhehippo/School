#include <stdio.h>
#include <stdlib.h>

int main ()
{
	//initialize needed variables
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


	//prompt input, store input
	fprintf(stderr, "Enter value: ");
	fscanf(stdin, "%u", &userInput);
    //fprintf(stderr, "%u\n", userInput); 
	

	//***NOTE I MAY HAVE SOME USELESS STUFF IN HERE, I CUT AND OPTIMIZED SO I
	//MAY HAVE MISSED SOME STUFF BUT HEY IT WORKS***
	
	//if input is 2 digits, else assume input is 3 digits
	if (userInput < 100)
	{
	
		unsigned char d2 = (userInput % 10);
		unsigned char d1 = ((userInput-d2) / 10);
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
		if ((carry10 + d1) >= 10)
		{
			sum100 = ((carry10 + d1) - 10);
		}
		else
		{
		sum100 = (carry10 + d1);
		}
		if ((carry10 + d1) >= 10)
		{
			carry100 = 1;
		}
		else
		{
			carry100 = 0;
		}
		sum1000 = carry100;	
		

		//now print output
		fprintf(stderr, "%3u x 11 = ", userInput);
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5hhu ", d1);
		fprintf(stderr, "(%hhu+%hhu) ", d1, d2);
		fprintf(stderr, "%5hhu\n", sum1);
		//next line of output
		fprintf(stderr, "%9c= ",' ');
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5hhu ", d1);
		fprintf(stderr, "%5hhu ", d1d2);
		fprintf(stderr, "%5hhu\n", sum1);
		//check if more lines are needed for more carrying 
		if (d1d2 >= 10)
		{
			fprintf(stderr, "%9c= ", ' ');
			fprintf(stderr, "%5c ", ' ');
			fprintf(stderr, "%5c ", ' ');
			fprintf(stderr, "(%hhu+%hhu)", d1, carry10);
			fprintf(stderr, "%6hhu ", sum10);
			fprintf(stderr, "%5hhu\n", sum1);
			//next line
			fprintf(stderr, "%9c= ", ' ');
			fprintf(stderr, "%5c ", ' ');
			if (sum1000 >= 1)
			{
				fprintf(stderr, "%5hhu ", sum1000);
			}
			else
			{
				fprintf(stderr, "%5c ", ' ');
			}
			fprintf(stderr, "%5hhu ", sum100);
			fprintf(stderr, "%5hhu ", sum10);
			fprintf(stderr, "%5hhu\n", sum1);
			//next line
			fprintf(stderr, "%9c= ", ' ');
			if (carry100 >= 1)
			{
				fprintf(stdout, "%hhu%hhu%hhu%hhu\n", carry100, sum100, sum10, sum1);		
			}
			else 
			{
				fprintf(stdout, "%hhu%hhu%hhu\n", sum100, sum10, sum1);
			}
		}	
		else
		{
		//next line
		fprintf(stderr, "%9c= ", ' ');
		fprintf(stdout, "%hhu%hhu%hhu\n", sum100, sum10, sum1);		
		}
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
			
		//now print output 0 9 (9+9) (9+9) 9
		fprintf(stderr, "%3u x 11 = ", userInput);
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5hhu ", d1);
		fprintf(stderr, "(%hhu+%hhu) ", d1, d2);
		fprintf(stderr, "(%hhu+%hhu) ", d2, d3);
		fprintf(stderr, "%5hhu\n", sum1);
		//next line of output 0 9 18 18 9
		fprintf(stderr, "%9c= ",' ');
		fprintf(stderr, "%5c ", ' ');
		fprintf(stderr, "%5hhu ", d1);
		fprintf(stderr, "%5hhu ", d1d2);
		fprintf(stderr, "%5hhu ", d2d3);
		fprintf(stderr, "%5hhu\n", sum1);
		//if done, do final output
		if ((carry100 == 0) && (carry10 == 0))
		{
			fprintf(stderr, "%9c= ", ' ');
			fprintf(stdout, "%hhu%hhu%hhu%hhu\n", sum1000, sum100, sum10,sum1);
			//end if this case is true after printing final out
			return (0);
		}
		//new line 0 (9+1) (8+1) 8 9 
		fprintf(stderr, "%9c= ", ' ');
		fprintf(stderr, "%5c ", ' ');
		//check if 1000s place is getting a carry
		if (carry100 > 0)
		{
			fprintf(stderr, "(%hhu+%hhu)", d1, carry100);
		}
		else
		{
			fprintf(stderr, "%5hhu ", d1);
		}
		//check if 100s place got a carry
		if (carry10 > 0)
		{
			fprintf(stderr, "(%hhu+%hhu)", sum100, carry10);
			
		}
		else 
		{
			fprintf(stderr, "%5hhu ", sum100);
		}
		fprintf(stderr, "%5hhu ", sum10);
		fprintf(stderr, "%5hhu\n", sum1);
		//new line 
	
		fprintf(stderr, "%9c= ", ' ');
		if (sum10000 > 0)
		{
			fprintf(stdout, "%hhu%hhu%hhu%hhu%hhu\n", sum10000, sum1000, sum100, sum10, sum1);
		}
		else
		{
			fprintf(stdout, "%hhu%hhu%hhu%hhu\n", sum1000, sum100, sum10, sum1);
		}




		//fprintf(stderr, "d1: %hhu, d2: %hhu, d3: %hhu\n", d1, d2, d3);
		//fprintf(stderr, "%hhu %hhu %hhu %hhu %hhu", sum10000, sum1000, 
		//sum100, sum10, sum1);
	}
	
	return (0);
}
