#include <stdio.h>
#include <stdlib.h>


int main()
{

	short int x = 0;
	char *nums =NULL;

	nums = (char *) calloc (9, sizeof(char));
	
	for (x = 0; x < 9; x++)
	{
		*(nums+x) = (x + 1) * (x + 1);
	}

	for (x = 8; x >= 0; x--)
	{
		fprintf(stdout, "nums[%hhd]: %hhd\n", x, nums[x]);
	}
	
	return (0);

}
