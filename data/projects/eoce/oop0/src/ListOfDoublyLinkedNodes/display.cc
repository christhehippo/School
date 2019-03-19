#include "ListOfDoublyLinkedNodes.h"
#include <stdio.h>

void ListOfDoublyLinkedNodes :: display(int mode)
{
	int index = 0;
	Node *tmp = NULL;

	if (this -> getFirst() == NULL)
	{
		// na
	}
	else
	{
		if (mode < 2)
		{
			tmp = this -> getFirst();
			while (tmp != NULL)
			{
				if (mode % 2 == 1)
				{
					fprintf(stdout, "[%d] ", index);
					index++;
				}
				fprintf(stdout, "%d", tmp -> getValue());
				tmp = tmp -> getAfter();
				if (tmp != NULL)
					fprintf(stdout, " -> ");
				else
					fprintf(stdout, "\n");
			}
		}
		else if (mode < 4)
		{
			tmp = this -> getLast();
			index = this -> getQuantity();
			while (tmp != NULL)
			{
				if (mode % 2 == 1)
				{
					fprintf(stdout, "[%d] ", index);
					index--;
				}
				fprintf(stdout, "%d", tmp -> getValue());
				tmp = tmp -> getPrior();
				if (tmp != NULL)
					fprintf(stdout, " -> ");
				else
					fprintf(stdout, "\n");
			}
		}
	}
}
