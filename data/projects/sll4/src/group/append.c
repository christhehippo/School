#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  lappend() - add a new list to the given list group after the list
//              at the indicated place. lappend() needs to manage
//              the necessary connections (pointers) to maintain list
//              group integrity, along with ensuring initial and
//              closing indicators of the list group remain relevant
//              and up-to-date.
//
//    behavior: on a NULL/UNDEFINED group- return NULL
//              on a NULL/UNDEFINED newList- return group as is
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *lappend(Group *myListGroup, List *place, List *newList)
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
		// case if appending after closing
		if (place == myListGroup -> closing)
		{
			tmp = myListGroup -> closing;
			tmp -> next = newList;
			newList -> next = NULL;
			myListGroup -> closing = newList;
		}
		else 
		{
			tmp = myListGroup -> initial;
			while (tmp != place)
			{
				tmp = tmp -> next;
			}
			tmp2    = tmp -> next;

			tmp     -> next = newList;
			newList -> next = tmp2;
		}
	}




	return (myListGroup);
}
