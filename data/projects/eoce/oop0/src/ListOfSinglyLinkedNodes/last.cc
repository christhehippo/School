#include <ListOfSinglyLinkedNodes.h>

Node * ListOfSinglyLinkedNodes :: getLast()
{
	return (this -> last);
}

void   ListOfSinglyLinkedNodes :: setLast(Node *newNode)
{
	this -> last -> setAfter(newNode);
	this -> last = newNode;
}
