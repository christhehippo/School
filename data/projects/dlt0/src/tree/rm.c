#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//   rmtree() - unset, nullify members, and de-allocate the given 
//              tree.
//
//              be sure to utilize existing list and tree library
//              functions to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                  DLT_SUCCESS: no problems encountered
//                  DLT_NULL:    normal operation
//                  DLT_ERROR:   error encountered (or tree was
//                               already NULL)
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t rmtree(Tree **curTree)
{
	code_t code 	= 0;
	Node  *tmp  	= NULL;
	Node  *tmp2     = NULL;
	List  *result   = NULL;

	if (curTree == NULL)
	{
		code = DLT_ERROR;
	}
	else if (*curTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;	
	}
	else if ((*curTree) -> root == NULL)
	{
		free(*curTree);
		*curTree = NULL;
		code = DLT_NULL | DLT_SUCCESS;
	}
	else
	{
		traverse_r(*curTree, &result, 0);
		tmp = result -> lead -> right;
		while (tmp != NULL)
		{
			tmp2 = NULL;
			searchtree(*curTree, &tmp2, tmp -> VALUE);
			grabnode(curTree, &tmp2);
			rmnode(&tmp2);
			tmp = tmp -> right;
		}
		tmp2 = (*curTree) -> root;
		(*curTree) -> root = NULL;
		free(tmp2);
		*curTree = NULL;

		code = DLT_SUCCESS | DLT_NULL;
	}

	return(code);
}
