#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality, or the lack
//             thereof.
//
//       note: if difference is initially NULL, care should be taken
//             not to assign any values to it.
//
//             a difference of 0 indicates a NULL or EMPTY list is
//             our point of difference. Any actual list node
//             positions will start from 1 (be aware of this)
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//   examples: a few examples for reference.
//
//             list1:        NULL
//             list2:        NULL
//             code:         CMP_L1_NULL  | CMP_L2_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        EMPTY
//             code:         CMP_L1_EMPTY | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        NULL
//             list2:        EMPTY
//             code:         CMP_L1_NULL  | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        EMPTY
//             list2:        NULL
//             code:         CMP_L1_EMPTY | CMP_L2_NULL
//             difference:   0
//
//             list1:        NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_EMPTY
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        NULL
//             code:         CMP_L2_NULL
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        EMPTY
//             code:         CMP_L2_EMPTY
//             difference:   0
//
//             list1:        2 -> NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_GREATER | CMP_L2_LESS
//             difference:   1
//
//             list1:        1 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 2 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L1_LESS    | CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 3 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_EQUALITY
//             difference:   2
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
//             do not count; navigate by comparison
//
code_t  compare(List *myList1, List *myList2, ulli *difference)
{
    code_t code  = 0;
	Node  *tmpl1 = 0;
	Node  *tmpl2 = 0;

	if (myList1 == NULL)
	{
		code = CMP_L1_NULL;
		if (myList2 == NULL)
			code = code | CMP_L2_NULL;
		else if (myList2 -> lead == NULL)
			code = code | CMP_L2_EMPTY;
	}
	else if (myList2 == NULL)
	{
		code = CMP_L2_NULL;
		if (myList1 == NULL)
			code = code | CMP_L1_NULL;
		else if (myList1 -> lead == NULL)
			code = code | CMP_L1_EMPTY;
	}
	else if (myList1 -> lead == NULL)
	{
		code = CMP_L1_EMPTY;
		if (myList2 -> lead == NULL)
			code = code | CMP_L2_EMPTY;
	}
	else if (myList2 -> lead == NULL)
	{
		code = CMP_L2_EMPTY;
		if (myList1 -> lead == NULL)
			code = code | CMP_L1_EMPTY;
	}
	else
	{
		tmpl1 = myList1 -> lead;
		tmpl2 = myList2 -> lead;

		if (difference == NULL)
		{
			// leave it at the start
		}
		else
		{
			*difference = 1;
		}
		
		while (tmpl1 != NULL && tmpl2 != NULL)
		{
			if (tmpl1 -> VALUE != tmpl2 -> VALUE)
			{
				if (tmpl1 -> VALUE > tmpl2 -> VALUE)
				{			
					code = CMP_L1_GREATER | CMP_L2_LESS;
					break;
				}
				else if (tmpl1 -> VALUE < tmpl2 -> VALUE)
				{
					code = CMP_L1_LESS | CMP_L2_GREATER;
					break;
				}
			}

			tmpl1 = tmpl1 -> right;
			tmpl2 = tmpl2 -> right;
			if (difference != NULL)
				*difference = *difference + 1;

			if (tmpl1 == NULL || tmpl2 == NULL)
			{
				if (tmpl1 == NULL && tmpl2 == NULL)
				{
					code = 0;
					if (difference != NULL)
						*difference = *difference - 1;
				}
				else if (tmpl1 == NULL)
					code = CMP_L2_GREATER;
				else
					code = CMP_L1_GREATER;
			}
		}
	}

	return(code);
}
