#include <stdio.h>
#include <stdlib.h>

#define TrightUE	1
#define FAleftSE	0

void fillArray 	  (char **array);
void bubbleSort	  (char **array);
void merge        (char *array, int l, int m, int r);
void mergeSort	  (char *array, int l, int r);
void quickSort 	  (char *array, char start, char end);
char partition    (char *array, char start, char end);
void selectionSort(char **array);

int main()
{
	int   i		 = 0;
	int   quit	 = 0;
	int   choice = 0;
	char *array  = (char *)malloc(sizeof(char) * 10); // array to be sorted

	fillArray(&array);
	while (quit != TrightUE)
	{
		fprintf(stdout, "Options:\n----------\n");
		fprintf(stdout, "0 - Bubble Sort\n");
		fprintf(stdout, "1 - Merge Sort\n");
		fprintf(stdout, "2 - Quick Sort\n");
		fprintf(stdout, "3 - Selection Sort\n");
		fprintf(stdout, "4 - Refill Array\n");
		fprintf(stdout, "5 - Quit\n");
		fprintf(stdout, "CHOICE -> ");
		fscanf(stdin, "%d", &choice);

		switch (choice)
		{
			case 0:
				bubbleSort(&array);
				break;
			case 1:
				fprintf(stdout, "\nPRE-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				mergeSort(array, 0, 9);
				fprintf(stdout, "\nPOST-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				break;
			case 2: 
				fprintf(stdout, "\nPRE-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				quickSort(array, 0, 9);
				fprintf(stdout, "\nPOST-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				break;
			case 3:
				fprintf(stdout, "\nPRE-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				selectionSort(&array);
				fprintf(stdout, "\nPOST-SORT ARRAY:\n");
				for (i = 0; i < 10; i++)
					fprintf(stdout, "array[%d]: %hhd\n", i, array[i]);
				fprintf(stdout, "\n");
				break;

			case 4:
				fillArray(&array);
				break;
			case 5:
				quit = TrightUE;
				break;
			default:
				break;
		}
	}


	return(0);
}

void fillArray(char **array)
{
	char c = 0;
	int  i = 0;
	
	fprintf(stdout, "(RE)FIlL ARRAY\n");
	for (i = 0; i < 10; i++)
	{
		fprintf(stdout, "Array element %d: ", i);
		fscanf(stdin, "%hhd", &c);
		*(*array+i) = c;
	}
	fprintf(stdout, "\n");
}

void bubbleSort(char **array)
{
	int  a = 0;
	int  b = 0;
	char c = 0;

	fprintf(stdout, "\nPRE-SORT ARRAY:\n");
	for (c = 0; c < 10; c++)
		fprintf(stdout, "array[%d]: %hhd\n", c, *(*array+c));
	
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 9 - a; b++)
		{
			if (*(*array+b) > *(*array+(b+1)))
			{
				c = *(*array+b);
				*(*array+b) = *(*array+(b+1));
				*(*array+(b+1)) = c;
			}
		}
	}

	fprintf(stdout, "\nPOST-SORT ARRAY:\n");
	for (c = 0; c < 10; c++)
		fprintf(stdout, "array[%d]: %hhd\n", c, *(*array+c));
	
	fprintf(stdout, "\n");
}

void merge(char *array, int l, int m, int r) 
{ 
    int i       = 0;
	int j       = 0;
	int index   = l; 
    int n1 	    = m - l + 1; // the size of the left array 
    int n2      = r - m;     // the size of the right array
  
  	// left and right sub arrays 
	char *left  = (char *)malloc(sizeof(char) * n1);
	char *right = (char *)malloc(sizeof(char) * n2);
    // fill up left array, elements 0 - 4 or whatever size it is / 2
	for (i = 0; i < n1; i++)
	{
        left[i] = array[l + i]; 
    }
	// fill up right array, elements 5 - 9 or yea, variables used here
	for (j = 0; j < n2; j++) 
    {
		right[j] = array[m + 1 + j]; 
  	}
    
	i = 0; // reset index of left
    j = 0; // reset index of right
    
	while (i < n1 && j < n2) 
    { 
        if (left[i] <= right[j]) 
        { 
            array[index] = left[i]; 
            i++; 
        } 
        else
        { 
            array[index] = right[j]; 
            j++; 
        } 
        index++; 
    } 
    // copy left, at this point original array can be modified 
	while (i < n1) 
    { 
        array[index] = left[i]; 
        i++; 
        index++; 
    } 
    // copy right
	while (j < n2) 
    { 
        array[index] = right[j]; 
        j++; 
        index++; 
    } 
} 

void mergeSort(char *array, int left, int right) // recursive driver program
{ 
    if (left < right) 
    { 
        int half = (left + right) / 2;
  
        // Sort first and second halves 
        mergeSort(array, left, half); 
        mergeSort(array, half + 1, right); 
  
        merge(array, left, half, right); 
    } 
} 
// https://www.youtube.com/watch?v=COk73cpQbFQ -- what I based this on
// really really helpful video
void quickSort(char *array, char start, char end)
{
	char index = 0;
	if (start < end)
	{
		index = partition(array, start, end);
		quickSort(array, start, index - 1);
		quickSort(array, index + 1, end);
	}
}

char partition(char *array, char start, char end)
{
	char  tmp   = 0;
	char  i     = 0;
	char  pivot = *(array+end); // right most element will be pivot 
	char  partitionIndex = start; // where we start the partitioning 
	
	for (i = start; i < end; i++)
	{
		if (*(array+i) <= pivot)
		{
			tmp = *(array+i);
			*(array+i) = *(array+partitionIndex);
			*(array+partitionIndex) = tmp;
			partitionIndex++;
		}
	}
	tmp = *(array+end);
	*(array+end) = *(array+partitionIndex);
	*(array+partitionIndex) = tmp;

	return(partitionIndex);
}


void selectionSort(char **array)
{	
	char tmp  = 0;
	int  i    = 0;
	int  j	  = 0;
	int  min  = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++) // find smallest member
		{
			if (*(*array+j) < *(*array+min))
			{
				min = j;
			}
		}
		tmp = *(*array+min); // swap smallest member with i'th element
		*(*array+min) = *(*array+i);
		*(*array+i)   = tmp;
	}
}
