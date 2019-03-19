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
	Box *square  = NULL;
	uc input     = 0;
	int index    = 0;

	square       = (Box *) malloc (sizeof(Box) * 6);

	fprintf (stdout, "How many sides do you choose? ");
	fscanf  (stdin,  "%hhu", &input);
	if (input <= 2)
	{
		fprintf (stdout, "You chose... poorly\n");
		exit (1);
	}

	(square+1) -> numsides  = input;
	(square+1) -> sides     = (uc *) malloc (sizeof(uc)*(square+1) -> numsides);
	(square+1) -> perimeter = 0;

	for (index = 1; index <= (square+1) -> numsides; index+=1)
	{
		fprintf (stdout, "How long is side #%d? ", index);
		fscanf  (stdin,  "%hhu", &input);
		if (input <= 0)
		{
			fprintf (stdout, "You chose... poorly\n");
			exit (index+1);
		}

		*((square+1) -> sides+(index-1))  = input;
		(square+1) -> perimeter      += *((square+1) -> sides+(index-1));
	}

	fprintf (stdout, "Perimeter is: %d\n", (square+1) -> perimeter);
	fprintf (stdout, "with sides of: \n");
	for (index = 0; index < (square+1) -> numsides; index++)
	{
		fprintf (stdout, "\tside #%d is: %hhu\n", (index+1),
												  *((square+1) -> sides+index));
	}
	fprintf (stdout, "\n");

	free ((square+1) -> sides);
	(square+1) -> sides = NULL;
	free (square);
	square = NULL;

	return (0);
}
