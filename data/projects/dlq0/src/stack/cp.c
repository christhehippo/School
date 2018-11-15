#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//   cpstack() - duplicate a given stack (especially the state of
//               its contents), in a new stack.
//
//     behavior: in the event of an existing yet non-NULL newStack,
//               just fall though (do nothing), and generate the
//               appropriate status code(s).
//
//               be sure to utilize existing list and stack library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//               the top of the stack should follow the last node in
//               its underlying list.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS:     normal operation
//                 DLL_EMPTY:       stack data element is empty
//                 DLS_SUCCESS:     normal operation
//                 DLS_CREATE_FAIL: *newStack already exists
//                 DLS_EMPTY:       stack is EMPTY
//                 DLS_NULL:        stack is NULL
//                 DLS_ERROR:       a failure was encountered
//                 DLS_INVALID:     stack does not exist
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t cpstack(Stack *curStack, Stack **newStack)
{
    code_t code = 0;
	List  *list = NULL;
	List *clist = NULL;

	if (curStack == NULL)
	{
		code = DLS_ERROR | DLS_NULL;
	}
	else if (newStack == NULL)
	{
		code = DLS_INVALID | DLS_ERROR;
	}
	else if (*newStack != NULL)
	{
		code = DLS_ERROR | DLS_CREATE_FAIL;
	}
	else if (curStack -> top == NULL)
	{
		mkstack(newStack, curStack -> size);
		code = DLS_EMPTY | DLS_SUCCESS | DLL_EMPTY | DLL_SUCCESS;
	}
	else
	{
		mkstack(newStack, curStack -> size);
		list  = curStack -> data;
		code = cplist(list, &clist);
		(*newStack) -> data = clist;
		(*newStack) -> top = (*newStack) -> data -> last;
		code = code | DLS_SUCCESS;
	}

	return (code);
}
