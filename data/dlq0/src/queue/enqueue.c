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
    // to be implemented (remove this comment upon completion)
    return (DLQ_DEFAULT_FAIL);
}
