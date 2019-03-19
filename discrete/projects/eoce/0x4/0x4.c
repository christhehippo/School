#include <stdio.h>
#include <stdlib.h>

void subset(int *factors, int **include, int i, int n, int k, int *done);

int main(int argc, char **argv)
{
	int done	 = 0;
	int i		 = 0;
	int index    = 0;
    int start 	 = 0;
	int end 	 = 0;
	int val      = 0;
	int div	     = 0;
	int sum      = 0;
	int count    = 0;
	int dir		 = 0;
	int *factors = (int *)malloc(sizeof(int) * 128); // 128 random size seems big enough
	int *include = calloc(128, sizeof(int));
	
	if (argc < 3)
	{
		if (argc == 1)
		{
			fprintf(stderr, "insufficient data provided\n");
			exit(1);
		}
		else if (argc == 2)
		{
			fprintf(stderr, "missing upper bound\n");
			exit(2);
		}
	}
	else
	{
		start = atoi(argv[1]);
		end   = atoi(argv[2]);

		if (start < end)
			dir = 1;
		else if (start > end)
			dir = -1;

		if (start < 2)
		{
			fprintf(stderr, "invalid range specification\n");
			exit(3);
		}

	}

	for (val = start; val != end + dir; val = val + dir)
	{
		count = 0;
		for (i = 0; i < 128; i++)
			factors[i] = 0;
		for (div = 2; div <= val / 2; div++)
		{
			if (val % div == 0)
			{
				factors[count] = div;
				count++;
			}
		}

		sum = 1;	
		for (index = 0; index < count; index++)
			sum = sum + factors[index];
		
		fprintf(stdout, "[%d] ", val);

		if (sum < val)
			fprintf(stdout, "deficient: ");
		else if (sum == val)
			fprintf(stdout, "perfect:   ");
		else if (sum > val)
			fprintf(stdout, "abundant:  ");

		fprintf(stdout, "1");
		if (count == 0) // check if prime
			fprintf(stdout, " = 1");
		else
			fprintf(stdout, "+");

		for (index = 0; index < count; index++)
		{
			if (index != count-1)
				fprintf(stdout, "%d+", factors[index]);
			else
				fprintf(stdout, "%d = %d ", factors[index], sum);
		}
		
		// weird/semi-perfect stuff here
		if (sum > val)
		{
			count++; // we need to stick the 1 in the array
			for (i = 126; i <= 0; i--)
			{
				if (i != 0)
				{
					factors[i+1] = factors[i];
				}
				else
				{
					factors[i] = 1;
				}
			}
			for (index = 0; index < 128; index++)
				include[index] = 0;
			done = 0;
			subset(factors, &include, 0, count, val, &done);
			if (done == 0)
				fprintf(stdout, "(weird: none)\n");
		}
		else	
			fprintf(stdout, "\n");
	
	
	}	
	
	return(0);
}
				// factors,   truth t    iteration, num ele, sum
void subset(int *factors, int **include, int i, int n, int k, int *done)
{
	// seems the best way to do this in my current understanding is to create
	// all possible permutations of the set, and then add them together
	// 
	// This is done through an include array which is altered prior to recursive call
	// basically just flagging values
	int index  = 0;
	int index2 = 0;
	int sum    = 0;
	if (i != n)
	{
		*(*include+i) = 1;
		subset(factors, include, i + 1, n, k, done);
		*(*include+i) = 2;
		subset(factors, include, i + 1, n, k, done);
	}
	else
	{
		if (*done == 1)
			return;
		for (index = 0; index < n; index++)
		{
			if (*(*include+index) == 2)
				sum = sum + factors[index];
		}
		if (sum == k)
		{
			fprintf(stdout, "(semi-perfect: ");
			for (index = 0; index < n; index++)
			{
				if (*(*include+index) == 2)
				{
					fprintf(stdout, "%d", factors[index]);
					
					// check what punctuation to use
					if (index == n - 1)
					{
						fprintf(stdout, ")\n");
					}
					else
					{
						for (index2 = index+1; index2 < n; index2++)
						{
							if (*(*include+index2) == 2)
							{
								fprintf(stdout, "+");
								break;
							}
							else
							{
								if (index2 == n - 1)
								{
									fprintf(stdout, ")\n");
									break;
								}
							}	
						}
					} // end punctuation check*/
				}
			}
			*done = 1; // dont want to print all the combos
		}
	}
}
