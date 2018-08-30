#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uc;

struct box
{
	unsigned char *sides;
	unsigned char  numsides;
	int			   length;
	int 		   area;
};
typedef struct box Box;

int main()
{
	struct box square;
	uc  input;
	int index;
	// or...
	// Box square

	fprintf(stdout, "How many sides do you choose?");
	fscanf (stdin, "%hhu", &input);
	if (input <= 2)
	{
		fprintf(stdout, "You chose... poorly\n");
		exit(1);
	}

	square.numsides = input;

	fprintf(stdout, "How long is a side?");
	fscanf (stdin, "%hhu", &input);
	if (input <= 0)
	{
		fprintf(stdout, "You chose... poorly\n");
		exit(2);
	}

	square.length    = input;

	square.area		 = square.length * square.length;

	square.sides     = (uc *)malloc(sizeof(uc) * square.numsides);



	free(square.sides);

	return(0);
}
