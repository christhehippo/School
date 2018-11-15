#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//  rmstack() - unset, nullify members, and de-allocate the given 
//              stack.
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    stack data element is NULL
//                  DLS_SUCCESS: no problems encountered
//                  DLS_NULL:    normal operation
//                  DLS_INVALID: stack does not exist
//                  DLS_ERROR:   error encountered (or stack was
//                               already NULL)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t rmstack(Stack **oldStack)
{
    code_t code = 0;
	List  *list = NULL;

	if (oldStack  == NULL)
	{
		code = DLS_INVALID | DLS_ERROR;
	}
	else if (*oldStack == NULL)
	{
		code = DLS_NULL | DLS_ERROR;
	}
	else
	{
		list = (*oldStack) -> data;
		rmlist(&list);
		(*oldStack) -> data = NULL;
		(*oldStack) -> top  = NULL;
		free(*oldStack);
		*oldStack = NULL;
		code = DLS_NULL | DLS_SUCCESS | DLL_NULL | DLL_SUCCESS;
	}
	return(code);
}
