#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// getpos() - a list library utility function to identify the actual
//			position of a given node in an indicated list.
//
//	  note: Indexing of the list starts from 0
//
//  behavior: on error (NULL/UNDEFINED list or given node), return
//			negative value (-1), on out-of-bounds condition,
//			return -2
//
//			you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
int getpos(List *myList, Node *given)
{
	// position value
	int pos = 0;
	Node* tmp;

	// check if NULL
	if (myList == NULL || given == NULL)
	{
		pos = -1;
	}
	else
	{
		tmp = myList -> lead;
		while (tmp != given)
		{
			tmp = tmp -> right;
			pos++;
			if (tmp == NULL)
			{
				pos = -2;
				break;
			}
		}
	}
	
	
	
	return(pos);
}

//////////////////////////////////////////////////////////////////////
//
// setpos() - a list library utility function to set a node pointer
//			to the node at the indicated position of a list.
//
//	  note: Indexing of the list starts from 0
//
//  behavior: on error (NULL/UNDEFINED list or negative/out-of-bounds
//			pos), return NULL.
//
//			you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
Node *setpos(List *myList, int pos)
{
	
	Node *tmp = NULL;
	int index = 0;

	if (myList == NULL)
	{
		// do nothing
	}
	else if (pos < 0)
	{
		tmp = NULL;
	}
	else
	{	// go to the indicated position
		tmp = myList -> lead;
		for (index = 0; index < pos; index++)
		{
			// if we hit a null, return a null
			if (tmp == NULL)	
				break;
			else
				tmp = tmp -> right;
		}
	}
	
	
	return(tmp);
}
