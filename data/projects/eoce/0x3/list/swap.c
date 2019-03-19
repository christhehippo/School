#include "list.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own first and last pointers, along with connectivity
//              between the nodes from the start to end of the list).
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
// status code: this function can generate the following status codes
//                DLN_NULL:    node is NULL
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   something is NULL or EMPTY, or other
//                             error state encountered.
//                DLL_INVALID: invalid list state
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t  swapnode(List **myList, Node *posA, Node *posB)
{
	code_t code = 0;
	Node *tmp   = NULL;
	Node *tmp2  = NULL;
	Node *tmp3  = NULL;
	Node *tmp4  = NULL;

	if (myList == NULL)
	{
		code = DLL_ERROR | DLL_INVALID;
	}
	else if (*myList == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if (posA == NULL || posB == NULL)
	{
		code = DLL_ERROR | DLN_NULL;
		if ((*myList) -> lead == NULL)
			code = code | DLL_EMPTY;
	}
	else if (posA == posB)
	{
		code = DLL_ERROR;
	}
	else if ((*myList) -> lead == NULL)
	{
		code = DLL_EMPTY | DLL_ERROR;
	}
	else if (posA -> right == posB) // x -> posA -> posB -> x
	{							   // covers 2 node conditions as well
		if (posA == (*myList) -> lead)
		{
			if (posB == (*myList) -> last)
			{
				posA -> right = NULL;
				posA -> left  = posB;
				posB -> right = posA;
				posB -> left  = NULL;
				(*myList) -> lead = posB;
				(*myList) -> last = posA;

				code = DLL_SUCCESS;
			}
			else
			{
				tmp = posB -> right;
				posA -> right = tmp;
				tmp  -> left  = posA;
				posA -> left  = posB;
				posB -> left  = NULL;
				posB -> right = posA;
				(*myList) -> lead = posB;
				code = DLL_SUCCESS;
			}
		}
		else if (posB == (*myList) -> last)
		{
			tmp = posA    -> left;
			posB -> left  = tmp;
			tmp -> right  = posB;
			posB -> right = posA;
			posA -> left  = posB;
			posA -> right = NULL;
			(*myList) -> last = posA;
			code = DLL_SUCCESS;
		}
		else // normal case where A -> B
		{
			tmp  = posA -> left;
			tmp2 = posB -> right;

			posA -> left  = posB;
			posA -> right = tmp2;
			posB -> left  = tmp;
			posB -> right = posA;
			tmp  -> right = posB;
			tmp2 -> left  = posA;

			code = DLL_SUCCESS;
		}
	}
	else if (posB -> right == posA)
	{
		if (posB == (*myList) -> lead)
		{
			if (posA == (*myList) -> last)
			{
				posB -> right = NULL;
				posB -> left  = posA;
				posA -> right = posB;
				posA -> left  = NULL;
				(*myList) -> lead = posA;
				(*myList) -> last = posA;

				code = DLL_SUCCESS;
			}
			else
			{
				tmp = posA -> right;
				posB -> right = tmp;
				tmp  -> left  = posB;
				posB -> left  = posA;
				posA -> left  = NULL;
				posA -> right = posB;
				(*myList) -> lead = posA;
				code = DLL_SUCCESS;
			}
		}
		else if (posA == (*myList) -> last)
		{
			tmp = posA    -> left;
			posB -> left  = tmp;
			tmp -> right  = posB;
			posB -> right = posA;
			posA -> left  = posB;
			posA -> right = NULL;
			(*myList) -> last = posA;
			code = DLL_SUCCESS;
		}
		else // normal case where B -> A
		{
			tmp  = posA -> left;
			tmp2 = posB -> right;

			posA -> left  = posB;
			posA -> right = tmp2;
			posB -> left  = tmp;
			posB -> right = posA;
			tmp  -> right = posB;
			tmp2 -> left  = posA;

			code = DLL_SUCCESS;
	
		}
	}
	else if (posA == (*myList) -> lead || posB == (*myList) -> lead)
	{
		if (posA == (*myList) -> lead)
		{
			if (posB == (*myList) -> last)
			{
				tmp  = posA -> right;
				tmp2 = posB -> left;

				posA -> right = NULL;
				posA -> left  = tmp2;
				tmp2 -> right = posA;
				posB -> left  = NULL;
				posB -> right = tmp;
				tmp  -> left  = posB;
				(*myList) -> lead = posB;
				(*myList) -> last = posA;

				code = DLL_SUCCESS;
			}
			else
			{
				tmp  = posA -> right;
				tmp2 = posB -> left;
				tmp3 = posB -> right;

				posA -> left  = tmp2;
				tmp2 -> right = posA;
				posA -> right = tmp3;
				tmp3 -> left  = posA;
				posB -> left  = NULL;
				posB -> right = tmp;
				tmp  -> left  = posB;
				(*myList) -> lead = posB;

				code = DLL_SUCCESS;
			}
		}
		else if (posB == (*myList) -> lead)
		{
			if (posA == (*myList) -> last)
			{
				tmp  = posB -> right;
				tmp2 = posA -> left;

				posB -> right = NULL;
				posB -> left  = tmp2;
				tmp2 -> right = posB;
				posA -> left  = NULL;
				posA -> right = tmp;
				tmp  -> left  = posA;
				(*myList) -> lead = posA;
				(*myList) -> last = posB;

				code = DLL_SUCCESS;
			}
			else
			{
				tmp  = posB -> right;
				tmp2 = posA -> left;
				tmp3 = posA -> right;

				posB -> left  = tmp2;
				tmp2 -> right = posB;
				posB -> right = tmp3;
				tmp3 -> left  = posB;
				posA -> left  = NULL;
				posA -> right = tmp;
				tmp  -> left  = posA;
				(*myList) -> lead = posA;

				code = DLL_SUCCESS;
			}
		}
	}
	else if (posA == (*myList) -> last || posB == (*myList) -> last)
	{
		if (posA == (*myList) -> last)
		{
			tmp  = posB -> left;
			tmp2 = posB -> right;
			tmp3 = posA -> left;

			posA -> left  = tmp;
			tmp  -> right = posA;
			posA -> right = tmp2;
			tmp2 -> left  = posA;
			posB -> left  = tmp3;
			tmp3 -> right = posB;
			posB -> right = NULL;
			(*myList) -> last = posB;

			code = DLL_SUCCESS;
		}
		else if (posB == (*myList) -> last)
		{
			tmp  = posA -> left;
			tmp2 = posA -> right;
			tmp3 = posB -> left;

			posB -> left  = tmp;
			tmp  -> right = posB;
			posB -> right = tmp2;
			tmp2 -> left  = posB;
			posA -> left  = tmp3;
			tmp3 -> right = posA;
			posA -> right = NULL;
			(*myList) -> last = posA;

			code = DLL_SUCCESS;
		}
	}
	else // anything else, should all be normal cases
	{
		tmp  = posA -> left;
		tmp2 = posA -> right;
		tmp3 = posB -> left;
		tmp4 = posB -> right;

		posA -> left  = tmp3;
		tmp3 -> right = posA;
		posA -> right = tmp4;
		tmp4 -> left  = posA;
		posB -> left  = tmp;
		tmp  -> right = posB;
		posB -> right = tmp2;
		tmp2 -> left  = posB;
		
		code = DLL_SUCCESS;
	}
	
	return(code);
}
