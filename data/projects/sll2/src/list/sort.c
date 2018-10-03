#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **preserved**, and the altered/
//              sorted list (a new list) is what is returned.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, return NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
List *sortlist(List *myList, int mode)
{
	int i		   = 0; // indexers
	int listSize   = 0;
	Node *tmp      = NULL;
	Node *tmp2     = NULL;
	Node *tmp3     = NULL;
	List *newList  = NULL;
	
	// fix mode if it needs to be fixed
	if (mode > 2)
		mode = mode % 3;
	
	if (myList    == NULL)
	{

	}
	else if (myList -> lead == myList -> last)
	{
		newList = cplist(myList);
	}
	else
	{
		newList  = cplist(myList);	
		listSize = getpos(myList, myList -> last);
		// sorry for lack of comments, its just i changed
		// this and swap so many times i lost track...
		if (mode == 0)
		{	
			for(i = 0; i < listSize; i++) 
			{
				tmp = newList -> lead;
				tmp2 = tmp -> right;
				if (tmp -> info > tmp2 -> info)
				{
					newList = swapnode(newList, tmp, tmp2);
					tmp3 = tmp2;
					tmp2 = tmp2 -> right;
					tmp = tmp3;
				}

				while (tmp2 -> right != NULL)
				{
					tmp  = tmp  -> right;
					tmp2 = tmp2 -> right;
					if (tmp -> info > tmp2 -> info)
					{
						newList = swapnode(newList, tmp, tmp2);
						tmp3 = tmp2;
						tmp2 = tmp2 -> right;
						tmp = tmp3;
					}
				}
			}
		}	
		else if (mode == 1)
		{
			for(i = 0; i < listSize; i++) 
			{
				tmp = newList -> lead;
				tmp2 = tmp -> right;
				if (tmp -> info < tmp2 -> info)
				{
					newList = swapnode(newList, tmp, tmp2);
					tmp3 = tmp2;
					tmp2 = tmp2 -> right;
					tmp = tmp3;
				}

				while (tmp2 -> right != NULL)
				{
					tmp  = tmp  -> right;
					tmp2 = tmp2 -> right;
					if (tmp -> info < tmp2 -> info)
					{
						newList = swapnode(newList, tmp, tmp2);
						tmp3 = tmp2;
						tmp2 = tmp2 -> right;
						tmp = tmp3;
					}
				}
			}

		}
		else if (mode == 2) // reverse list
		{
			for (i = 0; i < listSize / 2; i++)
			{
				tmp     = setpos(newList, i);
				tmp2    = setpos(newList, listSize - i);
				newList = swapnode(newList, tmp, tmp2);
			}
		}
	}

	return(newList);
}
