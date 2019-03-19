#include "ListOfSinglyLinkedNodes.h"

Node * ListOfSinglyLinkedNodes :: obtain (Node *place)
{
	Node *tmp  = NULL;
	Node *tmp2 = NULL;
	if (place == NULL)
	{
		// return NULL
	}
	else if (this -> getFirst() == this -> getLast())
	{
		this -> setFirst(NULL);
		this -> setLast(NULL);
	}
	else if (place == this -> getFirst())
	{
		tmp = this -> getFirst();
		tmp2 = tmp -> getAfter();
		tmp -> setAfter(NULL); // set the after pointer to NULL
		this -> setFirst(NULL); // set the first node to NULL
		this -> setFirst(tmp2);
	}
	else if (place == this -> getLast())
	{
		tmp = this -> getFirst();
		while (tmp != place)
		{
			tmp2 = tmp;
			tmp = tmp -> getAfter();
		}
		tmp  -> setAfter(NULL);
		tmp2 -> setAfter(NULL);
		this -> setLast(tmp2); // last switched with left node
	}
	else
	{
		tmp = this -> getFirst();
		while (tmp != place)
		{
			tmp2 = tmp;
			tmp = tmp -> getAfter();
		}
		tmp = tmp -> getAfter();
		tmp2 -> setAfter(tmp); // tmp2 next points to tmp now, not place
	}
	
	return(tmp);
}
