#include "ListOfSinglyLinkedNodes.h"

Node * ListOfSinglyLinkedNodes :: find(int value)
{
	Node *tmp = this -> getFirst();

	while (tmp != NULL)
	{
		if (tmp -> getValue() != value)
			tmp = tmp -> getAfter();
		else
			break;
	}
	
	return(tmp);
}
