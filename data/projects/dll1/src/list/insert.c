#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//              at the indicated place. insert() needs to manage
//              the necessary connections/pointers) to maintain list
//              integrity, along with ensuring the start and end
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
code_t insert(List **myList, Node *place, Node *newNode)
{
	int    flag = 0;
	code_t code = 0;
	Node *tmp   = NULL;
	Node *tmp2  = NULL;

	if (myList == NULL)
	{
		code 	= DLL_INVALID | DLL_ERROR;
	}
	else if (*myList == NULL)
	{
		code	= DLL_ERROR | DLL_NULL;
	}
	else if ((*myList) -> lead == NULL)
	{
		if (newNode == NULL)
		{
			code = DLL_EMPTY | DLL_ERROR | DLN_NULL;
		}
		else
		{
			(*myList) -> lead = (*myList) -> last = newNode;
			code = DLL_SUCCESS;
		}
	}
	else if (newNode == NULL)
	{
		code	= DLL_ERROR | DLN_NULL;
	}
	else if (place == (*myList) -> lead)
	{
		if ((*myList) -> lead == (*myList) -> last)
		{
			tmp = (*myList) -> lead;
			newNode -> right = tmp;
			(*myList) -> lead = newNode;
			(*myList) -> last -> left = newNode;
			code = DLL_SUCCESS;
		}
		else
		{
			tmp = (*myList) -> lead;
			newNode -> right = tmp;
			tmp -> left = newNode;
			(*myList) -> lead = newNode;
			code = DLL_SUCCESS;
		}
	}
	else
	{
		tmp = (*myList) -> lead;
		while (tmp != NULL)
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
			tmp = (*myList) -> lead;
			while (tmp -> right != place)
			{
				tmp = tmp -> right;
			}
			// tmp -> newNode -> tmp2
			tmp2 = place;
			tmp -> right = newNode;
			newNode -> right = tmp2;
			newNode -> left  = tmp;
			tmp2 -> left = newNode;
			code = DLL_SUCCESS;
		}
		else
		{
			code = DLL_INVALID | DLL_ERROR | DLN_ERROR | DLN_NULL;	
		}
	}

    return(code);
}
