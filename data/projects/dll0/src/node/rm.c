#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    rmnode() - a node library function to clear and deallocate an 
//               existing node
//
// status codes:
//               DLN_SUCCESS: no problems encountered
//               DLN_NULL:    node in NULL state
//               DLN_ERROR:   some error occurred
//               DLN_INVALID: invalid use (NULL pointer)
//
//   suggestion: avoid deallocating an already NULL or non-existant
//               node; do proper error checking!
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               be sure to explicitly set the node to NULL after
//               performing all necessary steps (but don't JUST
//               set it NULL- clear and deallocate first).
//
code_t rmnode(Node **curNode)
{
    code_t code = 0;

	if (curNode == NULL)
	{
		code = DLN_ERROR | DLN_INVALID;
	}
	else if (*curNode == NULL)
	{
		code = DLN_ERROR | DLN_NULL;
	}
	else
	{
		(*curNode) -> left = (*curNode) -> right = NULL;
		(*curNode) -> DATA = (*curNode) -> OTHER = NULL;
		free(*curNode);
		*curNode = NULL;
		code = DLN_NULL | DLN_SUCCESS;
	}


	
	return(code);
}
