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

		//Here is the math for the two digit input
		//I made sure all the two digits worked before I touched anything to do with three digits
		
		//for when I do mbe1, I see a lot of ways I could have saved myself work and made this a bit shorter

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
			fprintf(stderr, "         = ");
			fprintf(stderr, "%15d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d\n", sum100, sum10, sum1);
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
			fprintf(stderr, "         = ");
			fprintf(stderr, "%15d", (input / 10));
			fprintf(stderr, "%5d%d", carry100, sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "            (%d+%d)", (input / 10), carry10);
			fprintf(stderr, "%4d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "%14d%d", carry100 ,sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "      (%d+%d)", sum1000 ,carry100);
			fprintf(stderr, "%4d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", carry100);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stdout,"%d%d%d%d\n", carry100,sum100, sum10, sum1);
			return (0);

		}
		
		else
		{
			//this path is for if there is a carry from the tens place calculation 
			fprintf(stderr, "%15d   ", (input / 10));
			fprintf(stderr, "(%d+%d)", (input / 10), sum1);
			fprintf(stderr, "%4d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "%15d", (input / 10));
			fprintf(stderr, "%5d%d", carry10, sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "            (%d+%d)", (input / 10), carry10);
			fprintf(stderr, "%4d",sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stderr, "%15d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d\n", sum100, sum10, sum1);
			return (0);

		}
	}		
	else
	{
		//Here is the math for the 3 digit stuff, more or less the same as the two digit
		//I am guessing some of it could be done at variable declaration but to be safe I just 
		//did it for each case

		//first piece of output
		fprintf(stderr, "%3hu x 11 = ", input);
		
		sum1 = ((input % 100) % 10);
		carry1 = 0;
		sum10 = sum1 + ((input / 10) % 10);
		//check for carry 10s
		if (sum10 >= 10)
		{
			carry10 = sum10 / 10;
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

		//ALL THE FOLLOWING IS DRAWN OUT CONDITIONS FOR THE POSSIBLE INPUTS
		//THEY ALL BUILD ON EACH OTHER AND FOLLOW THE SAME GENERAL FORMAT

		//sorry for not combining lines, it makes more sense to me if I do it one line at a time

		//no carries output
		if ((carry10 == 0) && (carry100 == 0) && (carry1000 == 0))
		{
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "   (%d+%d)", sum1000, (sum100 - sum1000));
			fprintf(stderr, " (%d+%d)", (sum100 - sum1000), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d\n", sum1000, sum100, sum10, sum1);
			
			return (0);	
		}
		
		if ((carry10 == 1) && (carry100 == 0) && (carry1000 == 0))
		{
//			fprintf(stderr, "test\n");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "   (%d+%d)", sum1000, (sum100 - (carry10 + sum1000)));
			fprintf(stderr, " (%d+%d)", (sum100 - (sum1000 + carry10)), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "%6d", (sum100 - carry10));
			fprintf(stderr, "%6d", sum10 + 10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "   (%d+%d)", (sum100 - carry10), carry10);
			fprintf(stderr, "%4d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			///next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d\n", sum1000, sum100, sum10, sum1);
			
			return (0);
		}
			
		if ((carry10 == 0) && (carry100 == 1) && (carry1000 == 0))
		{
//			fprintf(stderr, "test\n");
			fprintf(stderr, "%9d", sum1000 - carry100);
			fprintf(stderr, "   (%d+%d)", (sum1000 - carry100), (sum10 - sum1)); 
			fprintf(stderr, " (%d+%d)", (sum10 - sum1), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", (sum1000 - carry100));
			fprintf(stderr, "%6d", (sum100 + 10));
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "      (%d+%d)", (sum1000 - carry100), carry100);
			fprintf(stderr, "%4d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			///next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d\n", sum1000, sum100, sum10, sum1);
			
			return (0);
		}
		
		if ((carry10 == 1) && (carry100 == 1) && (carry1000 == 0))
		{
//			fprintf(stderr, "test\n");
			fprintf(stderr, "%9d", sum1000 - carry100);
			fprintf(stderr, "   (%d+%d)", (sum1000 - carry100), ((sum10 + 10) - sum1)); 
			fprintf(stderr, " (%d+%d)", ((sum10 + 10) - sum1), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", (sum1000 - carry100));
			fprintf(stderr, "%6d", ((sum100 - carry10) +10));
			fprintf(stderr, "%6d", (sum10 + 10));
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "      (%d+%d)", (sum1000 - carry100), carry100);
			fprintf(stderr, " (%d+%d)", (sum100 - carry10), carry10);
			fprintf(stderr, "%4d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			///next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d\n", sum1000, sum100, sum10, sum1);
			
			return (0);
		}

		if ((carry10 == 0) && (carry100 == 1) && (carry1000 == 1))
		{
//			fprintf(stderr, "test\n");
			fprintf(stderr, "%9d", ((sum1000 + 10) - carry100));
			fprintf(stderr, "   (%d+%d)", ((sum1000 + 10) - carry100), (sum10 - sum1)); 
			fprintf(stderr, " (%d+%d)", (sum10 - sum1), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", ((sum1000 + 10) - carry100));
			fprintf(stderr, "%6d", ((sum100 - carry10) +10));
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "      (%d+%d)", ((sum1000 + 10) - carry100), carry100);
			fprintf(stderr, "%4d", (sum100 - carry10));
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			///next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", (sum1000 + 10));
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "(%d+%d)", (sum10000 - carry1000), sum10000);
			fprintf(stderr, "%4d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%3d", sum10000);
			fprintf(stderr, "%6d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d%d\n", sum10000, sum1000, sum100, sum10, sum1);
		
			return (0);
		}	

		if ((carry10 == 1) && (carry100 == 1) && (carry1000 == 1))
		{
//			fprintf(stderr, "test\n");
			fprintf(stderr, "%9d", ((sum1000 + 10) - carry100));
			fprintf(stderr, "   (%d+%d)", ((sum1000 + 10) - carry100), sum100); 
			fprintf(stderr, " (%d+%d)", (sum100), sum1);
			fprintf(stderr, "%4d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", ((sum1000 + 10) - carry100));
			fprintf(stderr, "%6d", ((sum100 + 10) - carry10) );
			fprintf(stderr, "%6d", (sum10 + 10));
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "      (%d+%d)", ((sum1000 + 10) - carry100), carry100);
			fprintf(stderr, " (%d+%d)", (sum100 - carry10), carry10);
			fprintf(stderr, "%4d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			///next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%9d", (sum1000 + 10));
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "(%d+%d)", (sum10000 - carry1000), sum10000);
			fprintf(stderr, "%4d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stderr, "%3d", sum10000);
			fprintf(stderr, "%6d", sum1000);
			fprintf(stderr, "%6d", sum100);
			fprintf(stderr, "%6d", sum10);
			fprintf(stderr, "%6d\n", sum1);
			//next line
			fprintf(stderr, "         = ");
			fprintf(stdout, "%d%d%d%d%d\n", sum10000, sum1000, sum100, sum10, sum1);
			
			return (0);
		}


//		fprintf(stderr, "sum1-10000: %d %d %d %d %d. carry10 to 1000: %d %d %d.\n", sum1, sum10, sum100, sum1000, sum10000,
//		carry10, carry100, carry1000);




	}






	return (0);
}
