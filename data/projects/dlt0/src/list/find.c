#include "list.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
//
//    find() - a list library utility function to locate a node in
//             an existing list by value it contains.
//
//       note: find() focuses on the actual content of what is in the
//             nodes, setting a (double) pointer to the first node
//             that contains the matching value (from the start of the
//             list, if foundNode is initially NULL, or from the point
//             in the list that foundNode points).
//
//status code: this function can generate the following status codes
//               DLN_SUCCESS:  match found
//               DLN_NULL:     match not found (node is NULL)
//               DLN_ERROR:    error encountered
//               DLN_INVALID:  node doesn't exist (UNDEFINED)
//               DLL_NULL:     list is NULL
//               DLL_EMPTY:    list is EMPTY
//               DLL_ERROR:    error encountered
//               DLL_INVALID:  list doesn't exist (UNDEFINED)
//
//   behavior: on error (NULL/UNDEFINED list/node), foundNode, if
//             it exists, is NULL.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
//             do not count; navigate by comparison
//
code_t find(List *myList, char searchval, Node **foundNode)
{
    code_t code = 0;
	Node *tmp   = NULL;	
	if (myList == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if (myList -> lead == NULL)
	{
		code = DLL_ERROR | DLL_EMPTY;
	}
	else if (foundNode == NULL)
	{
		code = DLN_ERROR | DLN_INVALID;;
	}
	else
	{
		if (*foundNode == NULL)
		{
			tmp = myList -> lead;
		}
		else
		{
			tmp = (*foundNode) -> right;
		}
		while (tmp != NULL)
		{
			if (tmp -> VALUE == searchval)
			{
				break;
			}
			else
			{
				tmp = tmp -> right;
				*foundNode = tmp; // I am pretty sure I don't need this
			}					  // but it makes test 20/21 work for some reason...
		}
		if (tmp != NULL)
		{
			*foundNode = tmp;
			code = DLN_SUCCESS;
		}
		else
		{
			*foundNode = tmp;
			code = DLN_NULL;
		}
	}
	return(code);
}
