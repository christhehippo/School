#include <stdio.h>
#include <stdlib.h>

int sum(int *numbers, int qty)
{
	int idx = 0;
	int result = 0;
	for (idx = 0; idx < qty; idx++)
	{
		result = result + *(numbers + idx);
	}
	return(result);
}
float avg(int total, int qty)
{
	return(total/qty);
}

int main(int argc, char **argv)
{
	int index = 0;
	int *values = NULL;
	int total = 0;
	float result = 0.0;
	int num = 0;

	values = (int *)malloc(sizeof(int)*(argc-1));
	num = argc - 1;

	for (index = 0; index < num; index++)
	{
		*(values+index) = atoi(*(argv+(index+1)));
	}
	
	total = sum(values, num);
	result  avg(total, num);
	
	for (index = 0; index < num; index++)
	{
		fprintf(stdout, "%d ", *(values+index));
	}
	fprintf(stdout, "/ %d = %f\n", num, result);
	free(values);
	values = NULL;


	return (0);
}

