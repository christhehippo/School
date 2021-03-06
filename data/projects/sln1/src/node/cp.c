#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// cpnode() - a node library function to duplicate a node and its 
//			contents -- it must call other functions as needed, and
//			take care to ensure all aspects of the source node have
//			been successfully replicated in the copied node.
//
//  behavior: on error or NULL source node, return NULL.
//
//	  NOTE: you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
//			the contents of the "right" pointer, if non-NULL,
//			should be pointing to any next node (even though we
//			are not copying it here).
//
Node *cpnode(Node *curNode)
{
	Node *node;

	if (curNode == NULL)
	{
		node = NULL;
	}
	else
	{
		node = mknode(0);
		node -> right = curNode -> right;
		node -> info  = curNode -> info;
	}

	return(node);
}
