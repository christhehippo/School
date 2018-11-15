#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//     push() - place newNode onto top of given stack
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should track the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:     newNode is NULL (an error)
//                  DLS_SUCCESS:  normal operation (push successful)
//                  DLS_NULL:     stack is NULL
//                  DLS_OVERFLOW: tried to push onto a full bounded
//                                stack (considered an error)
//                  DLS_ERROR:    error encountered
//                  DLS_INVALID:  stack does not exist
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t push(Stack **myStack, Node *newNode)
{
    code_t code = 0;
	List  *list = NULL;
	
	if (myStack 	  == NULL)
	{
		code 	 	   = DLS_INVALID | DLS_ERROR;
	}
	else if (*myStack == NULL)
	{
		code 	 	   = DLS_NULL | DLS_ERROR;
	}
	else if (newNode  == NULL)
	{
		code 	 	   = DLN_NULL | DLS_ERROR;
	}
	else if ((*myStack) -> size == (*myStack) -> data -> qty)
	{
		code = DLS_ERROR | DLS_OVERFLOW;
	}
	else if ((*myStack) -> top == NULL)
	{
		list = (*myStack) -> data;
		append(&list, NULL, newNode);
		(*myStack) -> top = (*myStack) -> data -> last;
		code = DLS_SUCCESS;
	}
	else
	{
		list = (*myStack) -> data;
		append(&list, (*myStack) -> top, newNode);
		(*myStack) -> top = (*myStack) -> data -> last;
		code = DLS_SUCCESS;
	}

	return (code);
}
