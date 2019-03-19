#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permute(char *word, int start, int n, int *num);

int main(int argc, char **argv)
{
	int   i    = 1;
	int   num  = 0;
	char *word = (char *)malloc(sizeof(char) * 128);
	

	while (i < argc) // get word
	{
		strcat(word, argv[i]);
		i++;
		if (i != argc)
			strcat(word, " ");
	}
	
	fprintf(stdout, "ANAGRAMS: \n");
	permute(word, 0, (strlen(word)-1), &num);
	fprintf(stdout, "%d COMBINATIONS\n", num);
	return(0);
}


void permute(char *word, int start, int n, int *num)
{
	char tmp = 0;
	int index = 0;
	if (start == n)
	{
		*num = *num + 1;
		fprintf(stdout, "%s\n", word);
	}
	else
	{
		for (index = start; index <=n; index++)
		{
			// swap around element
			tmp = *(word+start);
			*(word+start) = *(word+index);
			*(word+index) = tmp;
			permute(word, start+1, n, num);  // recursive method of generating permutations
			// swap back
			tmp = *(word+start);
			*(word+start) = *(word+index);
			*(word+index) = tmp;
		}
	}
}
