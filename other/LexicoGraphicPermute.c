///////////////////////////////////////////////////////////////////////////////////
// ALGORITHM: Lexicographic Permute - Christian Cattell 
// ====================================================
//  Input: An array P, that is an n-dimensional permutation. P = a1, a2, a3,..., an
//
// Output: Either return P if P is the last permutation or the next lexicographic
//         permutation.
//
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

void lexicographicPermute(char **pNext, int n);
void swap				 (char *a1, char *a2);
void reverse			 (char **pNext, int marker, int n);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		fprintf(stderr, "Invalid number of array elements (n == 0)\n");
		return(1);
	}
	else if (argc == 2)
	{
		fprintf(stdout, "%c\n", **(argv+1));
		return(2);
	}

	int   i     = 0;
	char *p     = (char *)malloc(sizeof(char) * (argc - 1));
	char *pNext = (char *)malloc(sizeof(char) * (argc - 1));

	for (i = 0; i < argc - 1; i++)
	{
		*(p+i)     = **(argv+i+1);
		*(pNext+i) = *(p+i);
	}
	// display what we are working with
//	fprintf(stdout, "%d elements: ", argc - 1);
//	for (i = 0; i < argc - 1; i++)
//		fprintf(stdout, "%c ", *(p+i));
//	fprintf(stdout, "\n");

	lexicographicPermute(&pNext, argc - 1);


	for (i = 0; i < argc - 1; i++)
		fprintf(stdout, "%c ", *(pNext+i)); 
	
	fprintf(stdout, "\n");
	return(0);
}

void lexicographicPermute(char **pNext, int n)
{
	int  i    = 0; // loop 1 
	int  j    = 0; // loop 2
	int  mi   = 0; // marker i
	int  mj   = 0; // marker j

	for (i    = 0; i < n - 1; i++) // find right-most ai < ai+1
	{
		if (*(*pNext+i) < *(*pNext+i+1))
			mi = i;	
	}

	for (j = mi + 1; j < n; j++) // find right-most ai < aj
	{
		if (*(*pNext+mi) < *(*pNext+j))
			mj = j;
	}
	
	if (mi == 0 && mj == 0)
		return;

	swap((*pNext+mi), (*pNext+mj)); // swap ai and aj
	reverse(pNext, mi + 1, n);      // reverse the array from ai+1 to an
	
}

void swap(char *a1, char *a2)
{
	char tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void reverse(char **pNext, int marker, int n) // I feel like this reverse tool
{ 											  // became overcomplicated
	int i = 0;
	int j = 0;
	char *revTool = (char *)malloc(sizeof(char) * n);
	
	for (i = n - 1; i >= 0 ; i--)
	{
		*(revTool+j) = *(*pNext+i);
		j++;
	}
	j = 0;
	for (i = marker; i < n; i++)
	{
		*(*pNext+i) = *(revTool+j);
		j++;
	}

	free(revTool);
}
