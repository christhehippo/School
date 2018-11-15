#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  rmqueue() - unset, nullify members, and de-allocate the given 
//              queue. You may want to call purge() to help.
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                  DLQ_SUCCESS: no problems encountered
//                  DLQ_NULL:    normal operation
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered (or queue was
//                               already NULL)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t rmqueue(Queue **curQueue)
{
    code_t code = 0;
	List  *list = NULL;
	
	if (curQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_INVALID;
	}
	else if (*curQueue == NULL)
	{
		code = DLQ_ERROR | DLQ_NULL;
	}
	else
	{
		purge(curQueue);
		list = (*curQueue) -> data;
		code = rmlist(&list);
		free(*curQueue);
		*curQueue = NULL;
		code = code | DLQ_NULL | DLQ_SUCCESS;
	}


	return(code);	
}
