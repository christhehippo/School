#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uc;

struct box
{
	uc  *sides;
	uc   numsides;
	int  perimeter;	
};
typedef struct box Box;

int main()
{
	struct box square;
	uc input;
	int index;
	// or...
	// Box square;

	fprintf (stdout, "How many sides do you choose? ");
	fscanf  (stdin,  "%hhu", &input);
	if (input <= 2)
	{
		fprintf (stdout, "You chose... poorly\n");
		exit (1);
	}

	square.numsides  = input;
	square.sides     = (uc *) malloc (sizeof (uc) * square.numsides);
	square.perimeter = 0;

	for (index = 1; index <= square.numsides; index+=1)
	{
		fprintf (stdout, "How long is side #%d? ", index);
		fscanf  (stdin,  "%hhu", &input);
		if (input <= 0)
		{
			fprintf (stdout, "You chose... poorly\n");
			exit (index+1);
		}

		*(square.sides+(index-1))  = input;
		square.perimeter      += *(square.sides+(index-1));
	}

	fprintf (stdout, "Perimeter is: %d\n", square.perimeter);
	fprintf (stdout, "with sides of: \n");
	for (index = 0; index < square.numsides; index++)
	{
		fprintf (stdout, "\tside #%d is: %hhu\n", (index+1),
												  *(square.sides+index));
	}
	fprintf (stdout, "\n");

	free (square.sides);

	return (0);
}
