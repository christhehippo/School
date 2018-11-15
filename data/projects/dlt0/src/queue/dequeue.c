#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  dequeue() - grab node off front of queue (queue is modified)
//              
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
//              the dequeued node pointer, if it exists, does not
//              need to be NULL; any existing content will be
//              discarded.
//
// status code: this function generates the following status codes
//                  DLN_INVALID:  dequeued node does not exist
//                  DLQ_SUCCESS:  normal operation
//                  DLQ_UNDERRUN: tried to dequeue() when empty
//                  DLQ_EMPTY:    queue is EMPTY
//                  DLQ_NULL:     queue is NULL
//                  DLQ_INVALID:  queue does not exist
//                  DLQ_ERROR:    error occurred (queue is NULL,
//                                underrun occurred, etc.)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t dequeue(Queue **myQueue, Node **newNode)
{
    code_t code = 0;
	Node  *tmp  = NULL;
	Node  *tmp2 = NULL;
	List  *list = NULL;

	if (myQueue == NULL)
	{
		code = DLQ_INVALID | DLQ_ERROR;
	}
	else if (*myQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_NULL;
	}
	else if (newNode == NULL)
	{
		code = DLN_INVALID | DLQ_ERROR;
	}
	else if ((*myQueue) -> front == NULL)
	{
		code = DLQ_ERROR | DLQ_UNDERRUN;
	}
	else
	{
		list = (*myQueue) -> data;
		tmp  = (*myQueue) -> front;
		tmp2 = (*myQueue) -> front -> right;
		code = obtain(&list, &tmp);
		
		if (list -> qty == 0)
		{
			(*myQueue) -> front = (*myQueue) -> back = NULL;
			*newNode = tmp;
			code = code | DLQ_EMPTY | DLQ_SUCCESS;
		}
		else
		{
			(*myQueue) -> front = tmp2;
			*newNode = tmp;
			code = code | DLQ_SUCCESS;
		}
	}
	
	return (code);
}
