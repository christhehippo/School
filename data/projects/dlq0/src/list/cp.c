#include "list.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
//
//    cplist() - duplicate a given list (especially the state of
//               its contents), in a new list.
//
//               be sure to utilize existing list and node library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS:       normal operation
//                 DLL_ALREADY_ALLOC: *newList already exists
//                 DLL_EMPTY:         cur & ending *newList are EMPTY
//                 DLL_NULL:          oldList or *newList are NULL
//                 DLL_ERROR:         an error was encountered
//                 DLL_INVALID:       newList doesn't exist
//
//               as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t cplist(List *oldList, List **newList)
{
    code_t code = 0;
	Node *tmp   = NULL;
	Node *tmp2  = NULL;
	Node *tmp3  = NULL;
	if (newList == NULL)
	{
		code = DLL_INVALID | DLL_ERROR;
	}
	else if (oldList == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if (*newList != NULL)
	{
		code = DLL_ALREADY_ALLOC | DLL_ERROR;
	}
	else if (oldList -> lead == NULL)
	{
		mklist(newList);
		code = DLL_SUCCESS | DLL_EMPTY;
	}
	else if (oldList -> lead == oldList -> last)
	{
		mklist(newList);
		tmp = oldList -> lead;
		cpnode(tmp, &tmp2);
		(*newList) -> lead = tmp2;
		(*newList) -> last = tmp2;
		code = DLL_SUCCESS;
	}
	else if (oldList -> lead -> right == oldList -> last)
	{
		mklist(newList);
		tmp  = oldList -> lead;
		cpnode(tmp, &tmp2);
		(*newList) -> lead = tmp2;
		tmp = oldList -> last;
		cpnode(tmp, &tmp3);
		(*newList) -> last = tmp3;
		tmp2 -> right = tmp3;
		tmp3 -> left  = tmp2;
		code = DLL_SUCCESS;
	}
	else
	{
		mklist(newList);
		tmp = oldList -> lead;
		append(newList, NULL, tmp);
		tmp2 = tmp -> right;
		while (tmp2 != NULL)
		{
			append(newList, tmp, tmp2);
			tmp  = tmp2;
			tmp2 = tmp2 -> right;
		}
		code = DLL_SUCCESS;
	}
	return (code);
}
