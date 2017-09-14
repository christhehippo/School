

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int max;
	int x = 0;
	int y;
	int z;
	int n;
	int dash;
	
	fprintf(stdout, "Enter value: ");
	fscanf(stdin, "%d", &max);
	//formatting tool below
	fprintf(stdout, "\n   | ");

	//top line loop
	for (z = 0; z <=  max; z = z +1)
	{
		fprintf(stdout, "%3d ", z);
	}
	//more format tool stuff
	fprintf(stdout, "\n-------");
	//add 4 * the max dashes to make it consistent 
	for (dash = 0; dash <= max; dash = dash + 1)
	{
		fprintf(stdout, "----");
	}
	
	fprintf(stdout, "\n");
	//this creates the bulk of the table
	for (y = 0; y <= max; y = y + 1)
	{
		fprintf(stdout, "%2d | ", y);

		for (x = 0; x <= max; x = x + 1)
		{
			n == 0;
	
			n = x * y;

			fprintf(stdout, "%3d ", n);
		}

		fprintf(stdout, "\n");
	}

	return (0);
}

