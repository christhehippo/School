#include <stdio.h>
#include "node.h"

void display(Node *);

int main()
{
	// rewrite node-app-display to use the node library functions
	// (mknode(), specifically). The resulting output
	// should be IDENTICAL to the original node-app-display program.
	
	// Display list from start to end by calling the display() 
	// function, passing in a pointer to the start of the list.

	char input      = 0;
	Node *tmp 		= mknode(0); // create node with tmp+tmp 2 pointing to it
	Node *tmp2      = tmp;
	
	if (tmp == NULL)
	{
		fprintf(stdout, "Error creating node\n");
		return (1);
	}

	fprintf(stdout, "Enter a value (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	while (input != -1)
	{
		// assign input to node pointed at by tmp2
		tmp2 -> info  = input; 
		tmp2 -> right = mknode(0);
		
		fprintf(stdout, "Enter a value (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			rmnode(tmp2 -> right);
		}
		else
		{
			tmp2 = tmp2 -> right;
		}
	}

	display(tmp);

	return(0);
}

void display(Node *start)
{
	// implement your display list function here, and call it from
	// main() -- you may use the same code implemented previously 
	// for displaying the list.
	
	// This is a test to see if you can modularize your code.
	while (start -> right != NULL)
	{
		fprintf(stdout, "%d -> ", start -> info);
		start = start -> right;
	}
	fprintf(stdout, "NULL\n");
}
