#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  linsert() - add a new list to the given list group before the list
//              at the indicated place. linsert() needs to manage
//              the necessary connections (pointers) to maintain list
//              group integrity, along with ensuring the first and
//              last indicators of the list group remain relevant
//              and up-to-date.
//
//    behavior: on a NULL/UNDEFINED group- return NULL
//              on a NULL/UNDEFINED list-  do nothing; return as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *linsert(Group *myListGroup, List *place, List *newList)
{
	List *tmp  = NULL;
	List *tmp2 = NULL;
    
	if (myListGroup == NULL || myListGroup == UNDEFINED)
	{
		// nothing
	}
	else if (newList == NULL || newList == UNDEFINED)
	{
		// nothing
	}
	else if (myListGroup -> initial == NULL)
	{
		myListGroup -> initial = myListGroup -> closing = newList;
	}
	else 
	{
		// check if the position is the inital pos
		if (myListGroup -> initial == place)
		{
			tmp     = myListGroup  -> initial;
			newList     -> next    = tmp;
			myListGroup -> initial = newList;
		}
		else if (place == myListGroup -> closing)
		{
			// for whatever reason, tmp2 is left, tmp is right here
			printf("linsert test\n");
			tmp  = myListGroup -> closing;
			tmp2 = myListGroup -> initial;
			while (tmp2 -> next != tmp)
			{
				tmp2 = tmp2 -> next;
			}
			tmp2    -> next  = newList;
			newList -> next  = tmp;
		}
		else
		{
			// tmp is right of newnode, tmp2 is left
			tmp = myListGroup -> initial;
			while (tmp != place)
			{
				tmp = tmp   -> next;
			}
			tmp2    =  tmp  -> next;
			tmp     -> next = newList;
			newList -> next = tmp2;

		}
	}


	return (myListGroup);	
}
