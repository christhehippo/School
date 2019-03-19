#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// lgetpos() - a group library utility function to identify the actual
//             position of a given list in an indicated list group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group/list), return negative
//             value (-1), on out-of-bounds condition, return -2
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
sli lgetpos(Group *myListGroup, List *given)
{
    // your implementation here (please remove this comment when done)
    return(-3);
}

//////////////////////////////////////////////////////////////////////
//
// lsetpos() - a group library utility function to set a list pointer
//             to the list at the indicated position of a group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL/UNDEFINED group or
//             negative/out-of-bounds pos), return NULL.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
List *lsetpos(Group *myListGroup, sli pos)
{
    // your implementation here (please remove this comment when done)
    return(UNDEFINED);
}
