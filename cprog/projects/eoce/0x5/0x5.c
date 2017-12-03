#include <stdio.h>
#include <stdlib.h>


int main()
{
	// Vars
	int fibo[34] = {0};
	fibo[3] = 1;
	int index = 0;

	// Quick new line
	fprintf(stdout, "\n");

	for (index = 2; index < 34; index++)
	{
		
		// Do maths   
		fibo[index] = fibo[index] + fibo[index-1] + fibo[index-2];
		// The logic here is that if everything is initially 0 except the 4th element
		// then you can just add the old value of fibo[index] to the new value of fibo[index]
		// 0+0+'0', 0+0+'1', 0+1+'0', 1+1+'0', 1+2+'0', 2+3+'0', 3+5+'0' -- to list a few calculations.
		// This gets around the 0 + 0 = 1 issue


		// Print num
		fprintf(stdout, "    %.8d", fibo[index]);
		


		// New line check
		if ((index - 1) % 4 == 0 && index != 2)
		{
			fprintf(stdout, "\n");
		}
	}
	
	// Another quick new line
	fprintf(stdout, "\n");

	return(0);
}
