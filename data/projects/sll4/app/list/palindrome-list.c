#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*****************************************************************************
 ** sll2 extra credit program - the purpose of this program is to test your
 ** palindrome processing       skills at using linked lists to aid you in
 ** -------------------------   solving problems. You will be evaluated on:
 **
 ** 0. string to list: take input (from STDIN) and place one character in a
 **                    unique node constituting a linked list.
 **              NOTE: do not use arrays; build your linked list one char
 **                    at a time (until terminated by a newline).
 **
 ** 1. string to list: take input (from the command-line, if present) and
 **                    place one character in a unique node in a linked list.
 **              NOTE: command-line input would override prompting the user
 **                    for input via STDIN.
 **
 ** 2. process spaces: any spaces in the input are to be ignored (ie not 
 **                    manifested within nodes in the resulting linked list)
 **              NOTE: be sure your program accepts spaces, even if it will
 **                    only ignore them in the ultimate processing.
 **
 ** 3.     reverse it: reverse the list and store it as an additional list.
 **              NOTE: don't reinvent the wheel. Points will be awarded for
 **                    appropriately utilizing list operations in your 
 **                    solution to this problem.
 **
 ** 4.   compare them: do a node-by-node comparison of both lists in order
 **                    to determine whether the input (ignoring spaces) is
 **                    a palindrome or not.
 **              NOTE: comparison is done using lists
 **
 ** 5. display status: display a message indicating whether or not the 
 **                    input is a palindrome or not.
 **              NOTE: be sure to output the processed string (from the
 **                    list) along with its palindrome status.
 **
 ** 6.       comments: code must contain readable and informative comments
 **                    throughout explaining the process and rationale.
 **              NOTE: comments should be organized, just like code- be it
 **                    consistent indentation or custom comment blocks.
 **
 ** extra credit will be awarded based on your appropriate use of linked
 ** list function usage, correctness, and non-reinventing of wheels. It also
 ** wouldn't hurt to comment your code and ensure it is indented and readable.
 **/
int main(int argc, char **argv)
{
	int   i      = 0;
	int   i2     = 0;
	int   length = 0;
	char  c	     = 48;
	char *string = calloc(64, sizeof(char));
	uc    comp   = 0;
	ulli  pos    = 1;
	Node *tmp    = NULL;
	List *list   = mklist();
	List *listB  = mklist();
	if (argc > 1)
	{
		// get an initial list going
		c = argv[1][0];
		list -> lead = list -> last = mknode(c);
		i2 = 1;

		for (i = 1; i < argc; i++)
		{
			c = 48;
			while (c != 0)
			{
				c = argv[i][i2];

				if (c == 0)
				{
					i2 = 0;
				}
				else
				{
					i2++;
					tmp  = mknode(c);
					list = append(list, list -> last, tmp); 
				}
			}			
		}
	}
	else
	{
		fprintf(stdout, "Enter string pls: ");
		fgets(string, sizeof(string), stdin); // fscanf doesnt like spaces
		// fill list
		i = 0;
		list -> lead = list -> last = mknode(string[i]);
		i++;
		while (string[i] != 0)
		{
			if (string[i] == ' ')
			{

			}
			else if (string[i] == '\n')
			{
				string[i] = 0;
			}
			else
			{
				tmp  = mknode(string[i]);
				list = append(list, list -> last, tmp);
			}
			i++;
		}
	}
	
	listB = cplist(list);
	listB = sortlist(listB, 2);

	comp = compare(list, listB, &pos);
	
	if (comp != 0)
	{
		if (argc > 1)
		{
			for (i = 1; i < argc; i++)
			{
				fprintf(stdout, "%s", argv[i]);
			}
			fprintf(stdout, ": NOT A PALINDROME\n");
		}
		else
		{
			fprintf(stdout, "%s: NOT A PALINDROME\n", string);
		}
	}
	else
	{
		if (argc > 1)
		{
			for (i = 1; i < argc; i++)
			{
				fprintf(stdout, "%s", argv[i]);
			}
			fprintf(stdout, ": IS A PALINDROME\n");
		}
		else
		{
			fprintf(stdout, "%s: IS A PALINDROME\n", string);
		}

	}	
	return(0);
}
