#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// searchlist() - a list library utility function to locate a node in
//                an existing list by value it contains.
//
//      note: unlike getpos()/setpos(), which worked in units of list
//            positional offsets, searchlist() focuses on the actual
//            content of what is in the nodes, returning a pointer to
//            the initial node that contains the matching value (from 
//            the start of the list).
//
//  behavior: on error (NULL/UNDEFINED list, NULL node, no match),
//            return NULL
//
//            you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *searchlist(List *myList, char value)
{
	Node *node;

	if (myList == NULL || myList == UNDEFINED)
	{
		// null list or undefined list check
		node = NULL;
	}
	else if (myList -> lead == NULL)
	{
		// empty list check
		node = NULL;
	}
	else
	{
		node = myList -> lead;
		// loop through until myList -> last
		while (node -> right != NULL)
		{
			if (node -> info == value)
				break;
			else			
				node = node -> right;
		}
		// if at the end, and value not found, set node to NULL
		if (node -> info != value)
		{
			node = NULL;
		}
	}
	
	
	
	return(node);
}
