#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  enqueue() - place newNode onto back of given queue
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              be mindful of bounded queue limits. A bounded
//              queue can overrun, an unbounded queue cannot.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
// status code: this function generates the following status codes
//                  DLQ_SUCCESS: normal operation (success!)
//                  DLQ_NULL:    queue is NULL
//                  DLQ_OVERRUN: tried to enqueue onto a full
//                               bounded queue (considered an error)
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t enqueue(Queue **myQueue, Node *newNode)
{
	code_t code = 0;
	List  *list = NULL;
	
	if (myQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_INVALID;
	}
	else if (*myQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_NULL;
	}
	else if (newNode == NULL)
	{
		code = DLN_NULL | DLQ_ERROR;
	}
	else if ((*myQueue) -> front == NULL)
	{
		list = (*myQueue) -> data;
		append(&list, NULL, newNode);
		(*myQueue) -> front = (*myQueue) -> back = list -> lead;
		code = DLQ_SUCCESS;
	}
	else if ((*myQueue) -> buffer == (*myQueue) -> data -> qty)
	{
		code = DLQ_ERROR | DLQ_OVERRUN;
	}
	else // normal
	{
		list = (*myQueue) -> data;
		append(&list, list -> last, newNode);
		(*myQueue) -> back = list -> last;
		code = DLQ_SUCCESS;	
	}

    return (code);
}
