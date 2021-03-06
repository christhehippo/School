#include <stdio.h>
#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// ldisplay() - display the list group in an organized fashion (list
//              by list) or to display an isolated list from the group
//              of lists (as indicated by the pos parameter).
//
//    behavior: on a NULL group, output "<NULL>", return -1
//              on an EMPTY group, output "<EMPTY>", return 0
//              on an error state, output "<ERROR>", return -2
//
//              pos serves a dual purpose:
//                  -1: displays all lists in the list group
//                   0-n: displays that particular list in the group
//
//      output: (if pos is a -1):
//              <0>: 2 -> 4 -> 8 -> NULL
//              <1>: 3 -> 6 -> NULL
//              <2>: -> NULL
//              <3>: 12 -> 36 -> 96 -> 112 -> 119 -> NULL
//
//              (if pos is a 1):
//              <1>: 3 -> 6 -> NULL
//
//return value: the number of lists displayed
//
//        note: ALL output ends with a newline character
//
sli ldisplay(Group *myListGroup, sli pos)
{
	sli   num  = 0;
	List *tmp  = NULL;


	if (myListGroup == NULL)
	{
		num = -1;
		fprintf(stdout, "<NULL>\n");
	}
	else if (myListGroup -> initial == NULL)
	{
		num = 0;
		fprintf(stdout, "<EMPTY>\n");
	}
	else if (pos == -1)
	{
		tmp = myListGroup -> initial;
		while (tmp != NULL)
		{
			fprintf(stdout, "<%ld> ", num);
			displayf(tmp, 0);
			num++;
			tmp = tmp -> next;
		}
	}
	else
	{
		tmp = lsetpos(myListGroup, pos);
		if (tmp == NULL) 
		{
			fprintf(stdout, "<ERROR>\n");
			num = -2;
		}
		else
		{
			fprintf(stdout, "<%ld>: ", pos);
			num = 1;
			displayf(tmp, 0);	
		}
	}




	return (num);
}
