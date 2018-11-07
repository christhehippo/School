#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  mklist() - allocate, initialize, and return a pointer to the
//             newly allocated and initialized list struct.
//
//status code: this function generates the following status codes:
//               DLL_SUCCESS:       no problems encountered
//               DLL_EMPTY:         result of normal operation
//               DLL_MALLOC_FAIL:   error on creation
//               DLL_ALREADY_ALLOC: list pointer already allocated
//               DLL_NULL:          list remains in NULL state
//               DLL_ERROR:         an error has taken place
//
//             be sure you perform any necessary error checking,
//             and that any and all struct members are appropriately
//             initialized.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
code_t mklist(List **newList)
{
    code_t code = 0;
	
	if (newList == NULL)
	{
		code = DLL_ERROR | DLL_INVALID;
	}
	else if (*newList != NULL)
	{
		code = DLL_ERROR | DLL_ALREADY_ALLOC;
	}
	else
	{
		*newList = (List *)malloc(sizeof(List) * 1);

		if (newList == NULL)
		{
			code = DLL_ERROR | DLL_MALLOC_FAIL;
		}
		else
		{
			code = DLL_SUCCESS | DLL_EMPTY;
		}

		(*newList) -> lead = NULL;
		(*newList) -> last = NULL;
		(*newList) -> qty  = 0;
	}
	return(code);
}
