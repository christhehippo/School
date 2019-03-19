#include "ListOfSinglyLinkedNodes.h"

void ListOfSinglyLinkedNodes :: append(Node *place, Node *newNode)
{
	Node *tmp  = NULL;
	Node *tmp2 = NULL;
	if (place == NULL)
	{
		this -> setLast(newNode); // if we pass null to this, maybe put it at the end
		this -> setFirst(this -> last); // make it so first and last are the same node
	}
	else if (newNode == NULL)
	{
//		fprintf(stderr, "Invalid newNode\n");
	}
	else if ((this -> getFirst()) == NULL)
	{
		this -> setFirst(newNode);
		this -> setLast(newNode);
	}
	else if (place == this -> getLast())
	{
		this -> setLast(newNode);
	}
	else if (place == this -> getFirst())
	{
		this -> setFirst(newNode);
	}
	else
	{
		tmp = this -> getFirst();
		while (tmp != place && tmp != NULL)
		{
			tmp = tmp -> getAfter();
		}
		if (tmp == NULL)
		{
//			fprint(stderr, "place not found\n");
		}
		else
		{
			tmp2 = place -> getAfter();	
			place -> setAfter(newNode);
			newNode -> setAfter(tmp2);
		}
	}
}
