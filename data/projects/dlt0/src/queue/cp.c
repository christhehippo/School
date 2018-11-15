#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//   cpqueue() - duplicate a given queue (especially the state of
//               its contents), in a new queue.
//
//               be sure to utilize existing list and queue library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLQ_SUCCESS:     normal operation
//                 DLQ_CREATE_FAIL: *newQueue already exists
//                 DLQ_EMPTY:       curQueue is EMPTY
//                 DLQ_NULL:        queue is NULL
//                 DLQ_INVALID:     queue does not exist
//                 DLQ_ERROR:       an error occurred
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
code_t cpqueue(Queue *curQueue, Queue **newQueue)
{
	code_t code  = 0;
	List  *list  = NULL;
	List  *listc = NULL;

	if (newQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_INVALID;
	}
	else if (*newQueue != NULL)
	{
		code = DLQ_ERROR | DLQ_CREATE_FAIL;
	}
	else if (curQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_NULL;
	}
	else if (curQueue -> front == NULL)
	{
		code = mkqueue(newQueue, curQueue -> buffer);
	}
	else
	{
		mkqueue(newQueue, curQueue -> buffer);
		list = curQueue -> data;
		code = code | cplist(list, &listc);
		(*newQueue) -> data  = listc;
		(*newQueue) -> front = listc -> lead;
		(*newQueue) -> back  = listc -> last;
		code = DLQ_SUCCESS | code;
	}



	return(code);

}
