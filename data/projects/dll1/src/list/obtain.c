#include "list.h"
//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//error states: NULL or EMPTY initial list, NULL thatNode. In such a
//              case, do not modify the list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:    *thatNode is NULL
//                  DLN_INVALID: thatNode is NULL
//                  DLN_ERROR:   *thatNode not in list
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    list is NULL
//                  DLL_ERROR:   error encountered (any error)
//                  DLL_INVALID: cannot proceed (myList is NULL)
//                  DLL_EMPTY:   list is EMPTY (not directly an
//                               error, although likely is associated
//                               with error condition)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t  obtain(List **myList, Node **thatNode)
{
	int    flag = 0;
	code_t code = 0;
	Node  *tmp  = NULL;
	Node  *tmp2 = NULL;
	Node  *tmp3 = NULL;

	if (myList == NULL)
	{
		code = DLL_ERROR | DLL_INVALID;
	}
	else if (thatNode == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if (*myList == NULL)
	{
		code = DLL_ERROR | DLL_NULL;
	}
	else if (*thatNode == NULL)
	{
		code = DLL_EMPTY | DLL_ERROR;
	}
	else if ((*myList) -> lead == NULL)
	{
		code = DLL_ERROR | DLL_EMPTY;
	}
	else if ((*myList) -> lead == (*myList) -> last)
	{
		(*myList) -> lead = (*myList) -> last = NULL;
		code = DLL_SUCCESS | DLL_EMPTY;
	}
	else if ((*myList) -> lead -> right == (*myList) -> last)
	{
		if ((*myList) -> lead == *thatNode)
		{
			tmp  = (*myList) -> last;
			tmp2 = (*myList) -> lead;
			tmp  -> right = tmp  -> left = NULL;
			tmp2 -> right = tmp2 -> left = NULL;
			(*myList) -> lead = (*myList) -> last;
			code = DLL_SUCCESS; 
		}
		else if ((*myList) -> last == *thatNode)
		{
			tmp  = (*myList) -> lead;
			tmp2 = (*myList) -> last;
			tmp  -> right = tmp  -> left = NULL;
			tmp2 -> right = tmp2 -> left = NULL;
			(*myList) -> last = (*myList) -> lead;
			code = DLL_SUCCESS;
		}
	}
	else
	{
		// check if node is in list
		tmp = (*myList) -> lead;
		while (tmp != NULL)
		{
			if (tmp == *thatNode)
			{
				flag = 1;
				break;
			}
			else
			{
				tmp = tmp -> right;
			}	
		}

		if (flag == 0)
		{
			code = DLL_ERROR;
		}
		else if (flag == 1)
		{
			if (*thatNode == (*myList) -> lead)
			{
				tmp  = (*myList) -> lead;
				tmp2 = 		 tmp -> right;
				tmp  -> right = tmp -> left = NULL; // set right/left toNULL
				tmp2 -> left  = NULL;
				(*myList) -> lead = tmp2;
			}
			else if (*thatNode == (*myList) -> last)
			{
				tmp  = (*myList)  -> last;
				tmp2 = 		  tmp -> left;
				tmp -> left = tmp -> right = NULL;
				(*myList) -> last = tmp2;
				tmp2 -> right = NULL;
			}
			else
			{
				tmp  = (*thatNode)  -> left; // tmp -> tmp2 -> tmp3
				tmp2 = tmp          -> right;
				tmp3 = tmp2         -> right;
				tmp  -> right  	    = tmp3;
				tmp3 -> left 	    = tmp;
				tmp2 -> left = tmp2 -> right = NULL;
			}
			
			code = DLL_SUCCESS;
		}
	}
    return(code);
}
