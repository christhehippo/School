#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//  mktree() - allocate, initialize, and return a pointer to the newly
//             created tree.
//
//       note: the second parameter is to be the created tree's
//             maximum height (bound).
//
//     height: a height of 0 indicates an unbounded tree
//             > 0 will limit the total number of levels in the tree
//
//status code: this function can generate the following status codes:
//                 DLT_SUCCESS:     no problems encountered
//                 DLT_EMPTY:       result of normal operation
//                 DLT_CREATE_FAIL: error on creation (malloc-
//                                  related or already exists)
//                 DLT_NULL:        tree remains in NULL state
//                 DLT_ERROR:       an error has taken place
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t mktree(Tree **newTree, uc height)
{
	code_t code = 0;

	if (newTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (*newTree != NULL)
	{
		code = DLT_ERROR | DLT_CREATE_FAIL;
	}
	else 
	{
		*newTree       = (Tree *)malloc(sizeof(Tree) * 1);
		if (*newTree  == NULL)
		{
			code       = DLT_ERROR | DLT_CREATE_FAIL; 
		}
		else
		{
			(*newTree) -> root       = NULL;
			(*newTree) -> max_height = height;
			code       = DLT_EMPTY | DLT_SUCCESS;
		}
	}
	
	return (code);
}
