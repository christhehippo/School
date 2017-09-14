

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int max;
	int x = 0;
	int y = 0;
	int z = 0;
	int n = 0;
	int dash = 0;
	
	fprintf(stdout, "Enter value: ");
	fscanf(stdin, "%d", &max);
	//formatting tool below
	fprintf(stdout, "\n   | ");

	//top line loop
	while (z <= max)	
	{
		fprintf(stdout, "%3d ", z);
		z++;
	}
	//more format tool stuff
	fprintf(stdout, "\n-------");
	//add 4 * the max dashes to make it consistent 
	while (dash <= max)	 
	{
		fprintf(stdout, "----");
		dash++;
	}
	
	fprintf(stdout, "\n");
	//this creates the bulk of the table
	while (y <= max)
	{
		fprintf(stdout, "%2d | ", y);

		while (x <= max)
		{
			
			n = x * y;
			fprintf(stdout, "%3d ", n);
			x++;
		}

		y++;
		fprintf(stdout, "\n");
	}

	return (0);
}

