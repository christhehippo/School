#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
// mkstack() - allocate, initialize, and return a pointer to
//             the newly created stack.
//
//       note: the second parameter is to be the created stack's
//             maximum size (upper bound).
//
//             be sure to utilize existing list and stack library
//             functions to facilitate your implementation. Do NOT
//             reinvent the wheel.
//
//             the top of the stack should follow the last node in
//             its underlying list.
//
//       size: a stack size of 0 will indicate an unbounded stack
//             > 0 will limit the total number of nodes in the stack
//
//   behavior: in the event of an existing yet non-NULL newStack,
//             just fall though (do nothing), and generate the
//             appropriate status code(s).
//
//status code: this function can generate the following status codes:
//                 DLL_SUCCESS:     normal operations
//                 DLL_EMPTY:       result of normal operation
//                 DLS_SUCCESS:     normal operations
//                 DLS_EMPTY:       result of normal operation
//                 DLS_CREATE_FAIL: error on creation
//                 DLS_NULL:        stack remains in NULL state
//                 DLS_ERROR:       an error has taken place
//                 DLS_INVALID:     stack does not exist
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
code_t mkstack(Stack **newStack, ulli size)
{
	code_t code = 0;
	List  *list = NULL;

	if (newStack == NULL)
	{
		code = DLS_ERROR | DLS_INVALID;
	}
	else if (*newStack != NULL)
	{
		code = DLS_ERROR | DLS_CREATE_FAIL;
	}
	else
	{
		(*newStack) = (Stack *)malloc(sizeof(Stack) * 1);
		if ((*newStack) == NULL)
			code = DLS_ERROR | DLS_CREATE_FAIL;
		else
			code = DLS_SUCCESS | DLS_EMPTY | DLL_EMPTY | DLL_SUCCESS;

		(*newStack) -> size = size;
		mklist(&list);
		(*newStack) -> data = list;
	}
	return(code);
}
