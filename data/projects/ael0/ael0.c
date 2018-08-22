//////////////////////////////////////////////////////////////
//  ael0 - Christian Cattell
//
//

#include <stdio.h>
#include <stdlib.h>

void menu(); // display the menu
void build(int *list); // build the list
void display_forward(int *list); // display the list forwards
void display_backward(int *list);// display the list backward
void insert(int *list, int pos, int val); // before
void append(int *list, int pos, int val); // after
int  obtain(int *list, int pos); // obtain a specific value
void empty (int *list); // clear the list

int main()
{
    int choice  =  0;
	int *list   = malloc(sizeof(int) * 20);
	list[0]     = -1;
	
	int pos     = 0;
	int val     = 0;
	
	while (1)
	{
		menu();
		fscanf(stdin, " %d", &choice);
		switch(choice)
		{						
			case 0: // build list
			{
				build(list);
				break;
			}

			case 1: // display list forward
			{
				display_forward(list);
				break;
			}

			case 2: // display list backward
			{
				display_backward(list);
				break;
			}

			case 3: // insert into list
			{
				fprintf(stderr, "Enter index to insert before: ");
				fscanf(stdin, " %d", &pos);
				fprintf(stderr, "Enter value to insert into list: ");
				fscanf(stdin, " %d", &val);
				insert(list, pos, val);
				break;
			}

			case 4: // append into list
			{
				fprintf(stderr, "Enter index to append after: ");
				fscanf(stdin, " %d", &pos);
				fprintf(stderr, "Enter value to append into list: ");
				fscanf(stdin, " %d", &val);
				append(list, pos, val);

				break;
			}

			case 5: //  obtain value from list, delete the value too
			{
				fprintf(stderr, "Enter index to obtain: ");
				fscanf(stdin, " %d", &pos);
				val = obtain(list, pos);
				fprintf(stdout, "The value you obtained is: %d\n", val);
				break;
			}

			case 6: // clear the list, same as the function used in the build function
			{
				empty(list);
				break;
			}

			case 7: // exit
			{
				return (0);
			}
			
			default:
			{
				break;
			}
		}
	}

	return(0);
}

void menu() // function to display the menu options
{
	fprintf(stderr, "\n====ael0====\n");
	fprintf(stderr, "0. build list\n");
	fprintf(stderr, "1. display list forward\n");
	fprintf(stderr, "2. display list backward\n");
	fprintf(stderr, "3. insert into list\n");
	fprintf(stderr, "4. append into list\n");
	fprintf(stderr, "5. obtain form list\n");
	fprintf(stderr, "6. clear list\n");
	fprintf(stderr, "7. quit\n");
	fprintf(stderr, ">>> ");
}

void build (int *list) // function to build the list
{
	empty(list);
	int input = 0;
	int index = 0;
	while (input != -1)
	{	
		if (index == 19)
		{
			list[index] = -1;
			return;
		}

		fprintf(stderr, "enter value (-1 to finish): ");
		fscanf(stdin, "%d", &input); // get user value
		list[index] = input; // put it in array
		index++;

		if (input == -1) // if user enters -1, then we are done
			return;
	}
}

void display_forward(int *list)  // display the list forwards
{
	int index = 0;
	
	for (index = 0; index < 20; index++)
	{
		fprintf(stdout, "[%d] %d", index, list[index]);

		if (list[index] == -1) // if we are at the end, print a newline and stop
		{
			fprintf(stdout, "\n");
			break;
		}
		else
		{
			fprintf(stdout, " -> ");
		}
	}
	return;
}

void display_backward(int *list)
{
	int index = 0;
	int start = 0;

	for (index = 19; index >= 0; index--) // figure out our starting position
	{
		if (list[index] == -1)
		{
			start = index;
			break;
		}
	}

	for (index = start; index >= 0; index--) // print the array backwards
	{
		fprintf(stdout, "[%d] %d", index, list[index]);
		
		if (index == 0)
			fprintf(stdout, "\n");
		else
			fprintf(stdout, " -> ");
	}

	return;
}

void insert(int *list, int pos, int val)
{
	int index = 0;
	for (index = 19; index >= pos; index--)
	{
		if (list[19] == -1) // discard the 18th value to preserve the -1
			index--;

		list[index] = list[index - 1];

		if (index == pos)
		{
			if (pos == 0)
			{
				list[pos] = val; // if list is empty
				return;
			}
			else
			{
				list[pos] = val; // else shift things 
				return;
			}
		}
	}
}

void append(int *list, int pos, int val) //append a value after index chosen
{
	if (pos == 0)
	{
		if (list[pos] == -1) // this was breaking test 12, made it so it checks if 0 list elements
		{
			list [1] = -1;
			list [0] = val;
			return;
		}
	}
	
	int index  = 0;
	
	for (index = 19; index >= pos; index--)
	{
		if (list[19] == -1)
			index--;
		
		if (index == pos + 1)
		{
			list[index] = val;
			return;
		}
		else
		{
			list[index] = list[index - 1];
		}

	}
}

int obtain(int *list, int pos) // remove a value from the list
{
	int removedVal = list[pos];

	while (1)
	{
		list[pos] = list[pos + 1];
		if (list[pos] == -1)  
		{
			break;
		}
		else
		{
			pos++;
		}
	}

	return(removedVal);
}

void empty(int *list) // removes contents from the list
{
	int index   = 0;
	list[0]     = -1;

	for (index  = 1; index < 20; index++)
		list[index] = 0;
}


