#include <DoublyLinkedNode.h>

DoublyLinkedNode :: DoublyLinkedNode()
{
	this -> setAfter(NULL);
	this -> setPrior(NULL);
	this -> setValue(0);

}

DoublyLinkedNode :: DoublyLinkedNode(int value)
{
	this -> setAfter(NULL);
	this -> setPrior(NULL);
	this -> setValue(value);

}
