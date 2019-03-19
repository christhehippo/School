#include <ListOfDoublyLinkedNodes.h>

List * ListOfDoublyLinkedNodes :: copy()
{
	Node *tmp 		= NULL;
	List *newList	= NULL;
	newList = new ListOfDoublyLinkedNodes();

	tmp = this -> getFirst();
	while (tmp != NULL)
	{
		newList -> append(newList -> getLast(), tmp);
		tmp = tmp -> getAfter();
	}

    return (newList);
}
