#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayb() - display the list in a reversed orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: 0 display the list backward, no positional values
//              1 display the list backward, with positional values
//     
//        note: positional values are indexed starting from 0
//     
//    behavior: on a NULL list, output "NULL"
//              if list is UNDEFINED, output "UNDEFINED"
//              on an EMPTY list, output "NULL <-"
//              on error (invalid mode): MOD by 2 and do the result
//                 (or the logical equivalent)
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "<-" sequences, flush
//              against the left margin, of the forms:
//
//   backwards:   NULL <- 9 <- 7 <- 6 <- 4
//
//              or, if being displayed with node positions:
//
//   backwards:   NULL <- [3] 9 <- [2] 7 <- [1] 6 <- [0] 4
//
//        note: ALL output ends with a newline character
//
void displayb(List *myList, int mode)
{
	Node *tmp      = NULL;
	int   pos      = -1;
	int   pos_flag = 0;
	
	// check what mode to use
	if (mode % 2 == 1)
		pos_flag = 1;

	if (myList == NULL)
	{
		fprintf(stdout, "NULL\n");
	}
	else if (myList == UNDEFINED)
	{
		fprintf(stdout, "UNDEFINED\n");
	}
	else if (myList -> lead == NULL)
	{
		fprintf(stdout, "NULL <-\n");
	}
	else
	{
		tmp = myList -> last; // grab last node

		fprintf(stdout, "NULL <- "); // print end of list
		while (pos != 0)
		{
			pos = getpos(myList, tmp);
			if (pos_flag == 1)
			{   //  conditional check
				fprintf(stdout, "[%d] ", pos);
			}
			fprintf(stdout, "%d ", tmp -> info);
			tmp = setpos(myList, pos-1); // advance position in list
			if (pos == 0)
			{   // check if we are at the end *start*
				fprintf(stdout, "\n");
			}
			else
			{
				fprintf(stdout, "<- ");
			}
		}
		

	}
	










}
