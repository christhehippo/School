#include "ListOfDoublyLinkedNodes.h"

Node * ListOfDoublyLinkedNodes :: obtain (Node *place)
{
	Node *tmp  = NULL;
	Node *tmp2 = NULL;
	if (place == NULL)
	{
		// nothing
	}	
	else if (this -> getFirst() == this -> getLast())
	{
		this -> setFirst(NULL);
		this -> setLast (NULL);
	}
	else if (this -> getFirst() == place)
	{
		tmp = place -> getAfter();
		place -> setAfter(NULL);
		this -> setFirst(tmp);
	}
	else if (this -> getLast() == place)
	{
		tmp = place -> getPrior();
		place -> setPrior(NULL);
		this -> setPrior(tmp);
	}
	else
	{
		tmp  = place -> getPrior();
		tmp2 = place -> getAfter();
		place -> setPrior(NULL);
		place -> setAfter(NULL);
		tmp  -> setAfter(tmp2);
		tmp2 -> setPrior(tmp);
	}


	return(tmp);
}
