#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printA(char *array);

int main()
{
	char *dividendA  = (char *)malloc(sizeof(char) * 9);
	char *divisorA   = (char *)malloc(sizeof(char) * 5);
	char *part		 = (char *)malloc(sizeof(char) * 6);
	char *other		 = (char *)malloc(sizeof(char) * 5);
	char *sub		 = (char *)malloc(sizeof(char) * 7);
	char *subOld	 = (char *)malloc(sizeof(char) * 7);
	int   tmp        = 0;
	int   space		 = 0;
	int   scale		 = 0;
	int   i 		 = 0;
	int   partInt	 = 0;
	int   strLength  = 0;
	int   divisor    = 0;
	int   dividendL  = 0;
	int   dividend   = 0;
	int   carry		 = 0;

	srand(time(NULL));

	dividend  = rand() % (999999999 - 1000000) + 1000000;
	divisor   = rand() % (99999 - 100) + 100;
	sprintf(divisorA, "%d", divisor);	
	sprintf(dividendA, "%d", dividend);
	
	//get length of divisor
	for (i = 0; i < 5; i++)
	{
		if (divisorA[i] > 47 && divisorA[i] < 58)
			strLength++;
	}
	// some things may seem odd but I am trying to make the switch to letters easier 
	// for next program
	fprintf(stdout, "           %5d\n", dividend / divisor); // answer
	fprintf(stdout, "     +----------\n");
	fprintf(stdout, "%5s| %9s\n", divisorA, dividendA);
	
	
	for (i = 0; i < 6; i++)
		part[i] = 0;
	for (i = 0; i < strLength; i++)
	{
		part[i] = dividendA[i]; 
	}
	for (i = 0; i < 9; i++)
	{
		if (dividendA[i] > 47 && dividendA[i] < 58)
			dividendL++;
	}

	partInt = atoi(part); // isolated the same digit size part
	scale = partInt / divisor;
	if (scale == 0)
	{
		part[strLength] = dividendA[strLength];
		partInt = atoi(part);
		scale = partInt / divisor;
	}
	tmp = partInt;
	partInt = divisor * scale;
	sprintf(other, "%d", partInt);
	for(i = 0; i < 6 + space; i++)
		fprintf(stdout, " ");
	fprintf(stdout, "-%s\n", other);
	for(i = 0; i < 7 + space; i++)
		fprintf(stdout, " ");
	
	for (i = 0; i < 6; i++)
	{
		if (other[i] > 47 && other[i] < 58)
			fprintf(stdout, "=");
	}
	fprintf(stdout, "\n");
	space++;
		
	while (1)
	{
		for (i = 0; i < 7; i++)
	 		sub[i] = 0;
	
		sprintf(sub, "%d", tmp - partInt);
		for (i = 0; i < 7; i++)
		{
			if (sub[i] < 47)
			{
				sub[i] = dividendA[strLength+carry];
				carry++;
				break;
			}
		}
		for (i = 0; i < 7; i++)
			subOld[i] = sub[i];
	
		for(i = 0; i < 7 + space; i++)
			fprintf(stdout, " ");
		
		fprintf(stdout, "%s\n", sub);
	
		for (i = 0; i < 6 + space; i++)
			fprintf(stdout, " ");
		
		tmp = atoi(sub);
		scale = tmp / divisor;
		tmp = divisor * scale;
		for (i = 0; i < 7; i++)
			sub[i] = 0;

		sprintf(sub, "%d", tmp);
		fprintf(stdout, "-%s\n", sub);
	
		for (i = 0; i < 7 + space; i++)
			fprintf(stdout, " ");
		space++;
		for (i = 0; i < 7; i++)
		{
			if (sub[i] > 47)
				fprintf(stdout, "=");
		}
		fprintf(stdout, "\n");	
		
		tmp  = atoi(subOld);
		partInt = atoi(sub);


		if (dividendL == strLength + carry)
			break;
	}	

	for (i = 0; i < 6 + space; i++)
		fprintf(stdout, " ");

	for (i = 0; i < 7; i++)
		sub[i] = 0;
	
	sprintf(sub, "%d", tmp - partInt);
	fprintf(stdout, "%s\n", sub);

	


	return(0);
}

void printA(char *array) // prototype for lettering variation 
{
	// some lettering conversion things here to be added
	fprintf(stdout, "%-9s", array);
}
