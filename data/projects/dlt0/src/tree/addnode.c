#include "tree.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
//
// addnode()   - place newNode into indicated tree at proper position.
//
//  status code: this function can generate the following status codes
//                  DLT_SUCCESS:  normal operation (success!)
//                  DLT_NULL:     tree is NULL
//                  DLT_MAX:      tried to add onto a full bounded
//                                tree (considered an error)
//                  DLT_ERROR:    error encountered
//                  DLT_INVALID:  tree pointer doesn't exist
//
//         note: a max_height of 0 indicates an unbounded tree
//              
//  assumptions: duplicate values are allowed;
//               nodes with values less than or equal to that of
//               an analyzed node are placed to the left,
//               where greater than are placed to the right.
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t addnode(Tree **myTree, Node *newNode)
{
	int     height      = 0;
	int     max_height  = 0;
	code_t code        = 0;
	Node  *tmp    	   = NULL;
	Node  *tmp2        = NULL;

	if (myTree        == NULL)
	{
		code = DLT_ERROR | DLT_INVALID;
	}
	else if (*myTree  == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (newNode  == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if ((*myTree) -> root == NULL)
	{
		(*myTree) -> root = newNode;
		(*myTree) -> root -> left = (*myTree) -> root -> right = NULL;
		code = DLT_SUCCESS;
	}
	else
	{
		max_height = (int)((*myTree) -> max_height); // saves some typing space
		if (max_height == 0)
			max_height = 254;

		newNode -> left = newNode -> right = NULL;
		// check if single node
		if ((*myTree) -> root -> right == (*myTree) -> root -> left)
		{ // this condition is a shorter way of checking for null
			if (newNode -> VALUE <= (*myTree) -> root -> VALUE)
			{
				(*myTree) -> root -> left = newNode;
				code = DLT_SUCCESS;
			}
			else
			{
				(*myTree) -> root -> right  = newNode;
				code = DLT_SUCCESS;
			}
		}
		else if (newNode -> VALUE <= (*myTree) -> root -> VALUE && (*myTree) -> root -> left == NULL)
		{
			(*myTree) -> root -> left = newNode;
			code = DLT_SUCCESS;
		}
		else if (newNode -> VALUE > (*myTree) -> root -> VALUE && (*myTree) -> root -> right == NULL)
		{
			(*myTree) -> root -> right = newNode;
			code = DLT_SUCCESS;
		}
		else
		{
			tmp    = tmp2 = (*myTree) -> root;
			height = 0;
			while (tmp != NULL) // find the proper ending spot
			{
				if (height >= max_height)
				{
					code   = DLT_ERROR | DLT_MAX;
					height = 255;
					tmp    = NULL;
					tmp2   = NULL;
				} 
				else if (newNode -> VALUE <= tmp -> VALUE)
				{
					tmp2 = tmp; 
					tmp  = tmp -> left;
					height++;
				}
				else if (newNode -> VALUE > tmp -> VALUE)
				{
					tmp2 = tmp;
					tmp  = tmp -> right;
					height++;
				}
			}
			// insert node now
			/////// WHY DOES THIS CONDITION SEG FAULT??????
//			if (height < max_height)
			if (tmp2 != NULL)
			{
				if (newNode -> VALUE <= tmp2 -> VALUE) 
				{
					tmp2 -> left = newNode;
					code = DLT_SUCCESS;
				}
				else 
				{
					tmp2 -> right = newNode;
					code = DLT_SUCCESS;
				}
			}
			else
			{
				code = DLT_ERROR | DLT_MAX;
			}
		}
	}

	return (code);
}
