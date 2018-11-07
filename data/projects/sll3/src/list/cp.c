#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// cplist() - a list library function to duplicate or copy an existing
//            list and all its component nodes.
//
//            the operative idea here is "separate copies"; you may
//            want to make use of cpnode() to assist.
//
//  behavior: on error, return NULL.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *cplist(List *oldList)
{
	List *newList = mklist(); 
	Node *tmp1    = NULL; // 1 + 2(rip tmp2) = oldList tmps
	Node *tmp3    = NULL; // 3 + 4 = newList tmps
	Node *tmp4    = NULL;

	if (newList == NULL)
	{
		// na
	}
	else if (oldList == NULL)
	{
		newList = NULL;
	}
	else if (oldList -> lead == NULL)
	{
		// na
	}
	else
	{
		tmp1 = oldList -> lead; // old
		tmp3 = cpnode(tmp1);	// new
		newList -> lead = tmp3; // assign new lead

		while (tmp1 != oldList -> last) // loop through the nodes
		{
			tmp1 = tmp1 -> right;
			tmp4 = cpnode(tmp1);
			tmp3 -> right = tmp4;
			tmp3 = tmp4;
		}
		newList -> last = tmp4; // assign new last
		newList -> qty  = oldList -> qty;
		newList -> next = oldList -> next;
	
	}

	return(newList);
}
