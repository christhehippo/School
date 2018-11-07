#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//    behavior: on a NULL list- do nothing; return NULL.
//              on an UNDEFINED list- do nothing, return list as is
//              on a NULL thatNode- do nothing; return list as is
//              on UNDEFINED thatNode- do nothing; return list as is
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatNode, the one
//              being isolated from the list, is being passed in as a
//              double pointer (we're passing the Node pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *obtain(List *myList, Node **thatNode)
{
	Node *tmp   = NULL;
	Node *tmp2  = NULL;

	// err handle
	if (myList == NULL)
	{

	}
	else if (myList == UNDEFINED)
	{

	}
	else if (myList -> lead == NULL)
	{
	
	}
	else if (myList -> lead == UNDEFINED)
	{

	}
	else if(thatNode == NULL)
	{

	}
	// 1-node
	else if (myList -> lead == myList -> last)
	{	
		myList -> lead = myList -> last = NULL;
		myList -> qty  = myList -> qty - 1;
	}
	// 2-node
	else if (myList -> last == myList -> lead -> right)
	{
		myList -> qty = myList -> qty - 1;
		if (*thatNode == myList -> last)
		{
			myList -> last = myList -> lead;
			myList -> last -> right = NULL;
		}
		else if (*thatNode == myList -> lead)
		{
			myList -> lead = myList -> last;
			myList -> last -> right = NULL;
		}
	}
	else
	{
		myList -> qty = myList -> qty - 1;
		// check if thatNode is the first node of a 2+ node list
		if (*thatNode == myList -> lead)
		{
			myList -> lead = myList -> lead -> right;
		}
		// else the normal procedure
		else
		{
			tmp  = myList -> lead;
			tmp2 = tmp -> right; 
			while (tmp2 != *thatNode)
			{
				tmp  = tmp  -> right;
				tmp2 = tmp2 -> right;
			}
			tmp -> right = tmp2 -> right;
			// make sure to save last if we kill it
			if (tmp -> right == NULL)
			{
				myList -> last = tmp;
			}
			
		}
	}

	return(myList);
}
