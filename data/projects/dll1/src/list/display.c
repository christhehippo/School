#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list in a specified orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output: "(NULL)"
//              on an EMPTY list,  output: "-> NULL"
//              invalid mode:      MOD by # of modes and do result
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "->" sequences, flush
//              against the left margin, of the forms:
//
// for forward: 0 -> 1 -> 2 -> ... -> N-1 -> N -> NULL
//
//   backwards: N -> N-1 -> ... -> 2 -> 1 -> 0 -> NULL
//
//              or, if being displayed with node positions:
//
// for forward: [0] 0 -> [1] 1 -> ... -> [N-1] N-1 -> [N] N -> NULL
//
//   backwards: [N] N -> [N-1] N-1 -> ... -> [1] 1 -> [0] 0 -> NULL
//
//        note: ALL output ends with a newline character
//
//        note: backwards output differs from that of singly-linked list
//              displayb(); with dll0, all display() output is universal
//              regardless of orientation.
//
//              if a mode of DISPLAY_POSVALS | DISPLAY_BACKWARD, you
//              WILL need to count up the number of nodes in the list;
//              this is expected, and shouldn't happen anywhere else.
//
code_t display(List *myList, int mode)
{
	int i       = 0;
    code_t code = 0;
	Node *tmp   = NULL;
	mode = mode % 4;

	if (myList == NULL)
	{
		code = DLL_NULL;
		fprintf(stdout, "NULL\n");
	}
	else if (myList -> lead == NULL)
	{
		code = DLL_EMPTY;
		fprintf(stdout, "-> NULL\n");
	}
	else if (mode < 2)
	{
		tmp	= myList -> lead;
		while (tmp != NULL)
		{
			if (mode == 1)
			{
				fprintf(stdout, "[%d] ", i);
			}
			fprintf(stdout, "%hhd -> ", tmp -> VALUE);
			i++;
			tmp = tmp -> right;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}
	else
	{
		if (mode == 3)
		{
			tmp = myList -> lead;
			while (tmp != NULL)
			{
				i++;
				tmp = tmp -> right;
			}
			i--;
		}
		tmp = myList -> last;
		while (tmp != NULL)
		{
			if (mode == 3)
			{
				fprintf(stdout, "[%d] ", i);
				i--;
			}
			fprintf(stdout, "%hhd -> ", tmp -> VALUE);
			tmp = tmp -> left;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}

	return(code);
}
