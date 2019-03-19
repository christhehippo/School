// odd/even checking (logic)
#include <stdio.h>

int main()
{
	signed char array[12] = {56,73,36,112,177,80,23,17,6,14,29,79};
	signed char tmp		  = 0;
	int i 				  = 0;
	int count			  = 0;
	
	for (i = 0; i < 12; i++) 
	{
		tmp = 1 & array[i]; // all odds have rightmost 1
		if (tmp == 1)		// 00000001
		{
			tmp = -128 & array[i]; // 10000000 
			if (tmp != -128)	   // all negatives have leftmost 1
			{
				fprintf(stdout, "%d\n", array[i]);
				count++;
			}
		}
	}
	fprintf(stdout, "There are %d odd numbers greater than zero.\n", count);


	return(0);
}
