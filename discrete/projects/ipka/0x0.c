// odd/even checking (arithmetic)
#include <stdio.h>

int main()
{
	signed char array[12] = {56,73,36,112,177,80,23,17,6,14,29,79};
	int i 				  = 0;
	int count			  = 0;
	
	for (i = 0; i < 12; i++) 
	{
		if ((array[i] > 0) && (array[i] % 2 != 0))
		{
			fprintf(stdout, "%d\n", array[i]);
			count++;
		}
	}
	fprintf(stdout, "There are %d odd numbers greater than zero.\n", count);

	return(0);
}
