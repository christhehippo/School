#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	time_t t;
	srand((char) time(&t));
	char x = (rand() % 25);
	char newBlock = 2;
	char n;
	int score = 0;
	int moves = 0;

	for (n = 0; n <= 4; n++)
	{
		if (n == 0)
		{	
			fprintf(stdout, " ~~~~~~~~~~~~~~~~       ~~~~~~~~~~~\n");
			fprintf(stdout, " Score: %9.9d       Moves: %4.4d  \n", score, moves);  
			fprintf(stdout, " ~~~~~~~~~~~~~~~~       ~~~~~~~~~~~\n");
			fprintf(stdout, " _______ _______ _______ _______ _______\n");
		}
		fprintf(stdout, "|       |       |       |       |       |\n");
		fprintf(stdout, "|       |       |       |       |       |\n");
		fprintf(stdout, "|_______|_______|_______|_______|_______|\n");
	}
	return(0);

}
