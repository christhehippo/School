#include <stdio.h>
#include <stdlib.h>

// define simple node/list structs
struct node {
	unsigned char    value;
	struct node     *N;
	struct node     *NE;
	struct node     *E;
	struct node     *SE;
	struct node     *S;
	struct node     *SW;
	struct node     *W;
	struct node     *NW;
};

typedef struct node  Node;


int main()
{
	int   i 	  = 0;
	int   ticker  = 0;
	int   turn    = 0;
	int   move    = 0;
	int   done	  = 0;
 	Node *board   = (Node *)malloc(sizeof(Node) * 9);
	
	// clear the board to all 'spaces'
	for (i = 0; i < 9; i++)
		(board+i) -> value = 48+i;

	// connect the board lol
	(board+0) -> N  = NULL;
	(board+0) -> NE = NULL;
	(board+0) -> E  = (board+1);
	(board+0) -> SE = (board+4);
	(board+0) -> S  = (board+3);
	(board+0) -> SW = NULL;
	(board+0) -> W  = NULL;
	(board+0) -> NW = NULL;

	(board+1) -> N  = NULL;
	(board+1) -> NE = NULL;
	(board+1) -> E  = (board+2);
	(board+1) -> SE = (board+5);
	(board+1) -> S  = (board+4);
	(board+1) -> SW = (board+3);
	(board+1) -> W  = (board+0);
	(board+1) -> NW = NULL;

	(board+2) -> N  = NULL;
	(board+2) -> NE = NULL;
	(board+2) -> E  = NULL;
	(board+2) -> SE = NULL;
	(board+2) -> S  = (board+5);
	(board+2) -> SW = (board+4);
	(board+2) -> W  = (board+1);
	(board+2) -> NW = NULL;

	(board+3) -> N  = (board+0);
	(board+3) -> NE = (board+1);
	(board+3) -> E  = (board+4);
	(board+3) -> SE = (board+7);
	(board+3) -> S  = (board+6);
	(board+3) -> SW = NULL;
	(board+3) -> W  = NULL;
	(board+3) -> NW = NULL;

	(board+4) -> N  = (board+1);
	(board+4) -> NE = (board+2);
	(board+4) -> E  = (board+5);
	(board+4) -> SE = (board+8);
	(board+4) -> S  = (board+7);
	(board+4) -> SW = (board+6);
	(board+4) -> W  = (board+3);
	(board+4) -> NW = (board+0);

	(board+5) -> N  = (board+2);
	(board+5) -> NE = NULL;
	(board+5) -> E  = NULL;
	(board+5) -> SE = NULL;
	(board+5) -> S  = (board+8);
	(board+5) -> SW = (board+7);
	(board+5) -> W  = (board+4);
	(board+5) -> NW = (board+1);

	(board+6) -> N  = (board+3);
	(board+6) -> NE = (board+4);
	(board+6) -> E  = (board+7);
	(board+6) -> SE = NULL;
	(board+6) -> S  = NULL;
	(board+6) -> SW = NULL;
	(board+6) -> W  = NULL;
	(board+6) -> NW = NULL;

	(board+7) -> N  = (board+4);
	(board+7) -> NE = (board+5);
	(board+7) -> E  = (board+8);
	(board+7) -> SE = NULL;
	(board+7) -> S  = NULL;
	(board+7) -> SW = NULL;
	(board+7) -> W  = (board+6);
	(board+7) -> NW = (board+3);

	(board+8) -> N  = (board+5);
	(board+8) -> NE = NULL;
	(board+8) -> E  = NULL;
	(board+8) -> SE = NULL;
	(board+8) -> S  = NULL;
	(board+8) -> SW = NULL;
	(board+8) -> W  = (board+7);
	(board+8) -> NW = (board+4);


	while (done == 0)
	{
		// loop to print board	
		for (i = 0; i < 9; i++)
		{
			fprintf(stdout, "%c", (board+i) -> value);
			ticker++;
			if (ticker != 3)
			{
				fprintf(stdout, " | ");
			}
			else
			{
				if (i != 8)
					fprintf(stdout, "\n---------");
				
				fprintf(stdout, "\n");
				ticker = 0;
			}
		}

		fprintf(stdout, "ENTER MOVE: ");
		fscanf(stdin, "%d", &move);

		if (turn == 0)
		{
			if (((board+move) -> value != 79) && ((board+move) -> value != 88))
			{
				(board+move) -> value = 79;
			}
			turn = 1; //  change turn
		}
		else
		{
			if (((board+move) -> value != 79) && ((board+move) -> value != 88))
			{
				(board+move) -> value = 88;
			}
			turn = 0; //  change turn
		}

		// now check if we have a win
		for (i = 0; i < 7; i++)
		{
			// brute force because i cant compare a value to null without seg faulting :(
			if (i == 0)
			{
				if ((board+i) -> value == (board+i) -> S -> value) // 0 3 6
				{
					if ((board+i) -> value == (board+i) -> S -> S -> value)
						done = 1;
				}
				else if ((board+i) -> value == (board+i) -> SE -> value) // 0 4 8
				{
					if ((board+i) -> value == (board+i) -> SE -> SE -> value)
						done = 1;
				}
				else if ((board+i) -> value == (board+i) -> E -> value) // 0 1 2
				{
					if ((board+i) -> value  == (board+i) -> E -> E -> value)
						done = 1;
				}
			}
			else if (i == 1)
			{
				if ((board+i) -> value == (board+i) -> S -> value) // 1 4 7
				{
					if ((board+i) -> value == (board+i) -> S -> S -> value)
						done = 1;
				}
			}
			else if (i == 2)
			{
				if ((board+i) -> value == (board+i) -> S -> value) // 2 5 8
				{
					if ((board+i) -> value == (board+i) -> S -> S -> value)
						done = 1;
				}
				else if ((board+i) -> value == (board+i) -> SW -> value) // 2 4 6 
				{
					if ((board+i) -> value == (board+i) -> SW -> SW -> value)
						done = 1;
				}
			}
			else if (i == 3)
			{
				if ((board+i) -> value == (board+i) -> E -> value) // 3 4 5
				{
					if ((board+i) -> value == (board+i) -> E -> E -> value)
						done = 1 ;
				}
			}
			else if (i == 6) // skip 4 + 5, already covered them
			{
				if ((board+i) -> value == (board+i) -> E -> value) // 6 7 8
				{
					if ((board+i) -> value == (board+i) -> E -> E -> value)
						done = 1;
				}
			}

			if (done == 1) // don't check everything if we are done
				break;
		}

	}

	for (i = 0; i < 9; i++)
	{
		fprintf(stdout, "%c", (board+i) -> value);
		ticker++;
		if (ticker != 3)
		{
			fprintf(stdout, " | ");
		}
		else
		{
			if (i != 8)
				fprintf(stdout, "\n---------");
			
			fprintf(stdout, "\n");
			ticker = 0;
		}
	}

	if (turn == 0)
	{
		fprintf(stdout,"\n\n");
		fprintf(stdout, "XXX   XXX   XXX    XXXXXX    XXXXXXXX\n");
		fprintf(stdout, " XXX XXXXX XXX       XX      XX    XX\n");
		fprintf(stdout, "  XXXXXXXXXXX        XX      XX    XX\n");
		fprintf(stdout, "   XXXX XXXX         XX      XX    XX\n");
		fprintf(stdout, "    XXX XXX          XX      XX    XX\n");
		fprintf(stdout, "     X   X         XXXXXX    XX    XX\n");
		fprintf(stdout, "\n\n");
	}
	else
	{
		fprintf(stdout,"\n\n");
		fprintf(stdout, "OOO   OOO   OOO    OOOOOO    OOOOOOOO\n");
		fprintf(stdout, " OOO OOOOO OOO       OO      OO    OO\n");
		fprintf(stdout, "  OOOOOOOOOOO        OO      OO    OO\n");
		fprintf(stdout, "   OOOO OOOO         OO      OO    OO\n");
		fprintf(stdout, "    OOO OOO          OO      OO    OO\n");
		fprintf(stdout, "     O   O         OOOOOO    OO    OO\n");
		fprintf(stdout, "\n\n");
	}



	return(0);
}

