#include <ListOfSinglyLinkedNodes.h>

Node * ListOfSinglyLinkedNodes :: getFirst()
{
	return (this -> first);
}

void   ListOfSinglyLinkedNodes :: setFirst(Node *newNode)
{
	newNode -> setAfter(this -> getFirst());
	this -> first = newNode;

}
