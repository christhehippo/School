#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// clearlist() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               clearlist().
//
//     behavior: on error, return NULL.
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
List *clearlist(List *myList)
{
	Node *tmp   = NULL;
	if (myList == NULL)
	{

	}
	else if (myList == UNDEFINED)
	{

	}
	else
	{
		// all purpose clear alg
		tmp  = myList -> lead;
		while (myList -> lead != myList -> last)
		{
			myList -> lead = myList -> lead -> right;
			rmnode(tmp);
			tmp = myList -> lead;
		}
		rmnode(myList -> lead);
		myList -> lead = myList -> last = NULL;
	}
	
	
	return(myList);
}
