#include "tree.h"
#include "stack.h"

#include <stdio.h>
//////////////////////////////////////////////////////////////////////
//
//traverse_s()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_s() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the stack-based implementation of traverse() will 
//              embody the utilization of a stack to the solution
//              of the tree traversal process. Once again, we are
//              sacrificing detail-oriented control in the moment
//              for conceptual elegance and simplification, which
//              will test your understanding of stack concepts.
//
//              traverse_s() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_ERROR:       an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t traverse_s(Tree *myTree, List **result, uc mode)
{
	code_t code   = 0;
	code_t scode  = 0;
	Node  *tmp    = NULL;
	Node  *tmp2   = NULL;
	Node  *tmp3   = NULL;
	Node  *tmp4   = NULL;
	Node  *tmp5   = NULL;
	Node  *tmp6   = NULL;
	Node  *write  = NULL;
	Node  *peeker = NULL;
	List  *slist  = NULL;
    Stack *stack  = NULL;

	if (myTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (result == NULL)
	{
		code = DLT_ERROR | DLL_INVALID;
	}
	else if (mode > 2)
	{
		code = DLT_ERROR;
		if (*result != NULL)
			code = code | DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_ERROR | DLT_EMPTY;
	}
	else if (*result != NULL)
	{
		code = DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_EMPTY | DLT_ERROR;
	}
	else if (myTree -> root == NULL)
	{
		code = mklist(result);
		code = code | DLT_SUCCESS | DLT_EMPTY;
	}
	else
	{
		mklist(result);
		mklist(&slist);  // make stack list
		mkstack(&stack, 200); // make stack
		stack -> data = slist; // assign stack list
		mknode(&tmp, 1); // alloc node, random value
		mknode(&tmp4, 1);
		mknode(&tmp5, 2);
		mknode(&peeker, 2);
		mknode(&write, 2);
		tmp4 -> DATA = myTree -> root; // get tree root 

		if (mode == 0)
		{
			push(&stack, tmp4); // push root to stack
			while (scode != (DLS_SUCCESS | DLS_EMPTY))
			{
				tmp6 = NULL;
				pop(&stack, &tmp6); // write next node in stack
				tmp = NULL;
				tmp = tmp6 -> DATA;
				
				write = NULL;
				mknode(&write, tmp -> VALUE);
				append(result, (*result) -> last, write);

				tmp2 = tmp3 = NULL;
				tmp2 = tmp -> right;
				tmp3 = tmp -> left;

				tmp4 = NULL;
				mknode(&tmp4, 1);
				
				if (tmp2 != NULL) // check if right exists, push
				{
					tmp4 -> DATA = tmp2;
					push(&stack, tmp4);
				}

				tmp5 = NULL;
				mknode(&tmp5, 10);
				
				if (tmp3 != NULL) // check if left exists, push
				{
					tmp5 -> DATA = tmp3;
					push(&stack, tmp5);
				}
				

				scode = isempty(stack);
				
			}
			code = DLT_SUCCESS;
		}
		else if (mode == 1) // preorder -> left most first, root, right
		{
			tmp = myTree -> root;
					
			while (scode != (DLS_SUCCESS | DLS_EMPTY) || tmp != NULL)
			{
				while (tmp != NULL)
				{
					tmp2 = NULL;
					mknode(&tmp2, 2);
					tmp2 -> DATA = tmp;
					push(&stack, tmp2);
					tmp = tmp -> left;
				}

				tmp6 = NULL;
				pop(&stack, &tmp6);
				tmp5 = NULL;
				tmp5 = tmp6 -> DATA;

				write = NULL;
				mknode(&write, tmp5 -> VALUE);
				append(result, (*result) -> last, write);
				tmp = tmp5 -> right;
				scode = isempty(stack);
			}
			code = DLT_SUCCESS;
		}
		else if (mode == 2)
		{
			tmp = myTree -> root;
					
			while (scode != (DLS_SUCCESS | DLS_EMPTY) || tmp != NULL)
			{
				while (tmp != NULL)
				{
					tmp2 = NULL;
					mknode(&tmp2, 2);
					tmp2 -> DATA = tmp;
					push(&stack, tmp2);
					tmp = tmp -> right;
				}

				tmp6 = NULL;
				pop(&stack, &tmp6);
				tmp5 = NULL;
				tmp5 = tmp6 -> DATA;

				write = NULL;
				mknode(&write, tmp5 -> VALUE);
				append(result, (*result) -> last, write);
				tmp = tmp5 -> left;
				scode = isempty(stack);
			}
			code = DLT_SUCCESS;
		}
	}


	return(code);
}
