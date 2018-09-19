#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// mknode() - a node library function to allocate and initialize a 
//			new node.
//
//  behavior: on error, return NULL.
//
//	  NOTE: you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
Node *mknode(char value)
{
	// allocate Node
	Node *node;
	node     = malloc(sizeof(Node) * 1);
	if (node == NULL)
	{
		// do nothing
	}
	else // else do something
	{
		// assign parameter to node.info
		node -> info     = value;
		node -> right    = NULL;
	}

	return(node);
}
