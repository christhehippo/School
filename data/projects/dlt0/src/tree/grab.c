#include "tree.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
//
//grabnode()  - grab node out of indicated tree, ensuring integrity
//              is maintained (tree is modified)
//              
// status code: this function can generate the following status codes
//                  DLT_SUCCESS: normal operation
//                  DLT_EMPTY:   tree is now EMPTY after grabnode_r()
//                  DLT_NULL:    tree is NULL
//                  DLT_ERROR:   error occurred (tree is NULL,
//                               tried to grab from an empty tree)
//
//              The key with getting a node out of the tree is 
//              that, in many cases, you are removing a parent;
//              so, what takes its place?
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t grabnode(Tree **myTree, Node **newNode)
{
	code_t code = 0;
	Node  *tmp  = NULL;
	Node  *tmp2 = NULL;

	if (myTree == NULL)
	{
		code = DLT_ERROR | DLT_INVALID;
	}
	else if (*myTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if ((*myTree) -> root == NULL)
	{
		code = DLT_ERROR | DLT_EMPTY;
	}
	else
	{
		tmp  = (*myTree) -> root;
		tmp2 = (*newNode);
		
		if ((*myTree) -> root == tmp2)
		{
			if (tmp -> left == NULL && tmp -> right == NULL)
			{
				(*myTree) -> root = NULL;
				code = DLT_EMPTY | DLT_SUCCESS;
			}
			else if (tmp -> left == NULL && tmp -> right != NULL)
			{
				(*myTree) -> root = tmp -> right;
				code = DLT_SUCCESS;
			}
			else if (tmp -> right == NULL && tmp -> left != NULL)
			{
				(*myTree) -> root = tmp -> left;
				code = DLT_SUCCESS;
			}
			else
			{
				tmp = (*myTree) -> root -> left;
				while (tmp -> right != NULL)
				{
					tmp2 = tmp;
					tmp  = tmp -> right;
				}
				if ((*myTree) -> root -> left == tmp)
				{
					tmp -> right = (*myTree) -> root -> right;
					tmp -> left  = (*myTree) -> root -> left -> left;
					(*myTree) -> root -> left = (*myTree) -> root -> right = NULL;
					(*myTree) -> root = tmp;
				}
				else
				{
					tmp2 -> right = NULL;
					tmp -> right = (*myTree) -> root -> right;
					tmp -> left  = (*myTree) -> root -> left;
					(*myTree) -> root = tmp;
				}
				code = DLT_SUCCESS;
			}
		}
		else
		{
			if ((*newNode) -> left == NULL && (*newNode) -> right == NULL)
			{
				if ((*myTree) -> root -> left == (*newNode))
				{
					(*myTree) -> root -> left = NULL;
				}
				else if ((*myTree) -> root -> right == (*newNode))
				{
					(*myTree) -> root -> right = NULL;
				}
				else
				{

				}
			}
			else
			{
				while (tmp != (*newNode))
				{
					if (tmp -> VALUE <= (*newNode) -> VALUE)
					{
						tmp2 = tmp;
						tmp = tmp -> right;
					}
					else 
					{
						tmp2 = tmp;
						tmp = tmp -> left;
					}
				}
				if (tmp -> left == NULL && tmp -> right != NULL)
				{
					tmp2 -> right = tmp -> right;
				}
				else if (tmp -> left != NULL && tmp -> right == NULL)
				{
					tmp2 -> left = tmp -> left;
				}
				else if (tmp -> left != NULL && tmp -> right != NULL)
				{
					tmp -> VALUE = tmp -> right -> VALUE;
					tmp -> right = NULL;
				}
				code = DLT_SUCCESS;
			}
		}
		
	}
	
	return (code);
}

