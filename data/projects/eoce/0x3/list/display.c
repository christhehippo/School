#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list according to mode(s).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_NOASCII:   display numeric values
//              DISPLAY_SEPS:      display separators between values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//              DISPLAY_ASCII:     display ASCII characters
//              DISPLAY_NOSEPS:    do not display separators
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output "(NULL)"
//              on an EMPTY list,  output "-> NULL" or "(EMPTY)" if
//                                 in ASCII mode
//              invalid mode:      MOD by 16 and do the result
//
//      format: output is to be against the left margin, on a single
//              line, ending with a newline character
//
//              DISPLAY_NOSEPS being set will remove all separators
//              and spaces from output, and positional values being
//              displayed change from "[#] " to "#:"
//
//              With DISPLAY_ASCII, separators are commas ', ', but
//              omitting the trailing comma at the end (there is no
//              terminating "NULL" displayed either)
//
//              Please see unit test output for examples. Note that
//              some mode combinations are nonsensical.
//
code_t display(List *myList, int mode)
{
	int    pos  = 0;
	code_t code = 0;
	Node  *tmp  = NULL;

	if (mode > 016 || mode < 0)
		mode = mode % 16;


	if (myList == NULL)
	{
		fprintf(stdout, "(NULL)\n");
		code = DLL_NULL;
	}
	else if (myList -> lead == NULL)
	{
		if (mode < 004)
		{
			fprintf(stdout, "-> NULL\n");
		}
		else if (mode < 010)
		{
			fprintf(stdout, "(EMPTY)\n");
		}
		else if (mode == 010)
		{
			fprintf(stdout, "NULL\n");
		}
		else
		{
			fprintf(stdout, "\n");
		}
		code = DLL_EMPTY;
	}
	else if (mode < 002)
	{
		tmp = myList -> lead;
		if (mode == 1)
		{
			fprintf(stdout, "[%d] ", pos);
			pos++;
		}
		fprintf(stdout, "%hhd -> ", tmp -> VALUE);
		tmp = tmp -> right;	
		while (tmp != NULL)
		{
					if (mode == 1)
			{
				fprintf(stdout, "[%d] ", pos);
				pos++;
			}
			fprintf(stdout, "%hhd -> ", tmp -> VALUE);
			tmp = tmp -> right;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}
	else if (mode < 4)
	{
		pos = myList -> qty - 1;
		tmp = myList -> last;
		if (mode == 3)
		{
			fprintf(stdout, "[%d] ", pos);
			pos--;
		}
		fprintf(stdout, "%hhd -> ", tmp -> VALUE);
		tmp = tmp -> left;	
		while (tmp != NULL)
		{
			if (mode == 3)
			{
				fprintf(stdout, "[%d] ", pos);
				pos--;
			}
			fprintf(stdout, "%hhd -> ", tmp -> VALUE);
			tmp = tmp -> left;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}
	else if (mode < 010)
	{
		if (mode < 006)
		{
			tmp = myList -> lead;
			if (mode == 005)
			{
				fprintf(stdout, "[%d] ", pos);
				pos++;
			}
			fprintf(stdout, "'%c', ", tmp -> VALUE);
			tmp = tmp -> right;	
			while (tmp != NULL)
			{
				if (mode == 005)
				{
					fprintf(stdout, "[%d] ", pos);
					pos++;
				}
				fprintf(stdout, "'%c'", tmp -> VALUE);
				if (tmp -> right != NULL)
					fprintf(stdout, ", ");
				tmp = tmp -> right;
			}
			fprintf(stdout, "\n");
			code = DLL_SUCCESS;
		}
		else
		{
			pos = myList -> qty - 1;
			tmp = myList -> last;
			if (mode == 007)
			{
				fprintf(stdout, "[%d] ", pos);
				pos--;
			}
			fprintf(stdout, "'%c', ", tmp -> VALUE);
			tmp = tmp -> left;	
			while (tmp != NULL)
			{
				if (mode == 007)
				{
					fprintf(stdout, "[%d] ", pos);
					pos--;
				}
				fprintf(stdout, "'%c'", tmp -> VALUE);
				if (tmp -> left != NULL)
					fprintf(stdout, ", ");
				tmp = tmp -> left;
			}
			fprintf(stdout, "\n");
			code = DLL_SUCCESS;
		}
	}
	else if (mode < 012)
	{
		tmp = myList -> lead;
		if (mode == 011)
		{
			fprintf(stdout, "%d:", pos);
			pos++;
		}
		fprintf(stdout, "%hhd", tmp -> VALUE);
		tmp = tmp -> right;	
		while (tmp != NULL)
		{
			if (mode == 011)
			{
				fprintf(stdout, "%d:", pos);
				pos++;
			}
			fprintf(stdout, "%hhd", tmp -> VALUE);
			tmp = tmp -> right;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}
	else if (mode < 014)
	{
		pos = myList -> qty - 1;
		tmp = myList -> last;
		if (mode == 013)
		{
			fprintf(stdout, "%d:", pos);
			pos--;
		}
		fprintf(stdout, "%hhd", tmp -> VALUE);
		tmp = tmp -> left;	
		while (tmp != NULL)
		{
			if (mode == 013)
			{
				fprintf(stdout, "%d:", pos);
				pos--;
			}
			fprintf(stdout, "%hhd", tmp -> VALUE);
			tmp = tmp -> left;
		}
		fprintf(stdout, "NULL\n");
		code = DLL_SUCCESS;
	}
	else if (mode < 016)
	{
		tmp = myList -> lead;
		if (mode == 015)
		{
			fprintf(stdout, "%d:", pos);
			pos++;
		}
		fprintf(stdout, "%c", tmp -> VALUE);
		tmp = tmp -> right;	
		while (tmp != NULL)
		{
			if (mode == 015)
			{
				fprintf(stdout, "%d:", pos);
				pos++;
			}
			fprintf(stdout, "%c", tmp -> VALUE);
			tmp = tmp -> right;
		}
		fprintf(stdout, "\n");
		code = DLL_SUCCESS;
	}
	else
	{
		pos = myList -> qty - 1;
		tmp = myList -> last;
		if (mode == 017)
		{
			fprintf(stdout, "%d:", pos);
			pos--;
		}
		fprintf(stdout, "%c", tmp -> VALUE);
		tmp = tmp -> left;	
		while (tmp != NULL)
		{
			if (mode == 017)
			{
				fprintf(stdout, "%d:", pos);
				pos--;
			}
			fprintf(stdout, "%c", tmp -> VALUE);
			tmp = tmp -> left;
		}
		fprintf(stdout, "\n");
		code = DLL_SUCCESS;

	}



	return(code);
}
