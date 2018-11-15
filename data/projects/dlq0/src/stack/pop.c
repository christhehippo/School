#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//      pop() - grab node off top of stack (stack is modified)
//              
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should track the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_INVALID:       newNode doesn't exist
//                  DLN_NULL:          *newNode is NULL (after pop)
//                  DLN_ALREADY_ALLOC: *newNode exists and not NULL
//                  DLS_SUCCESS:       normal operation
//                  DLS_UNDERFLOW:     pop() from an empty stack
//                  DLS_EMPTY:         stack is EMPTY
//                  DLS_NULL:          stack is NULL
//                  DLS_INVALID:       stack does not exist
//                  DLS_ERROR:         error occurred (stack is NULL,
//                                     non-existent, underflow, etc.)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t pop(Stack **myStack, Node **newNode)
{
    code_t code = 0;
	List  *list = NULL;
	Node  *tmp  = NULL;

	if (myStack == NULL)
	{
		code = DLS_INVALID | DLS_ERROR;
	}
	else if (*myStack == NULL)
	{
		code = DLS_ERROR | DLS_NULL;
	}
	else if (newNode == NULL)
	{
		code = DLS_ERROR | DLN_INVALID;
	}
	else if ((*myStack) -> data == NULL)
	{

	}
	else if ((*myStack) -> top == NULL)
	{
		code = DLS_ERROR |DLS_UNDERFLOW | DLS_EMPTY | DLN_NULL;
	}
	else
	{
		list = (*myStack) -> data;
		tmp = list -> last;
		obtain(&list, &tmp);
		*newNode = tmp;
		if (list -> last == NULL)
		{
			(*myStack) -> top = NULL;
			code = DLS_EMPTY | DLS_SUCCESS;
		}
		else
		{
			(*myStack) -> top = list -> last;
			code = DLS_SUCCESS;
		}
	}
	
	
	return (code);
}
