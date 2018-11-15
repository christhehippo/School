#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
// mkqueue() - allocate and initialize a new queue
//
//       note: the second parameter is to be the created queue's
//             maximum buffer size (bound).
//
//             be sure to utilize existing list and queue library
//             functions to facilitate your implementation. Do NOT
//             reinvent the wheel.
//
//             the front of the queue should track the first of
//             the underlying list; the back of the queue should
//             track the last node of the list.
//
//     bufsiz: a queue buffer size of 0 indicates an unbounded queue
//             > 0 will limit the total number of nodes in the queue
//
//status code: this function can generate the following status codes:
//                 DLQ_SUCCESS:     no problems encountered
//                 DLQ_EMPTY:       result of normal operation
//                 DLQ_CREATE_FAIL: error on creation
//                 DLQ_NULL:        queue remains in NULL state
//                 DLQ_INVALID:     queue does not exist
//                 DLQ_ERROR:       an error has taken place
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
code_t mkqueue(Queue **newQueue, ulli bufsiz)
{
	code_t code = 0;
	List  *list = NULL;

	if (newQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_INVALID;
	}
	else
	{
		*newQueue = (Queue *)malloc(sizeof(Queue) * 1);
		if (*newQueue == NULL)
		{
			code = DLQ_ERROR | DLQ_CREATE_FAIL;
		}
		else
		{
			code = mklist(&list);
			(*newQueue) -> data   = list;
			(*newQueue) -> front  = NULL;
			(*newQueue) -> back   = NULL;
			(*newQueue) -> buffer = bufsiz;
			code = code | DLQ_SUCCESS | DLQ_EMPTY;
		}
	}


    return (code);
}
