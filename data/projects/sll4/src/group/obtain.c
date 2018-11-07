#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  lobtain() - take and isolate indicated list out of group of lists,
//              through a careful adjustment of necessary pointers.
//              lobtain() needs to maintain group of lists integrity.
//              
//    behavior: on a NULL Group- do nothing; return NULL.
//              on UNDEFINED Group- return UNDEFINED.
//              on a NULL/UNDEFINED thatList- return as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatList, the one
//              being isolated from the group, is being passed in as a
//              double pointer (we're passing the List pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *lobtain(Group *myListGroup, List **thatList)
{
	List *tmp  = NULL;
	List *tmp2 = NULL;
	int   flag = 0;
	int   pos  = 0;

	if (myListGroup   == NULL || myListGroup == UNDEFINED)
	{
		// return as is
	}
	else if (thatList == NULL || thatList    == UNDEFINED)
	{
		// return as is
	}
	else if (myListGroup -> initial == myListGroup -> closing)
	{
		myListGroup -> initial = myListGroup -> closing = NULL;
	}
	else
	{
		if (*thatList == myListGroup -> initial)
		{
			if (myListGroup -> initial -> next == myListGroup -> closing)
			{
				myListGroup -> initial = myListGroup -> closing;
				myListGroup -> initial -> next = NULL;
			}
			else
			{
				tmp = myListGroup -> initial -> next;
				myListGroup -> initial = tmp;
			}
		}
		else if (*thatList == myListGroup -> closing)
		{
			if (myListGroup -> initial -> next == myListGroup -> closing)
			{
				myListGroup -> closing = myListGroup -> initial;
				myListGroup -> initial -> next = NULL;
			}
			else
			{
				pos  = lgetpos(myListGroup, *thatList);
				tmp  = lsetpos(myListGroup, pos-1);
				tmp -> next = NULL;
				myListGroup -> closing = tmp;
			}
		}	
		else
		{
			// check if thatNode is in the list
			tmp = myListGroup -> initial;
			while (tmp != myListGroup -> closing)
			{
				tmp = tmp -> next;
				if (tmp == *thatList)
					flag = 1;
			}
			// check if we flagged the node in the list
			if (flag == 1)
			{
				// dont do anything
			}
			else
			{
				pos  = lgetpos(myListGroup, *thatList);
				tmp  = lsetpos(myListGroup, pos-1);
				tmp2 = lsetpos(myListGroup, pos+1);
				tmp  -> next = tmp2;
			}
		}
	}



    return(myListGroup);
}
