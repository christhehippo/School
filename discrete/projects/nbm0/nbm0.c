#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	// inputs
	char  inBase    = atoi(argv[1]);
	char  outBase   = atoi(argv[3]);
	char  places    = strlen(argv[2]);
	// other variables
	int   i 		         = 0;
	unsigned long long  tmp	 = 0;
	unsigned long long  tmp3 = 0;
	unsigned char  rem       = 0;
	unsigned char  tmp2      = 0;
	char *output             = calloc(64, sizeof(char)); // reserve memory for a long output

	// check for errors 
	if (inBase < 2 || inBase > 36)
	{
		fprintf(stderr, "Input base: %d is an invalid value\n", inBase);
		exit(1);
	}
	else if (outBase < 2 || outBase > 36)
	{
		fprintf(stderr, "Output base: %d is an invalid value\n", outBase);
		exit(2);
	}
	
	for (i = 0; i < places; i++) // loop to convert to a base 10 nubmer aka mathable num
	{
		tmp2 = argv[2][i]; // grab a byte from input string
		if (tmp2 > 64) // check if its a letter, convert it to a base 10 for ease of use
		{
			tmp2 = tmp2 - 55;
		}
		else // convert from ascii to real number
		{
			tmp2 = tmp2 - 48;
		}
		tmp3 = pow((double)inBase, (double)((places - 1) - i));
		tmp  = tmp + (tmp3 * (unsigned long long)tmp2);

	}
	i = 0; // reset our index value
	
	while (tmp != 0) // loop to fill the output string
	{
		rem = tmp % outBase; // get an output value
		tmp = tmp / outBase; // reduce tmp to its new value
		

		if (rem >= 10)
		{
			rem = rem + 55;
		}
		else
		{
			rem = rem + 48;
		}

		output[i] = rem;
		i++;
	}
	
	// print resulting string, backwards tho
	for (i = 63; i >= 0; i--)
	{
		if (output[i] == 0)
		{
			// ignore empty space, reserved more mem than needed
		}
		else
		{
			fprintf(stdout, "%c", output[i]);
		}
	}
	fprintf(stdout, "\n");

	return(0);
}
