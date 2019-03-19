#include "tree.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
//
//traverse_i()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_i() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              an iterative approach will be one to conform to a
//              more detail-oriented approach- loops. Also think of
//              it as the "naive" approach- if, once understanding
//              the task to be done, you set out to implement it
//              without trying to reference any existing approaches;
//              Especially an approach prior to gaining more
//              experience with recursion, and any experience with
//              stacks.
//
//              traverse_i() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_ERROR:       an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t traverse_i(Tree *myTree, List **result, uc mode)
{
	code_t code   = 0;
	Node  *tmp    = NULL;
	Node  *tmp2   = NULL;
	Node  *tmp3   = NULL;
	Node  *tmp4   = NULL;
	Node  *write  = NULL;


	if (myTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (result == NULL)
	{
		code = DLT_ERROR | DLL_INVALID;
	}
	else if (mode > 2)
	{
		code = DLT_ERROR;
		if (*result != NULL)
			code = code | DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_EMPTY;
	}
	else if (*result != NULL)
	{
		code = DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_ERROR | DLT_EMPTY;
	}
	else if (myTree -> root == NULL) // empty tree
	{
		code = mklist(result);
		code = code | DLT_SUCCESS | DLT_EMPTY;
	}
	else
	{
		mklist(result);

		if (mode == 0) // inorder
		{
			tmp = myTree -> root;
			mknode(&write, tmp -> VALUE);
			append(result, (*result) -> last, write);
			
			while (tmp -> left != NULL)
			{
				tmp2  = tmp; 
				tmp   = tmp -> left;
				write = NULL;
				mknode(&write, tmp -> VALUE);
				append(result, (*result) -> last, write);
			}
			
			while (tmp -> left != NULL)
				tmp = tmp -> left;
			
			while (tmp != myTree -> root)
			{
				if (tmp -> right != NULL)
				{
					tmp2 = tmp -> right;
					write = NULL;
					mknode(&write, tmp2 -> VALUE);
					append(result, (*result) -> last, write);
				}
				tmp2 = tmp;
				tmp = myTree -> root;
				while (tmp -> left != tmp2)
					tmp = tmp -> left;
			}
			tmp = myTree -> root;
			while (tmp -> right != NULL)
			{
				tmp = tmp -> right;
				write = NULL;
				mknode(&write, tmp -> VALUE);
				append(result, (*result) -> last, write);
			}

			code = DLT_SUCCESS;
		}
		else if (mode == 1)
		{
			tmp = myTree -> root;
			while (tmp -> left != NULL)
			{
				tmp2 = tmp;
				tmp  = tmp -> left;
			}

			while (tmp != myTree -> root)
			{
				if (tmp4 != NULL)
					tmp2 = tmp4;

				write = NULL;
				mknode(&write, tmp -> VALUE);
				append(result, (*result) -> last, write);

				if (tmp -> right != NULL)
				{
					tmp3 = tmp -> right;
					write = NULL;
					mknode(&write, tmp3 -> VALUE);
					append(result, (*result) -> last, write);
				}

				tmp = myTree -> root;
				while (tmp != tmp2)
				{
					tmp4 = tmp;
					tmp  = tmp -> left;
				}	
			}
			tmp = myTree -> root;
			write = NULL;
			mknode(&write, tmp -> VALUE);
			append(result, (*result) -> last, write);

			while (tmp -> right != NULL)
			{
				tmp = tmp -> right;
				write = NULL;
				mknode(&write, tmp3 -> VALUE);
				append(result, (*result) -> last, write);
			}
			code = DLT_SUCCESS;
		}
		// this is really strange without stack and recursion
		else if (mode == 2)
		{
			tmp = myTree -> root;
			while (tmp -> right != NULL)
			{
				tmp2 = tmp;
				tmp  = tmp -> right;
			}
			write = NULL;
			mknode(&write, tmp -> VALUE);
			append(result, (*result) -> last, write);
			write = NULL;
			mknode(&write, tmp2 -> VALUE);
			append(result, (*result) -> last, write);

			tmp = myTree -> root;
			while (tmp -> left != NULL)
			{
				tmp = tmp -> left;
				if (tmp -> right != NULL)
				{
					tmp2 = tmp -> right;
					write = NULL;
					mknode(&write, tmp2 -> VALUE);
					append(result, (*result) -> last, write);
				}
				write = NULL;
				mknode(&write, tmp -> VALUE);
				append(result, (*result) -> last, write);
			}	
			code = DLT_SUCCESS;
		}
	}

	return(code);
}
