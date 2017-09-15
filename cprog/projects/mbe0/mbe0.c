// mbe0 project by Christian Cattell cscs1320 cprog

#include <stdio.h>
#include <stdlib.h>



int main ()
{
	unsigned short int input;
	unsigned char sum10000, sum1000, sum100, sum10, sum1;
	unsigned char carry1000, carry100, carry10, carry1;

	fprintf(stderr, "Enter value: ");
	fscanf(stdin, "%hu", &input);

	//initial if statement to determine if processing a two or three digit number
	//if = 2 or less digits, else = 3 or more digits
	if ((input / 100) == 0)
	{
		//first piece output
		fprintf(stderr, "%3hu x 11 = ", input);

		sum1 = (input % ((input / 10) * 10)); 
		carry1 = 0; //this has no use, I don't know why it was required to have it
		sum10 = (input / 10) + sum1;
		carry10 = 0;
		sum100 = input / 10;
		if (sum10 >= 10)
		{
			carry10 = sum10 / 10;
			sum10 = sum10 - 10;
		}
		else
		{
			//no carries, then this path is taken
			fprintf(stderr, "%15d   ", sum100);
			fprintf(stderr, "(%d+%d)", sum100, sum1);
			fprintf(stderr, "%4d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", sum100);
			fprintf(stderr,"%6d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stdout,"%d%d%d\n", sum100, sum10, sum1);
			return (0);
		}
//		fprintf(stderr, "sum10: %d\n", sum10);
//		fprintf(stderr, "carry10: %d\n", carry10);		
		sum100 = (input / 10) + carry10;
		carry100 = sum100 / 10;
		if (sum100 >= 10)
		{
			//if the hundreds place has a carry this path is taken
			sum100 = sum100 - 10;

			fprintf(stderr, "%15d   ", (input / 10));
			fprintf(stderr, "(%d+%d)", (input / 10), sum1);
			fprintf(stderr, "%4d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", (input / 10));
			fprintf(stderr,"%5d%d", carry100, sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"            (%d+%d)", (input / 10), carry10);
			fprintf(stderr,"%4d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%14d%d", carry100 ,sum100);
			fprintf(stderr,"%6d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stdout,"%d%d%d%d\n", carry100,sum100, sum10, sum1);
			return (0);

		}
		
		else
		{
			//this path is for if there is a carry from the tens place calculation 
			fprintf(stderr, "%15d   ", (input / 10));
			fprintf(stderr, "(%d+%d)", (input / 10), sum1);
			fprintf(stderr, "%4d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", (input / 10));
			fprintf(stderr,"%5d%d", carry10, sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"            (%d+%d)", (input / 10), carry10);
			fprintf(stderr,"%4d",sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", sum100);
			fprintf(stderr,"%6d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stdout,"%d%d%d\n", sum100, sum10, sum1);
			return (0);

		}
	}		
	else
	{
		sum1 = ((input % 100) % 10);
		carry1 = 0;
		sum10 = sum1 + ((input / 10) % 10);
		//check for carry 10s
		if (sum10 >= 10)
		{
			carry10 = 1;
			sum10 = sum10 - 10;
		}
		else
		{
			carry10 = 0;
		}
		
		sum100 = (input / 100) + ((input % 100) / 10) + carry10;
		//check for carry 100s
		if (sum100 >= 10)
		{
			carry100 = 1;
			sum100 = sum100 - 10;

		}	
		else
		{
			carry100 = 0;
		}
		
		sum1000 = carry100 + (input / 100);
		//check for carry 1000s
		if (sum1000 >= 10)
		{
			carry1000 = 1;
			sum1000 = sum1000 - 10;
		}
		else
		{
			carry1000 = 0;
		}

		sum10000 = carry1000;

		//no carries output
		if ((carry10 = 0) && (carry100 = 0) && (carry1000 = 0))
		{
			fprintf(stderr,"hi\n");
		}
		fprintf(stderr, "sum1-10000: %d %d %d %d %d. carry10-1000: %d %d %d.\n", sum1, sum10, sum100, sum1000, sum10000, carry10, 
		carry100, carry1000);




	}






	return (0);
}
