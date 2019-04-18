///////////////////////////////////////////
// Christian Cattell === TSP Project
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void timeSum(int *bestComb, int *curComb, int *bestSum, int numCities, int city[numCities][numCities]);
void permute(int *curComb, int numCities);
void swap(int *a1, int *a2);
void reverse(int *curComb, int marker, int numCities);


int main(int argc, char **argv)
{
	FILE *fp;
	struct timeval ts;
	struct timeval te;
	gettimeofday(&ts, 0);
	if (argc != 3)
	{
		fprintf(stderr, "Error: invalid number of arguments\n");
		fprintf(stderr, "i.e. ./tsp [file].txt [number of cities]\n");
		exit(1);
	}
	if ((fp = fopen(*(argv+1), "r")) == NULL)
	{
		fprintf(stderr, "Error: invalid file\n");
		exit(2);
	}

	// allocate the matrix memory
	int  numCities = atoi(*(argv+2));
	int  city[numCities][numCities];
	char *tmpStr   = (char *)malloc(sizeof(char) * 5); // store the complete string for conversion to int 
	int *bestComb  = (int *)malloc(sizeof(int) * numCities);
	int *curComb   = (int *)malloc(sizeof(int) * numCities);
	char tmpC      = 0; // tmp var for pasring string  
	int  tmpI      = 0;
	int  bestSum   = 100000; // make the starting best time really big
	int  i 		   = 0; // index 1
	int  j 		   = 0; // index 2
	int  k         = 0; // index for parsing the chars from the file
	int  start     = 0;
	// populate matrix poorly
	for (i = 0; i < numCities; i++)
	{
		for (j = 0; j < numCities; j++)
		{
			for (k = 0; k < 5; k++) // make sure stuff is empty
			{		
				*(tmpStr+k) = 0;
			}
		
			for (k = 0; k < 5; k++)
			{
				tmpC = fgetc(fp);
				if (tmpC == ',' || tmpC == '\n')
				{
				//	fprintf(stdout, "%s\n", tmpStr);
					break;
				}	
				else if (tmpC == EOF)
				{
				//	fprintf(stdout, "%s\n", tmpStr);
					break;
				}
				else
				{
					*(tmpStr+k) = tmpC;
				}
			}
			tmpI = strtol(tmpStr, NULL, 10);
			city[i][j] = tmpI;
		}
	}

	for (i = 0; i < numCities; i++)
		*(curComb+i)  = i;
	start = *(curComb+0);
	for (i = 0; start == *(curComb+0); i++)
	{
		// check sum thing
		timeSum(bestComb, curComb, &bestSum, numCities, city);
		// get next combination
		permute(curComb, numCities);
	}
	gettimeofday(&te, 0);
	fprintf(stdout, "\n");
	for (i = 0; i < numCities; i++)
		fprintf(stdout, "%c ", (char)bestComb[i] + 65);
	fprintf(stdout, "%c > %d\n", (char)bestComb[0] + 65, bestSum);
	fprintf(stdout, "%8.4lf\n", te.tv_sec - ts.tv_sec + ((te.tv_usec - ts.tv_usec) / 1000000.0));
	fclose(fp);

	return(0);
}

// i gave up on using pointer notation halfway through this
void timeSum(int *bestComb, int *curComb, int *bestSum, int numCities, int city[numCities][numCities])
{
	int i   = 0;
	int sum = 0;
	for (i  = 0; i < numCities - 1; i++)
	{
		sum = sum + city[curComb[i]][curComb[i+1]];
	}
	sum = sum + city[curComb[numCities-1]][curComb[0]];
	for (i = 0; i < numCities; i++)
	{
		fprintf(stdout, "%c ", curComb[i] + 65); 
	}
	fprintf(stdout, "%c ", curComb[0] + 65);
	fprintf(stdout, "sum: %d\n", sum);
	if (sum < *bestSum)
	{
		*bestSum = sum;
		for (i = 0; i < numCities; i++)
		{
			bestComb[i] = curComb[i];
		}
	}
}

void permute(int *curComb, int numCities)
{
	int i    = 0; 
	int j    = 0;
	int mi   = 0;
	int mj   = 0;
	int tmp  = 0;

	for (i = 0; i < numCities - 1; i++)
	{
		if (curComb[i] < curComb[i + 1])
			mi = i;
	}
	for (j = mi + 1; j < numCities; j++)
	{
		if (curComb[mi] < curComb[j])
			mj = j;
	}

	if (mi == 0 && mj == 0)
		return;

	tmp  		= curComb[mi];
	curComb[mi] = curComb[mj];
	curComb[mj] = tmp;
	reverse(curComb, mi, numCities);
}	

void reverse(int *curComb, int marker, int numCities)
{
	int i   = 0;
	int tmp = 0;
	int midpoint = 0;
	midpoint = (numCities - marker + 1) / 2 + marker;
	for (i = marker + 1; i < midpoint; i++)
	{
		tmp = curComb[i];
		curComb[i] = curComb[numCities - (i - marker)];
		curComb[numCities - (i - marker)] = tmp;
	}
}
