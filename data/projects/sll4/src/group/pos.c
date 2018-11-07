#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// lgetpos() - a group library utility function to identify the actual
//             position of a given list in an indicated list group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group/list), return negative
//             value (-1), on out-of-bounds condition, return -2
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
sli lgetpos(Group *myListGroup, List *given)
{
    sli   pos = 0;
	List *tmp = NULL;
	if (myListGroup == NULL || given == NULL)
	{
		pos = -1;
	}
	else if (myListGroup -> initial == NULL)
	{
		pos = -2;
	}
	else if (myListGroup == UNDEFINED || given == UNDEFINED)
	{
		pos = -1;
	}
	else
	{
		tmp = myListGroup -> initial;
		while (tmp != given)
		{
			tmp = tmp -> next;
			pos+=1;
			if (tmp == NULL)
			{
				pos = -2;
				break;
			}
		}
	}

	return(pos);
}

//////////////////////////////////////////////////////////////////////
//
// lsetpos() - a group library utility function to set a list pointer
//             to the list at the indicated position of a group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group or
//             negative/out-of-bounds pos), return NULL.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
List *lsetpos(Group *myListGroup, sli pos)
{
	int   i 		 = 0;
	List *tmp        = NULL;
	if (myListGroup == NULL || myListGroup == UNDEFINED) 
	{
		// na
	}
	else if (pos < 0)
	{
	
	}
	else
	{
		tmp = myListGroup -> initial;
		while (i != pos)
		{
			if (tmp -> next == NULL)
			{
				tmp = NULL;
				break;
			}
			else
			{
				tmp = tmp -> next;
				i++;
			}
		}
	}


	return(tmp);
}
