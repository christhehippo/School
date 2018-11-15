#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    mknode() - a node library function to allocate and initialize
//               a new node (to provided value).
//
// status codes:
//               DLN_SUCCESS:       no problems encountered
//               DLN_MALLOC_FAIL:   error on creation
//               DLN_ALREADY_ALLOC: already exists
//               DLN_NULL:          node is in NULL state
//               DLN_ERROR:         some error occurred
//               DLN_INVALID:       invalid use (NULL pointer)
//
//   suggestion: be sure to error check any allocation or query of
//               external resources; limit initialization steps to
//               only be performed in the allocation was successful.
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               if node is not in valid state, node should be set
//               to NULL.
//
code_t mknode(Node **newNode, char info)
{
	code_t code = 0;

	if (newNode == NULL)
	{
		code = DLN_INVALID | DLN_ERROR;
	}
	else if (*newNode != NULL)
	{
		code = DLN_ERROR | DLN_ALREADY_ALLOC;
	}
	else
	{
		*newNode = (Node *)malloc(sizeof(Node) * 1);
		
		if (newNode == NULL)
		{
			code = DLN_ERROR | DLN_MALLOC_FAIL;
		}
		else
		{
			code       			= DLN_SUCCESS;
			(*newNode) -> right = NULL;
			(*newNode) -> left  = NULL;
			(*newNode) -> VALUE = info;
		}
	}
    
	
	
	return(code);
}
