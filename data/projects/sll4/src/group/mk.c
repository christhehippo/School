#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// mkgroup() - a group library function to allocate and initialize a 
//             new group.
//
//   behavior: on error, return NULL.
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
Group *mkgroup(void)
{
	// malloc a group
	Group *myGroup = malloc(sizeof(Group) * 1);
	
	if (myGroup == NULL)
	{
		// do nothing
	}
	else
	{
		myGroup -> initial = NULL;
		myGroup -> closing = NULL;
	}

	return(myGroup);
}
