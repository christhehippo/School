#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//     empty() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               empty().
//
//               be sure to utilize existing list and node library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS: everything went according to plan
//                 DLL_EMPTY:   list is now empty (normal operation)
//                 DLL_NULL:    *myList is NULL
//                 DLL_ERROR:   a failure was encountered, NULL
//                 DLL_INVALID: invalid condition (myList NULL)
//
//               as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t  empty(List **myList)
{
	code_t code  = 0;
	Node *tmp    = NULL;
	Node *tmp2   = NULL;

	if (myList == NULL)
	{
		code = DLL_ERROR | DLL_INVALID;
	}
	else if (*myList == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if ((*myList) -> lead == NULL)
	{
		code = DLL_SUCCESS | DLL_EMPTY;
	}
	else
	{
		tmp = (*myList) -> lead;
		while (tmp != NULL)
		{
			tmp2    = tmp -> right;
			obtain(myList, &tmp);
			tmp     = tmp2;
		}
		code = DLL_SUCCESS | DLL_EMPTY;
	}





    return(code);
}
