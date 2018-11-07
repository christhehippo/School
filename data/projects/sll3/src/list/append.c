#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the initial and closing
//              pointers of the list remain relevant and up-to-date.
//
//    behavior: on an UNDEFINED list- do nothing; return list as is
//              on a NULL list- allocate a list and proceed
//              on a NULL or UNDEFINED newNode- return list as is
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *append(List *myList, Node *place, Node *newNode)
{
	Node *tmp  = NULL;
	Node *tmp2 = NULL;
	int   pos  = 0;
	
	if (myList == UNDEFINED)
	{

	}
	else if (myList == NULL)
	{
		myList = mklist();
	}
	else if (newNode == NULL)
	{

	}
	else if (newNode == UNDEFINED)
	{

	}
	else if (myList -> lead == NULL)
	{
		myList -> lead = newNode;
		myList -> last = newNode;
		myList -> qty = myList -> qty + 1;
	}
	else if (place == myList -> last)
	{
		tmp = place;
		myList -> last = newNode;
		tmp -> right = newNode;
		myList -> qty = myList -> qty + 1;
	}
	else
	{
		pos  = getpos(myList, place);
		// tmp node to insert after
		tmp  = setpos(myList, pos);
		// tmp2 node to the right of tmp
		tmp2 = setpos(myList, pos+1);
		newNode -> right = tmp2;
		tmp -> right = newNode;
		myList -> qty = myList -> qty + 1;
	}
	return(myList);
}
