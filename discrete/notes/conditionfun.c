#include <stdio.h>
#include <stdlib.h>

int main()
{
	int grid[8][8];
	int x 	   = 0;
	int y 	   = 0;
	int w      = 0; // w, as in the radius, of a square
	int index  = 0;
	int indexY = 0;
	int flag   = 0;

	for (index = 0; index < 8; index++)
	{
		for (indexY = 0; indexY < 8; indexY++)
		{
			grid[index][indexY] = 0;
		}
	}

	grid[4][2] = 1;
	grid[5][2] = 1;
	grid[3][6] = 1;

	fprintf(stdout, "Choose your X coordinate: ");
	fscanf (stdin, "%d", &x);

	fprintf(stdout, "Choose your Y coordinate: ");
	fscanf (stdin, "%d", &y);

	fprintf(stdout, "Choose your W radiusness: ");
	fscanf (stdin, "%d", &w);

	//check if theres an intersection (aka collision)
	for (index = 0; (index < w) && (flag != 1); index++)
	{
		for (indexY = 0; (indexY < w) && (flag != 1); indexY++)
		{
			if (grid[x+index][y+indexY] == 1)
			{
			fprintf(stdout, "Collisionne at %d,%d\n", x+index, y+indexY);
				flag = 1;
			}
		}
	}
	

	return (0);
}
