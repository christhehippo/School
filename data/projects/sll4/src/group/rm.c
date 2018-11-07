#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// rmgroup() - a group library function to deallocate an existing
//             list group; care must be taken to ensure any component
//             lists have been properly disposed of so as to prevent
//             a memory leak. The resulting group will be in a NULL
//             state following successful processing.
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
Group *rmgroup(Group *oldGroup)
{
	List *tmp  = NULL;
	List *tmp2 = NULL;
	
	if (oldGroup == NULL)
	{

	}
	else if (oldGroup -> initial == NULL)
	{
		free(oldGroup);
		oldGroup = NULL;
	}
	else
	{
		// set tmp to first list in group
		tmp  = oldGroup -> initial;
		
		// check if it is the only list in the group
		if (oldGroup -> initial -> next == NULL)
		{
			rmlist(tmp);
			free(oldGroup);
			oldGroup = NULL;
		}
		//  else tmp2 is the next list
		else
		{
			tmp2 = tmp -> next;
			rmlist(tmp);
			while (tmp2 != NULL)
			{
				tmp = tmp2;
				tmp2 = tmp2 -> next;
				rmlist(tmp);
			}
			free(oldGroup);
			oldGroup = NULL;
		}
	}

	return(oldGroup);
}
