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
	
//	fprintf(stderr, "Input: %hu, Input / 100: %hu\n", input, (input / 100));
	if ((input / 100) == 0)
	{
		//first piece output
		fprintf(stderr, "%3hu x 11 = ", input);

		sum1 = (input % ((input / 10) * 10)); 
		carry1 = 0;
//		fprintf(stderr, "sum1: %d\n", sum1);

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

		if (sum100 >= 10)
		{
			carry100 = sum100 / 10;
			sum100 = sum100 - 10;
		}
		else
		{
			fprintf(stderr, "%15d   ", (input / 10));
			fprintf(stderr, "(%d+%d)", sum100, sum1);
			fprintf(stderr, "%4d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", (input / 10));
			fprintf(stderr,"%6d", (sum10 + 10));
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"            (%d+%d)", (input / 10), carry10);
			fprintf(stderr,"%4d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stderr,"%15d", sum100);
			fprintf(stderr,"%6d", sum10);
			fprintf(stderr,"%6d\n", sum1);
			fprintf(stderr,"         = ");
			fprintf(stdout,"%d%d%d\n", sum100, sum10, sum1);
			return (0);

		}
		
		
//		fprintf(stderr, "sum100: %d\n", sum100);
//		fprintf(stderr, "carry100: %d\n", carry100);
		
//		sum1000 = carry100;
//		fprintf(stderr, "sum1000: %d\n", sum1000);

	}
	else
	{

	}






	return (0);
}
