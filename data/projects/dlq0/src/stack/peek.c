#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//     peek() - read node off top of stack (do not modify stack)
//              passing back a COPY of the node that is read
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              peekNode, if it exists, will be discarded in favor
//              of information obtained from the stack (so no need
//              to pre-NULL the value)
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_INVALID: peeknode doesn't exist
//                  DLS_SUCCESS: normal operation
//                  DLS_NULL:    stack is NULL
//                  DLS_EMPTY:   stack is EMPTY (not an error)
//                  DLS_ERROR:   stack is NULL or other error state
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t peek(Stack *myStack, Node **peekNode)
{
	code_t code = 0;
	Node  *tmp  = NULL;
	Node  *tmp2 = NULL;

	if (myStack == NULL)
	{
		code = DLS_NULL | DLS_ERROR;
	}
	else if (peekNode == NULL)
	{
		code = DLN_INVALID | DLS_ERROR;
	}
	else if (myStack -> top == NULL)
	{
		code = DLS_EMPTY | DLS_SUCCESS;
	}
	else
	{
		tmp2 = myStack -> top;
		cpnode(tmp2, &tmp);
		*peekNode = tmp;
		code = DLS_SUCCESS;
	}
	

    return (code);
}
