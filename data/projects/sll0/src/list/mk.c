#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// mklist() - a list library function to allocate and initialize a 
//			new list.
//
//  behavior: on error, return NULL.
//
//	  note: you are to have only ONE return statement for this
//			entire function. Change the existing one as needed.
//
List *mklist(void)
{
	List *list = malloc(sizeof(List) * 1);
	if (list == NULL)
	{
		// do nothing
	}
	else
	{
		// if memory alloc is good, assign null to node pointers
		list -> lead  = NULL;
		list -> last  = NULL;
	}
	
	
	return(list);
}
