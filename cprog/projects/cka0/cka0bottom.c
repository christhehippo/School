#include <stdio.h>
#include <stdlib.h>

int main()
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	int index  = 0; // iteration variable
	int b1 = 0;
	int b2 = 0;
	int b4 = 0;
	int b8 = 0;
	//////////////////////////////////////////////////////////////////
	//
	// Display table header
	//
	fprintf (stdout, " bin|oct|dec|hex\n");
	fprintf (stdout, "----+---+---+----\n");
	
	//////////////////////////////////////////////////////////////////
	//
	// Loop
	//

	do
	{
		if (index >= 8)
		{ 
			b8 = 1;
			b4 = ((index / 2) / 2) - 2;
			b2 = (index / 2) - (((index / 2) / 2) * 2); 
		}		
		else
		{
			b8 = 0;
			if (index >= 4)
			{
				b4 = 1;
				if (index - 5 > 0)
				{
					b2 = 1;
				}
				else
				{
					b2 = 0;
				}
			}
			
			else
			{
				if (index >= 2)
				{
					b2 = 1;
				}
			}
		}
		
		b1 = index % 2;
		fprintf(stdout, "%d%d%d%d", b8, b4, b2, b1);
		fprintf(stdout, "|%.3o", index);
		fprintf(stdout, "|%3d", index);
		fprintf(stdout, "|0x%X\n", index);
		index++;	
	}
	while (index <= 15);
	return (0);
}
