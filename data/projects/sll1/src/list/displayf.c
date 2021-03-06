#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayf() - display the list in a specified orientation, also
//			  with or without positional values (as indicated
//			  by the mode parameter).
//
//	   modes: 0 display the list forward, no positional values
//			  1 display the list forward, with positional values
//	 
//		note: positional values are indexed starting from 0
//	 
//	behavior: on a NULL list, output "NULL"
//			  if list is UNDEFINED, output "UNDEFINED"
//			  on an EMPTY list, output "-> NULL"
//			  on error (invalid mode): MOD by 2 and do the result
//				 (or the logical equivalent)
//
//	  format: output is to be on a single line, with node values
//			  space-padded. and separated by "->" sequences, flush
//			  against the left margin, of the forms:
//
// for forward:   val0 -> val1 -> val2 -> ... -> valN-1 -> valN -> NULL
//
//			  or, if being displayed with node positions:
//
// for forward: [0] val0 -> [1] val1 -> ... -> [N-1] valN-1 -> [N] valN -> NULL
//
//		note: ALL output ends with a newline character
//
void displayf(List *myList, int mode)
{
	// error checking
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
		fprintf(stdout, "-> NULL\n");
	}
	else
	{
		// variables 
 		Node *tmp    = myList -> lead;
		int index    = 0;
		int pos_flag = 0;

		if (mode % 2 == 1)
			pos_flag = 1;

	
		for (index = 0; tmp != NULL; index++)
		{
			if (pos_flag == 1)
				fprintf(stdout, "[%d] ", index);

			fprintf(stdout, "%d -> ", tmp -> info);
			tmp = tmp -> right;
		}
		fprintf (stdout, "NULL\n");
	}
	return;
}
