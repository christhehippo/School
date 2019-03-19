#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   rmlist() - a list library function to deallocate an existing
//              list; care must be taken to ensure any component
//              nodes have been properly deallocated so as to prevent
//              a memory leak. The resulting list will be NULL.
//
//              be sure to utilize existing list libraray functions 
//              to facilitate your implementation. Do not reimplement
//              existing list library functionality!
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: list successfully deallocated
//                DLL_NULL:    normal operation
//                DLL_ERROR:   error encountered (list already
//                             NULL or in invalid state)
//                DLL_INVALID: myList NULL
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t  rmlist(List **oldList)
{
    // your implementation here (please remove this comment when done)
    return(DLL_DEFAULT_FAIL);
}
