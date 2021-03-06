#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "support.h"

int main()
{
    Tree   *myTree                   = NULL;
    List   *tmpList                  = NULL;
    Node   *tmp                      = NULL;
    char    data[]                   = { 11, 9, 13, 11, 7, 6, 4, 2, 8 };
    int     testno                   = 0;
    int     variation                = 0;
    int     k                        = 0;
    int     num                      = 0;
    code_t  result                   = 0;

    char *output[6];
    output[0]                        = "(NULL)";
    output[1]                        = "-> NULL";
    output[2]                        = "-> NULL";
    output[3]                        = "2 -> 4 -> 6 -> 7 -> 8 -> 9 -> 11 -> 13 -> NULL";
    output[4]                        = "2 -> 4 -> 7 -> 8 -> 9 -> 13 -> NULL";
    output[5]                        = "2 -> 8 -> 9 -> 13 -> NULL";

    fprintf(stdout,             "UNIT TEST: tree library grabnode() function\n");
    fprintf(stdout,             "===========================================\n");

    //////////////////////////////////////////////////////////////////
    //
    // number of test cycles
    //
    for (variation = 0; variation < 6; variation++)
    {
        //////////////////////////////////////////////////////////
        //
        // there the NULL run, be sure to allocate a tree
        //
        if (variation           == 1)
        {
            mktree(&myTree, 0);
            tmp                  = myTree -> root;
        }

        //////////////////////////////////////////////////////////
        //
        // for variation 2, test a tree with only one node
        //
        if (variation           == 2)
        {
            if (myTree -> root  == NULL)
            {
                tmp              = NULL;
                mknode(&tmp, data[0]);
                addnode(&myTree, tmp);
                tmp              = myTree -> root;
            }
        }

        //////////////////////////////////////////////////////////
        //
        // populate our tree for the remaining half of tests
        //
        else if (variation      == 3)
        {
            if (myTree -> root  == NULL)
            {
                for (k = 0; k < 9; k++)
                {
                    tmp              = NULL;
                    mknode(&tmp, data[k]);
                    addnode(&myTree, tmp);
                }

                tmp              = myTree -> root;
            }
        }

        //////////////////////////////////////////////////////////
        //
        // set up the specific manipulation of the populated tree
        //
        switch (variation)
        {
            case 3:
                tmp              = myTree -> root;
                break;

            case 4:
                tmp              = myTree -> root;
                result           = grabnode(&myTree, &tmp);
                tmp              = myTree -> root -> left -> left;
                break;

            case 5:
                tmp              = myTree -> root -> left -> left;
                result           = grabnode(&myTree, &tmp);
                tmp              = myTree -> root -> left;
                break;
        }

        //////////////////////////////////////////////////////////
        //
        // grab a node from the tree
        //
        result                   = grabnode(&myTree, &tmp);

        fprintf(stdout,     "Test %d: (iteration %d) ", testno++, variation);

        //////////////////////////////////////////////////////////
        //
        // display a description of the current tree state
        //
        if (variation           == 0)
            fprintf(stdout, "grabnode from NULL tree ...\n");
        else if (variation      == 1)
            fprintf(stdout, "grabnode from empty tree ...\n");
        else if (variation      == 2)
            fprintf(stdout, "grabnode from tree with one node ...\n");
        else
            fprintf(stdout, "grabnode from populated tree ...\n");

        //////////////////////////////////////////////////////////
        //
        // display the results
        //
        fprintf(stdout,     " you have: ");
		tmpList = NULL;
        traverse_r(myTree, &tmpList, PREORDER);
        display(tmpList, 0);
        fprintf(stdout,     "should be: %s\n\n", output[num++]); 
        fflush (stdout);

        fprintf(stdout, "Test %d: Checking results ...\n", testno++);
        fprintf(stdout, " you have: ");
        lscodes(result);

        fprintf(stdout, "should be: ");

        if (variation == 0)
            lscodes(DLT_ERROR | DLT_NULL);
        else if (variation == 1)
            lscodes(DLT_ERROR | DLT_EMPTY);
        else if (variation == 2)
            lscodes(DLT_SUCCESS | DLT_EMPTY);
        else if (variation >  2)
            lscodes(DLT_SUCCESS);

        fprintf(stdout, "\n");
        fflush (stdout);
    }
    return(0);
}
