///////////////////////////////////////////////////////////////////////////////////
// ALGORITHM: Lexicographic Permute - Christian Cattell 
// ====================================================
//  Input: An array P, that is an n-dimensional permutation. P = a1, a2, a3,..., an
//
// Output: Either return P if P is the last permutation or the next loxicographic
//         permutation.
//
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

char *lexicographicPerumute(char *p, char *pNext, int n);

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Invalid number of array elements (n == 0 or 1)\n");
		return(1);
	}

	char *p     = (char *)malloc(sizeof(char) * (argc - 1));
	char *pNext = (char *)malloc(sizeof(char) * (argc - 1));


	return(0);
}

void lexicographicPermute(char *p, char *pNext, int n)
{
	int i = 0;

	for (i = 0; i < n - 1; i++) // find ai < ai+1
	{
		if (*(p+i) < *(p+i+1))
			break;
	}
	
	if (i == n - 1) // if array is last permutation, point pNext at p
		*pNext = *p;
}
