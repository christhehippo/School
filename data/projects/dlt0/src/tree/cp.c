#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//  cptree()   - duplicate a given tree (especially the state of
//               its contents), in a new tree.
//
//  status code: this function can generate the following status code
//                 DLT_SUCCESS:     normal operation
//                 DLT_CREATE_FAIL: *newTree already exists
//                 DLT_EMPTY:       curTree and *newTree are EMPTY
//                 DLT_NULL:        curTree or *newTree is NULL
//                 DLT_ERROR:       a failure was encountered
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t cptree(Tree *curTree, Tree **newTree)
{
	code_t code   = 0;
	Node  *tmp    = NULL;
	Node  *tmp2   = NULL;
	List  *result = NULL;

	if (curTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (newTree == NULL)
	{
	
	}
	else if (*newTree != NULL)
	{
		code = DLT_CREATE_FAIL | DLT_ERROR;
	}
	else if (curTree -> root == NULL)
	{
		mktree(newTree, curTree -> max_height);
		code = DLT_SUCCESS | DLT_EMPTY | DLL_EMPTY;
	}
	else
	{
		mktree(newTree, curTree -> max_height);
		traverse_r(curTree, &result, 0); // glad i noticed this 
		tmp = result -> lead;
		while (tmp != NULL)
		{
			tmp2 = NULL;
			mknode(&tmp2, tmp -> VALUE);
			addnode(newTree, tmp2);
			tmp = tmp -> right;
		}

		code = DLT_SUCCESS;
	}
	
	return (code);
}
