#include <stdio.h>
#include "node.h"

int main()
{
	char data[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7 };
	int i;

	fprintf(stdout, "Array: ");
	for(i = 0; i < 14; i++)
		fprintf(stdout, "%hhd ", *(data+i));
	fprintf(stdout, "\n");

	// Create a linked list of nodes, using the node library 
	// functions where applicable (mknode() specifically), and
	// have each node contain one of the above array elements,
	// to have a linked list equivalent of the array.

	// Display the list from beginning to end- the above order
	// of values should be seen.

	Node *first = NULL;
	Node *tmp   = NULL;
	first  		= mknode(data[0]);
	tmp = first;

	// create nodes 1-13
	for (i = 1; i < 14; i++)
	{
		tmp -> right = mknode(data[i]);
		tmp = tmp -> right;
	}
	
	// print nodes.info for nodes 0-13
	fprintf(stdout, "List:  ");
	tmp = first;
	for (i = 0; i < 14; i++)
	{	
		fprintf(stdout, "%hhd ", tmp -> info);
		tmp = tmp -> right;
	}
	fprintf(stdout, "\n");
	return(0);
}
