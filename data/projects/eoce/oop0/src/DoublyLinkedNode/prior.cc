#include <DoublyLinkedNode.h>

void DoublyLinkedNode :: setPrior(Node *priorNode)
{
	this -> prior = priorNode;
}

Node * DoublyLinkedNode :: getPrior()
{
	
	return(this -> prior);
}
