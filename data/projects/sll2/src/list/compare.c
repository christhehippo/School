#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality (or the lack
//             thereof), as well as the position of difference.
//
//       note: if pos is initially NULL, care should be taken not to
//             assign any values to it.
//
//             a pos of 0 indicates a NULL or EMPTY list is our 
//             point of difference. Any actual list node positions
//             will start from 1 (be aware of this difference from
//             setpos()/getpos()).
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//             if a list is UNDEFINED, use that specific code
//
//   examples: a few examples for reference.
//
//             list1: NULL
//             list2: NULL
//             code:  CMP_L1_NULL  | CMP_L2_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: EMPTY
//             code:  CMP_L1_EMPTY | CMP_L2_EMPTY
//             pos:   0
//
//             list1: NULL
//             list2: EMPTY
//             code:  CMP_L1_NULL  | CMP_L2_EMPTY
//             pos:   0
//
//             list1: EMPTY
//             list2: NULL
//             code:  CMP_L1_EMPTY | CMP_L2_NULL
//             pos:   0
//
//             list1: NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_EMPTY
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: NULL
//             code:  CMP_L2_NULL
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: EMPTY
//             code:  CMP_L2_EMPTY
//             pos:   0
//
//             list1: 2 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_GREATER | CMP_L2_LESS
//             pos:   1
//
//             list1: 1 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 2 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_L1_LESS    | CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 3 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_EQUALITY
//             pos:   2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
uc compare(List *myList1, List *myList2, ulli *pos)
{

	uc    status  = 0;
	Node *tmp1    = NULL;
	Node *tmp2    = NULL;

	// both lists null
	if (myList1 == NULL && myList2 == NULL)
	{
		status = (CMP_L1_NULL | CMP_L2_NULL);
	}	
	// L1 null
	else if (myList1 == NULL)
	{
		status = CMP_L1_NULL;
		// check if L2 is empty when L1 is null
		if (myList2 -> lead == NULL)
			status = (status | CMP_L2_EMPTY);	
		// check if L2 is undefined when l1 is null
		else if (myList2 == UNDEFINED)
			status = (status | CMP_L2_UNDEFINED);
		
	}
	// L2 null
	else if (myList2 == NULL)
	{
		status = CMP_L2_NULL;
		// check if L1 is empty when L2 is null
		if (myList1 -> lead == NULL)
			status = (status | CMP_L1_EMPTY);	
		// check if l1 is undefined when l2 is null
		else if (myList1 == UNDEFINED)
			status = (status | CMP_L1_UNDEFINED);
	}
	// both empty
	else if (myList1 -> lead == NULL && myList2 -> lead == NULL)
	{
		status = (CMP_L1_EMPTY | CMP_L2_EMPTY);
	}
	// L1 empty
	else if (myList1 -> lead == NULL)
	{
		status = CMP_L1_EMPTY;
		// check if l2 undefined when l1 empty
		if (myList2 == UNDEFINED)
		{
			status = (status | CMP_L2_UNDEFINED);
		}
	}
	// L2 empty
	else if (myList2 -> lead == NULL)
	{
		status = CMP_L2_EMPTY;
		// check if l1 undefined when l2 empty
		if (myList1 == UNDEFINED)
		{
			status = (status | CMP_L1_UNDEFINED);
		}
	}
	// both undefined
	else if (myList1 == UNDEFINED && myList2 == UNDEFINED)
	{
		status = (CMP_L1_UNDEFINED | CMP_L2_UNDEFINED);
	}
	// else anything else
	else
	{
		if (pos != NULL)
		{
			(*pos) = 1;
		}
		tmp1 = myList1 -> lead;
		tmp2 = myList2 -> lead;
	
		// loop through list
		while ((tmp1 -> right != NULL) || (tmp2 -> right != NULL))
		{
			if ((tmp1 -> right == NULL) && (tmp2 -> right != NULL))
			{
				status = CMP_L2_GREATER;;
				// check if tracking pos
				if (pos != NULL)
				{
					(*pos)+=1;
				}
				break;
			}
			else if ((tmp2 -> right == NULL) && (tmp1 -> right != NULL))
			{
				status = CMP_L1_GREATER;
				// check if tracking pos
				if (pos != NULL)
				{
					(*pos)+=1;
				}
				break;
			}
			
			// advance list
			tmp1 = tmp1 -> right;
			tmp2 = tmp2 -> right;
			// if keeping track of pos
			if (pos != NULL)
			{
				(*pos)+=1;
			}

			if ((tmp1 -> info) > (tmp2 -> info))
			{
				status = (CMP_L1_GREATER | CMP_L2_LESS);
				break;
			}
			else if ((tmp1 -> info) < (tmp2 -> info))
			{
				status = (CMP_L1_LESS | CMP_L2_GREATER);
				break;
			}
		}
	}

	return (status);
}
