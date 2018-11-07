#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **MODIFIED**, and becomes the
//              sorted list.
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, list becomes NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   error encountered
//                DLL_INVALID: list does not exist
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t  sortlist(List **myList, int mode)
{
	int    size = 1;
	int    i    = 0;
	code_t code = 0;
	Node  *tmp  = NULL;
	Node  *tmp2 = NULL;
	Node  *tmp3 = NULL;
	Node  *tmp4 = NULL;

	if (mode > 2)
	{
		mode = mode % 3;
	}

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
		*myList = NULL;
		code = DLL_EMPTY | DLL_ERROR;
	}
	else if ((*myList) -> lead == (*myList) -> last)
	{
		// do nothing but set code
		code = DLL_SUCCESS;
	}
	// pretty much copied pasted my last sort code, its just bubble sort-ish swap
	else if (mode == 0)
	{
		tmp = (*myList) -> lead;
		while (tmp != NULL)
		{
			tmp = tmp -> right;
			size++;
		}

		for (i = 0; i < size; i++)
		{
			tmp  = (*myList) -> lead;
			tmp2 = tmp -> right;
			if (tmp -> VALUE > tmp2 -> VALUE)
			{
				swapnode(myList, tmp, tmp2);
				tmp3 = tmp2;
				tmp2 = tmp2 -> right;
				tmp  = tmp3;
			}

			while (tmp2 -> right != NULL)
			{
				tmp = tmp -> right;
				tmp2 = tmp2 -> right;
				if (tmp -> VALUE > tmp2 -> VALUE)
				{
					swapnode(myList, tmp, tmp2);
					tmp3 = tmp2;
					tmp2 = tmp2 -> right;
					tmp  = tmp3;
				}
			}
		}
		code = DLL_SUCCESS;
	}
	else if (mode == 1)
	{
		tmp = (*myList) -> lead;
		while (tmp != NULL)
		{
			tmp = tmp -> right;
			size++;
		}
		
		for (i = 0; i < size; i++)
		{
			tmp  = (*myList) -> lead;
			tmp2 = tmp -> right;
			if (tmp -> VALUE < tmp2 -> VALUE)
			{
				swapnode(myList, tmp, tmp2);
				tmp3 = tmp2;
				tmp2 = tmp2 -> right;
				tmp  = tmp3;
			}

			while (tmp2 -> right != NULL)
			{
				tmp = tmp -> right;
				tmp2 = tmp2 -> right;
				if (tmp -> VALUE < tmp2 -> VALUE)
				{
					swapnode(myList, tmp, tmp2);
					tmp3 = tmp2;
					tmp2 = tmp2 -> right;
					tmp  = tmp3;
				}
			}
		}
		code = DLL_SUCCESS;
	}
	else if (mode == 2)
	{
		tmp = (*myList) -> lead;
		while (tmp != NULL)
		{
			tmp = tmp -> right;
			size++;
		}
		tmp  = (*myList) -> lead;
		tmp2 = (*myList) -> last;
		for (i = 0; i < size / 2; i++)
		{
			tmp3 = tmp  -> right;
			tmp4 = tmp2 -> left;
			swapnode(myList, tmp, tmp2);
			tmp  = tmp3;
			tmp2 = tmp4;
		}
		code = DLL_SUCCESS;
	}

    return(code);
}
