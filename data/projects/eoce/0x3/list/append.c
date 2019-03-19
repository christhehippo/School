#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the first and last
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: do NOT create a list if NULL
//
// status code: this function can generate the following status codes
//                DLN_NULL:    newNode is NULL
//                DLN_ERROR:   place or newNode NULL (list not EMPTY)
//                DLL_SUCCESS: normal operation (success!)
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list ends up EMPTY
//                DLL_ERROR:   error encountered
//                DLL_INVALID: invalid condition (place not in list)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t append(List **myList, Node *place, Node *newNode)
{
	int    flag = 0;
    code_t code = 0;
	Node *tmp   = NULL;
	Node *tmp2  = NULL;
	if (myList == NULL)
	{
		code    = DLL_ERROR | DLL_INVALID;
	}
	else if (*myList == NULL)
	{
		code	= DLL_ERROR | DLL_NULL;
	}
	else if ((*myList) -> lead == NULL)
	{
		if (newNode == NULL)
		{
			code 	= DLL_EMPTY | DLL_ERROR | DLN_NULL;
		}
		else
		{
			(*myList) -> lead = (*myList) -> last = newNode;
			(*myList) -> qty += 1;
			code = DLL_SUCCESS;
		}
	}
	else if (newNode == NULL)
	{
		code = DLN_NULL | DLL_ERROR;
	}
	else if (place == (*myList) -> last)
	{
		tmp = (*myList) -> last;
		(*myList) -> last = newNode;
		tmp -> right = (*myList) -> last;
		(*myList) -> last -> left = tmp;
		code = DLL_SUCCESS;
		(*myList) -> qty += 1;
	}
	else if (place == NULL)
	{
		code = DLL_INVALID | DLL_ERROR | DLN_ERROR | DLN_NULL;
	}
	else 
	{
		tmp = (*myList) -> lead;
		while (tmp != (*myList) -> last)
		{
			if (tmp == place)
			{
				flag = 1;
				break;
			}
			else
			{
				tmp = tmp -> right;
			}
		}
		if (flag == 1)
		{
			tmp  = place;
			tmp2 = place -> right;
			newNode -> right = tmp -> right;
			newNode -> left  = tmp;
			tmp -> right = newNode;
			tmp2 -> left = newNode;
			code = DLL_SUCCESS;
			(*myList) -> qty += 1;
		}
		else
		{
			code = DLL_INVALID | DLN_ERROR;
		}
	}
	
	
	return(code);
}
