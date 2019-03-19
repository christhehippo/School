#include "ListOfDoublyLinkedNodes.h"

void ListOfDoublyLinkedNodes :: append(Node *place, Node *newNode)
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
	else if (place == this -> getLast())
	{
		tmp = this -> getLast();
		newNode -> setPrior(newNode);
		tmp -> setAfter(newNode);
		this -> setLast(newNode);
	}
	else
	{
		tmp  = place;
		tmp2 = place -> getAfter();
		tmp -> setAfter(newNode);
		newNode -> setPrior(tmp);
		newNode -> setAfter(tmp2);
		tmp2 -> setPrior(newNode);
	}

}
