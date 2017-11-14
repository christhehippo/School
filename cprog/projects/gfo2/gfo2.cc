#include <stdio.h>
#include <stdlib.h>

FILE* fileOpen();
void dashMaker9001();
void equaMaker9001();

int main()
{
	// Open file with function
	FILE *fp = fileOpen();

	int count     =  0;
	int nums[100] = {0};
	while (fscanf(fp, "%d", &nums[count]) != EOF)
	{
		++count; //Placing the numbers in the file into an initial array
	}			 //Variable count to help with next array loop

	fclose(fp);
	return(0);
}

FILE* fileOpen() 
{
	FILE *fp;
	fp = fopen("cprog.status.flat", "r");
	return (fp);
}

void dashMaker9001() // If there were more line like this to print it might be useful

{
	fprintf(stdout, "-------------------------------------\n");
}

void equaMaker9001() // If there were more line like this to print it might be useful
{
	fprintf(stdout, "=====================================\n");
}

