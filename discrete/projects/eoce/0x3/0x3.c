#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv)
{
	int *factors	 = calloc(64, sizeof(int));
	int	 output_flag = 0;
	int  qty		 = 0;
	int  n_ary       = 0;
	int  lower		 = 0;
	int  upper		 = 0;
	int  value		 = 0;
	int  div		 = 0;
	int  fcount		 = 0;
	int  fother		 = 0;
	int  ticker		 = 0;
	int  index		 = 0;

	if (argc < 3)
	{
		fprintf(stderr, "%s: Invalid number of arguments.\n", argv[0]);
		exit(1);
	}

	
	qty 	= atoi(argv[1]);
	if (qty == 0)
	{
		qty = 100000;
	}
	n_ary	= atoi(argv[2]);


	if (argc > 3) // name, qty, n-ary, lower, upper, output flag
	{
		lower = atoi(argv[3]); // lower
		if (lower == 0)
			lower  = 1;
		
		if (argc > 4)
		{
			upper = atoi(argv[4]);
			if (upper == 0)
				upper = 214700000;
			if (argc > 5)
			{
				output_flag = atoi(argv[5]);
			}
		}
		else
		{
			upper = 214700000;
		}
	}
	else
	{
		lower = 1;
		upper = 214700000;
	}


	for (value = lower; (value <= upper) && (ticker < qty); value++)
	{
		for (index = 0; index < 64; index++) // ckear factor array
			factors[index] = 0;
		
		fcount = fother = 0; // reset factor count;

		for (div = 1; div <= sqrt(value); div++)
		{
			if (value % div == 0)
			{
				factors[fcount] = div;
				fcount+=1;
				factors[fcount] = value / div;
				fcount+=1;
				fother+=1;
			}
		}
//		fprintf(stdout, "%d: %d factor pairs\n", value, fother);
		if (fother == n_ary)
		{
			ticker++;
			if (output_flag == 0)
			{
				fprintf(stdout, "%d ", value);
			}
			else
			{
				fprintf(stdout, "%d = {", value);
				index = 0;
				while (factors[index] != 0)
				{
					if (index == 0)
						fprintf(stdout, " 1,"); // make first take less space 
					else
						fprintf(stdout, "%3d,", factors[index]);
					index+=2;
				}
				index = index - 1;
				while (index > 0)
				{
					fprintf(stdout, "%3d", factors[index]);
					if (index != 1)
						fprintf(stdout, ",");
					else
						fprintf(stdout, " }\n");
					index-=2;
				}
			}
		}
	}

	if (output_flag == 0)
		fprintf(stdout, "\n");
	
	return(0);
}
