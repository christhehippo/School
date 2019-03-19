#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_r()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_r() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the recursive implementation of traverse_r() will 
//              embody the conceptual elegance often found in
//              such solutions: shorter code, less detail-oriented,
//              and relying centrally and heavily on calling some
//              function again and again as the means of processing.
//              While you cannot alter the header file, you may want
//              to implement a custom more local function that this
//              traverse_r() function calls.
//
//              traverse_r() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_ERROR:       an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//

void inorder(Node *tmp, List **result);
void preorder(Node *tmp, List **result);
void postorder(Node *tmp, List **result);

code_t traverse_r(Tree *myTree, List **result, uc mode)
{
	code_t code = 0;
	Node  *tmp  = NULL;
	

	if (myTree == NULL)
	{
		code = DLT_ERROR | DLT_NULL;
	}
	else if (result == NULL)
	{
		code = DLT_ERROR | DLL_INVALID;
	}
	else if (mode > 2 || mode < 0)
	{
		code = DLT_ERROR;
		if (*result != NULL)
			code = code | DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_EMPTY;
	}
	else if (*result != NULL)
	{
		code = DLL_ERROR | DLL_ALREADY_ALLOC;
		if (myTree -> root == NULL)
			code = code | DLT_ERROR | DLT_EMPTY;
	}
	else if (myTree -> root == NULL)
	{
		code = mklist(result);
		code = code | DLT_SUCCESS | DLT_EMPTY;
	}
	else
	{
		mklist(result);
		tmp = myTree -> root;
		if (mode == 0) // in order
		{
			inorder(tmp, result);
			code = DLT_SUCCESS;
		}
		else if (mode == 1)
		{
			preorder(tmp, result);
			code = DLT_SUCCESS;
		}
		else if (mode == 2)
		{
			postorder(tmp, result);
			code = DLT_SUCCESS;
		}
	}
	return(code);
}

void inorder(Node *tmp, List **result)
{
	if (tmp == NULL)
		return;
	// make a new node to preserve tree 
	Node *tmp2  = NULL; 
	mknode(&tmp2, tmp -> VALUE);
	Node *right = tmp -> right;
	Node *left  = tmp -> left;

	//	add node
	append(result, (*result) -> last, tmp2);
	// do the left node , add it, call on its left node
	inorder(left, result);
	// do the right node, add it, call on its right node
	inorder(right, result);
}

void preorder(Node *tmp, List **result)
{
	if (tmp == NULL)
		return;
	
	Node *tmp2  = NULL;
	mknode(&tmp2, tmp -> VALUE);
	Node *right = tmp -> right;
	Node *left  = tmp -> left;

	preorder(left, result);
	append(result, (*result) -> last, tmp2);
	preorder(right, result);
}

void postorder(Node * tmp, List **result)
{
	if (tmp == NULL)
		return;

	Node *tmp2  = NULL;
	mknode(&tmp2, tmp -> VALUE);
	Node *right = tmp -> right;
	Node *left  = tmp -> left;

	postorder(right, result);
	append(result, (*result) -> last, tmp2);
	postorder(left, result);

}
