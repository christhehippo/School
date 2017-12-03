// 0x4 
#include <stdio.h>
#include <stdlib.h>

void menu();
void displayList(int *list);
void  insertList(int *list);
void  appendList(int *list);
void  obtainList(int *list);
void   clearList(int *list);

int main()
{
	// Create initial list
	int list[30] = {0};
	// Fill it 
	int listFill = 0;
	for (listFill = 0; listFill < 20; listFill++)
	{
		list[listFill] = listFill; 
	}
	// Place -1 at the 'end' of the list
	list[20] = -1;

	// Endlessly call menu until you quit
	int menuLoop = 0;
	char num = 0; // user value stored in this var

	for (menuLoop = 0; menuLoop != 9001; menuLoop++)
	{
		// Clear screen, print menu
		menu();
		
		// Obtain user choice
		
		fscanf(stdin, "%hhu", &num);
		fprintf(stdout, "\n");

		// Do things
		if (num == 1)
		{
			displayList(list);
		}
		else if (num == 2)
		{
			insertList(list);
		}
		else if (num == 3)
		{
			appendList(list);
		}
		else if (num == 4)
		{
			obtainList(list);
		}
		else if (num == 5)
		{
			clearList(list);
		}
		else if (num == 6)
		{
			fprintf(stdout, "Goodbye\n\n");
			return(0);
		}
		else
		{
			fprintf(stdout, "Error: please enter a number between 1 and 6\n");
		}
	}

	fprintf(stdout, "\nIf you are reading this, something went horribly wrong...\n\n");
	return(1);	
}

// Function to print array
void displayList(int *list)
{
	if (list[0] == -1)
	{
		fprintf(stdout, "List empty\n");
		
	}
	else
	{
		fprintf(stdout, "\n------------------ ----------------- -------------------\n");

		char index = 0;
		for (index = 0; list[index] != -1; index++)
		{
			fprintf(stdout, "| list[%2hhu]: %4d | ", index, list[index]);
			if ((index+1) % 3 == 0)
			{	
				fprintf(stdout, "\n------------------ ------------------ ------------------\n");
			}
		}
		if ((index) % 3 != 0)
		{
			fprintf(stdout, "\n------------------ ------------------ ------------------\n");
		}
	}
}

// Function to insert into list BEFORE the given index
void insertList(int *list)
{
	char listIndex = 0;
	int  newVal    = 0;
	// Get user values
	fprintf(stdout, "Insert before: ");
	fscanf(stdin, "%hhd", &listIndex);
	fprintf(stdout, "New value: ");
	fscanf(stdin, "%d", &newVal);
	// Shift the data, remove last array element
	char shift = 29;
	for (shift = 29; shift != listIndex-1; shift--)
	{
		list[shift] = list[shift-1];
	}
	// Place new value BEFORE specified array index
	list[listIndex-1] = newVal;
	fprintf(stdout, "\n%d placed at list[%hhd]\n", newVal, listIndex-1);
}

// Function to insert into list AFTER the given index
void appendList(int *list)
{
	char listIndex = 0;
	int  newVal    = 0;
	// Get user values
	fprintf(stdout, "Insert after: ");
	fscanf(stdin, "%hhd", &listIndex);
	fprintf(stdout, "New value: ");
	fscanf(stdin, "%d", &newVal);
	// Shift the data, remove last array element if it is full
	char shift = 29;
	for (shift = 29; shift != listIndex; shift--)
	{
		list[shift] = list[shift-1];
	}
	// Place new value AFTER specified array index
	list[listIndex+1] = newVal;
	fprintf(stdout, "\n%d placed at list[%hhd]\n", newVal, listIndex+1);
}

// Get a value from array, remove it, shift values 
void obtainList(int *list)
{
	char listIndex  = 0;
	int  deletedVal = 0;
	// Get user value
	fprintf(stdout, "Index: ");
	fscanf(stdin, "%hhd", &listIndex);
	// Store the value
	deletedVal = list[listIndex];
	// Scrub value
	list[listIndex] = 0;
	// Shift values
	char loop = listIndex;
	for (loop = listIndex; loop < 29; loop++)
	{
		list[loop] = list[loop+1];
	}
	// Print deleted value
	fprintf(stdout, "list[%hhd]: %d has been removed\n", listIndex, deletedVal);
	
}

// Empty array
void clearList(int *list)
{
	char index = 0;
	for (index = 0; index < 30; index++)
	{
		list[index] = 0;
	}
	list[0] = -1;
	fprintf(stdout, "The list is now empty\n");
}	

// Draw up the menu
void menu()
{
	fprintf(stdout, "\n");

	fprintf(stdout, "=========================\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  1. Display list      |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  2. Insert into list  |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  3. Append into list  |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  4. Obtain from list  |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  5. Clear list        |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "|  6. Quit              |\n");
	fprintf(stdout, "|                       |\n");
	fprintf(stdout, "=========================\n");
	
	fprintf(stdout, "\n");
}








