#include "ListOfSinglyLinkedNodes.h"

// insert() - insert newNode before place in this
//
void ListOfSinglyLinkedNodes :: insert(Node *place, Node *newNode)
{
	Node *tmp    = NULL;
	Node *tmp2   = NULL;
	if (newNode == NULL)
	{
//		fprintf(stderr, "Invalid newNode\n");
	}
	else if (this -> getFirst() == NULL)
	{
		this -> setFirst(newNode);
		this -> setLast(newNode);
	}
	else if (place == this -> getFirst())
	{
		this -> setFirst(newNode);
	}
	else
	{
		tmp = this -> getFirst();
		while (tmp != place)
		{
			tmp2 = tmp;
			tmp  = tmp -> getAfter();
		}
		tmp2 -> setAfter(newNode);
		newNode -> setAfter(tmp);
	}
}
