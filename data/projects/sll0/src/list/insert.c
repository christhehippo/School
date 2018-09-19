#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//			  at the indicated place. insert() needs to manage
//			  the necessary connections pointers) to maintain list
//			  integrity, along with ensuring the start and end
//			  indicators of the list remain relevant and up-to-date.
//
//	behavior: on an UNDEFINED list- do nothing; return list as is
//			  on a NULL list- allocate a list and proceed
//			  on a NULL or UNDEFINED newNode- return list as is
//
//		note: you are expected to make use of the getpos() and
//			  setpos() functions to aid you in accomplishing this
//			  task. Don't needlessly reinvent the wheel.
//
//			  as with the other functions, you may use no more
//			  than one return() statement per function.
//
List *insert(List *myList, Node *place, Node *newNode)
{
	// check some pre - errors 
	if (myList == UNDEFINED)
	{
		
	}
	else if (myList == NULL)
	{	
		myList = mklist();
	}

	Node *tmp  = NULL;
	Node *tmp2 = NULL;
	int   pos  = 0;
	int index  = 0;

	// if list is empty
	if (myList -> lead == NULL)
	{
		myList -> lead = newNode;
		myList -> last = newNode;
	}
	// else if putting something at the start of the list
	else if (getpos(myList, place) == 0)
	{
		newNode -> right = place;
		myList -> lead = newNode; 
	}
	else
	{
		pos = getpos(myList, place);
		tmp = setpos(myList, pos);
		tmp2 = setpos(myList, pos - 1);
		newNode -> right = tmp;
		tmp2 -> right    = newNode;
		if (tmp -> right == NULL)
			tmp = myList -> last;
		

	}
	
	


	return(myList);
}
