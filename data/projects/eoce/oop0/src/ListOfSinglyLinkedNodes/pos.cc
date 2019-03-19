#include "ListOfSinglyLinkedNodes.h"

// needs to properly handle invalid list positions ( < 0)
Node * ListOfSinglyLinkedNodes :: setListPosition(int pos)
{
	Node *tmp  = NULL;
	int   i    = 0;

	if (pos < 0)
	{
//		fprintf(stderr, "Invalid pos, < 0\n");
	}
	else
	{
		tmp = this -> getFirst();
		while (i != pos && tmp != NULL)
		{
			tmp = tmp -> getAfter();
			i++;
		}
	}

	return(tmp);
}

// Needs to handle improper place pointers (ie NULL)
int ListOfSinglyLinkedNodes :: getListPosition(Node *place)
{
	int pos 	= 0;
	Node *tmp	= NULL;

	if (place == NULL)
	{
//		fprintf(stderr, "Invalid *place node\n");
	}
	else
	{
		tmp = this -> getFirst();
		while (tmp != place)
		{
			tmp = tmp -> getAfter();
			if (tmp == NULL)
				break;
		}
		if (tmp == NULL)
		{
//			fprintf(stderr, "Node not found\n");
		}
	}

	return(pos);
}
