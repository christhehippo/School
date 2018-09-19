#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2;
	char input;

	tmp  = tmp2   = (Node *) malloc (sizeof(Node)*1);
	if (tmp == NULL)
	tmp -> info   = 0;
	tmp -> right  = NULL;

	fprintf(stdout, "Enter a value (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	while (input != -1)
	{
		tmp2 -> info = input;

		tmp2 -> right = (Node *) malloc (sizeof(Node)*1);
		tmp2 -> right -> info = 0;
		tmp2 -> right -> right  = NULL;

		fprintf(stdout, "Enter a value (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			free(tmp2 -> right);
			tmp2 -> right = NULL;
		}
		else
			tmp2 = tmp2 -> right;
	}

	// Provide code to display list from start to end


	while (tmp != NULL)
	{
		fprintf(stdout, "%d -> ", tmp -> info);
		tmp = tmp -> right;
			
	}
	fprintf(stdout, "NULL");
	fprintf(stdout, "\n");

	return(0);
}
