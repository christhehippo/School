#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int index    = 0;
    int start 	 = 0;
	int end 	 = 0;
	int val      = 0;
	int div	     = 0;
	int sum      = 0;
	int count    = 0;
	int dir		 = 0;
	int *factors = (int *)malloc(sizeof(int) * 128); // 128 random size seems big enough	

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
			fprintf(stdout, " = 1\n");
		else
			fprintf(stdout, "+");

		for (index = 0; index < count; index++)
		{
			if (index != count-1)
				fprintf(stdout, "%d+", factors[index]);
			else
				fprintf(stdout, "%d = %d\n", factors[index], sum);
		}
		
	}	
	
	return(0);
}
