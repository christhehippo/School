#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own initial and closing pointers, along with
//              connectivity between the nodes from the start to end
//              of the list).
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
//    behavior: on a NULL list- do nothing: return NULL
//              on UNDEFINED list- return list as is
//              on an EMPTY list- do nothing: return list unchanged
//              on a NULL/invalid nodes to swap- do nothing: return
//                  the list unchanged
//
//        note: where applicable, make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *swapnode(List *myList, Node *item1, Node *item2)
{
	Node *tmp   = NULL;
	Node *tmp2  = NULL;
	Node *tmp3  = NULL;
	Node *tmp4  = NULL;
	
	if (myList == NULL)
	{

	}
	else if (myList == UNDEFINED)
	{

	}
	else if (myList -> lead == NULL)
	{

	}
	else if (item1 == NULL || item2 == NULL)
	{

	}
	// if two node list
	else if (myList -> lead -> right == myList -> last)
	{
		tmp  = myList -> lead;
		tmp2 = myList -> last;
		myList -> lead = tmp2;
		myList -> last = tmp;
		myList -> lead -> right = myList -> last;
	}
	// if one of the nodes is lead
	else if (myList -> lead == item1 || myList -> lead == item2)
	{
		if (myList -> lead == item1) // a case where item 1 is lead
		{
			if (myList -> last == item2) // a case where item 1 is lead, 2 is last
			{
				tmp = myList -> lead;
				while (tmp -> right != item2)
				{
					tmp = tmp -> right;
				}
				item2 -> right = item1 -> right;
				tmp -> right = item1;
				item1 -> right = NULL;
				myList -> lead = item2;
			}
			else  // a case where item 1 is lead and item is not last
			{
				if (item1 -> right == item2) // item2 is to right of item1
				{
					item1  -> right = item2 -> right;
					item2  -> right = item1;
					myList -> lead  = item2;
				}
				else // other case *breaks*
				{
					tmp  = item1 -> right;
					tmp2 = myList -> lead;
					while (tmp2 -> right != item2)
					{
						tmp2 = tmp2 -> right;
					}
					tmp3  = item2 -> right;
					
					item2 -> right = tmp;
					item1 -> right = tmp3;
					tmp2  -> right = item1;
					myList -> lead = item2;
				}
			}
		}
		else if (myList -> lead == item2)
		{
			if (myList -> last == item1) // a case where item 1 is lead, 2 is last
			{
				tmp = myList -> lead;
				while (tmp -> right != item1)
				{
					tmp = tmp -> right;
				}
				item1 -> right = item2 -> right;
				tmp -> right = item2;
				item2 -> right = NULL;
				myList -> lead = item1;
			}
			else
			{
				if (item2 -> right == item1) // item1 is to right of item2
				{
					item2  -> right = item1 -> right;
					item1  -> right = item2;
					myList -> lead  = item1;
				}
				else
				{
  					tmp  = item2 -> right;
					tmp2 = myList -> lead;
					while (tmp2 -> right != item1)
					{
						tmp2 = tmp2 -> right;
					}
					tmp3  = item1 -> right;
					
					item1 -> right = tmp;
					item2 -> right = tmp3;
					tmp2  -> right = item2;
					myList -> lead = item1;
				}
			}
		}
	}
	// if one of the nodes is last and NONE are lead
	else if (myList -> last == item1 || myList -> last == item2)
	{
		if (myList -> last == item1)
		{
			if (item2 -> right == item1)
			{
				tmp = myList -> lead;
				while (tmp -> right != item2)
				{
					tmp = tmp -> right;
				}
				tmp -> right = item1;
				item2 -> right = NULL;
				item1 -> right = item2;
				myList -> last = item2;
			}
			else 
			{
				tmp = myList -> lead;
				while (tmp -> right != item2)
				{
					tmp = tmp -> right;
				}
				tmp2 = item2 -> right;
				tmp3 = myList -> lead;
				while (tmp3 -> right != myList -> last)
				{
					tmp3 = tmp3 -> right;
				}
				tmp    -> right = item1;
				item1  -> right = tmp2;
				tmp3   -> right = item2;
				item2  -> right = NULL;
				myList -> last  = item2;
			}
			
		}
		else if (myList -> last == item2)
		{
			if (item1 -> right == item2)
			{
				tmp = myList -> lead;
				while (tmp -> right != item1)
				{
					tmp = tmp -> right;
				}
				tmp -> right = item2;
				item1 -> right = NULL;
				item2 -> right = item1;
				myList -> last = item1;
			}
			else
			{
				tmp = myList -> lead;
				while (tmp -> right != item1)
				{
					tmp = tmp -> right;
				}
				tmp2 = item1 -> right;
				tmp3 = myList -> lead;
				while (tmp3 -> right != myList -> last)
				{
					tmp3 = tmp3 -> right;
				}
				tmp    -> right = item2;
				item2  -> right = tmp2;
				tmp3   -> right = item1;
				item1  -> right = NULL;
				myList -> last  = item1;
			}
		}
	}
	else 
	{
		if (item1 -> right == item2)
		{
			// 1 -> item1 -> item2 -> x -> x -> NULL
			tmp = myList -> lead;
			while (tmp -> right != item1)
			{
				tmp = tmp -> right;
			}
			tmp2 = item2 -> right;
			tmp -> right = item2;
			item2 -> right = item1;
			item1 -> right = tmp2;
		}
		else if (item2 -> right == item1)
		{
			tmp = myList -> lead;
			while (tmp -> right != item2)
			{
				tmp = tmp -> right;
			}
			tmp2 = item1 -> right;
			tmp -> right = item1;
			item1 -> right = item2;
			item2 -> right = tmp2;
		}
		else
		{
			// item1 nodes
			tmp = myList -> lead;
			while (tmp -> right != item1)
			{
				tmp = tmp -> right;
			}
			tmp2 = item1 -> right;
			// item 2 nodes
			tmp3 = myList -> lead;
			while (tmp3 -> right != item2)
			{
					tmp3 = tmp3 -> right;
			}
			tmp4 = item2 -> right;
	

			item1 -> right = tmp4;
			tmp3  -> right = item1;
			item2 -> right = tmp2;
			tmp   -> right = item2; 
		}
	}


	return(myList);
}
