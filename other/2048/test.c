#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	time_t t;
	srand((char) time(&t));
	char x = (rand() % 5);
	char start = 2;
	char grid;
	char y;
	fprintf(stdout, "|-----||-----||-----||-----||-----|\n");
	for (y = 0; y <= 4; y++)
	{
	switch(x)
	{
		case 0:
		{
			for (grid = 0; grid <= 4; grid++)
			{
				if (grid == 0)
				{
					fprintf(stdout, "|  %hhu  |", start);
				}
				else
				{
					fprintf(stdout, "|     |");
				}
			}
			fprintf(stdout, "\n|-----||-----||-----||-----||-----|\n");
			break;
		}
		case 1:
		{
			for (grid = 0; grid <= 4; grid++)
			{
				if (grid == 1)
				{
					fprintf(stdout, "|  %hhu  |", start);
				}
				else
				{
					fprintf(stdout, "|     |");
				}
			}
			fprintf(stdout, "\n|-----||-----||-----||-----||-----|\n");
			break;
		}
		case 2:
		{
			for (grid = 0; grid <= 4; grid++)
			{
				if (grid == 2)
				{
					fprintf(stdout, "|  %hhu  |", start);
				}
				else
				{
					fprintf(stdout, "|     |");
				}
			}
			fprintf(stdout, "\n|-----||-----||-----||-----||-----|\n");
			break;
		}
		case 3:
		{
			for (grid = 0; grid <= 4; grid++)
			{
				if (grid == 3)
				{
					fprintf(stdout, "|  %hhu  |", start);
				}
				else
				{
					fprintf(stdout, "|     |");
				}
			}
			fprintf(stdout, "\n|-----||-----||-----||-----||-----|\n");
			break;
		}
		case 4:
		{
			for (grid = 0; grid <= 4; grid++)
			{
				if (grid == 4)
				{
					fprintf(stdout, "|  %hhu  |", start);
				}
				else
				{
					fprintf(stdout, "|     |");
				}
			}
			fprintf(stdout, "\n|-----||-----||-----||-----||-----|\n");
			break;
		}
	}
	}
	return(0);

}
