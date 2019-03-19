#include <ListOfSinglyLinkedNodes.h>

List * ListOfSinglyLinkedNodes :: copy()
{
    Node *tmp     = NULL;

	List *newList = NULL;
	newList = new ListOfSinglyLinkedNodes();

	tmp = this -> getFirst();
	while (tmp != NULL)
	{
		newList -> append(newList -> getLast(), tmp);
		tmp = tmp -> getAfter();
	}


	return (newList);
}
