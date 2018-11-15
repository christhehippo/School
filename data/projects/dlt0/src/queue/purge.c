#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//     purge() - a queue library function to empty an existing queue
//               of any and all of its component nodes (deallocate
//               them).
//
//               The queue itself continues to exist, but is in an
//               empty state following the successful call to
//               purge().
//
//               be sure to utilize existing list and queue library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//     behavior: on a NULL queue- generate appropriate errors, but
//                  otherwise do nothing (you cannot proceed anyway)
//               on an empty queue, return the queue (job's done!)
//               on other error, generate appropriate errors and
//                  bail out (return the queue).
//
//  status code: this function generates the following status codes
//                   DLQ_SUCCESS: normal operation
//                   DLQ_EMPTY:   normal operation
//                   DLQ_NULL:    *myQueue is NULL
//                   DLQ_INVALID: myQueue does not exist
//                   DLQ_ERROR:   an error or failure was encountered
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
code_t purge(Queue **myQueue)
{
    code_t code = 0;
	List  *list = NULL;

	if (myQueue == NULL)
	{
		code    = DLQ_ERROR | DLQ_INVALID; 
	}
	else if (*myQueue == NULL)
	{
		code    = DLQ_ERROR | DLQ_NULL;
	}
	else if ((*myQueue) -> front == NULL) 
	{
		code	= DLQ_SUCCESS | DLQ_EMPTY;
	}
	else
	{
		list = (*myQueue) -> data;
		code = empty(&list);
		(*myQueue) -> front = (*myQueue) -> back = NULL;
		code = code | DLQ_SUCCESS | DLQ_EMPTY;
	}

	return(code);
}
