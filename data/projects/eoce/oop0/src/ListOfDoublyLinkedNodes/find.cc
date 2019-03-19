#include "ListOfDoublyLinkedNodes.h"

Node * ListOfDoublyLinkedNodes :: find(int value)
{
	Node *tmp = NULL;
	tmp = this -> getFirst();

	while (tmp != NULL)
	{
		if (tmp -> getValue() != value)
			tmp = tmp -> getAfter();
		else
			break;
	}
	return(tmp);
}
