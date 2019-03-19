#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printA(char *array, char *key);

int main()
{
	char *dividendA  = (char *)malloc(sizeof(char) * 9);
	char *divisorA   = (char *)malloc(sizeof(char) * 5);
	char *part		 = (char *)malloc(sizeof(char) * 6);
	char *other		 = (char *)malloc(sizeof(char) * 5);
	char *sub		 = (char *)malloc(sizeof(char) * 7);
	char *subOld	 = (char *)malloc(sizeof(char) * 7);
	char *answer	 = (char *)malloc(sizeof(char) * 6);
	char *key		 = (char *)malloc(sizeof(char) * 9);
	int   same_flag  = 0;
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

	for (i = 0; i < 9; i++)
	{
		do
		{
			same_flag = 0;
			key[i] = rand() % (90 - 65) + 65;
			for (tmp = 0; tmp < 9; tmp++)
			{
				if (i != tmp)
				{
					if (key[i] == key[tmp])
						same_flag++;
				}
			}
		} while (same_flag == 1);
	}

	//get length of divisor
	for (i = 0; i < 5; i++)
	{
		if (divisorA[i] > 47 && divisorA[i] < 58)
			strLength++;
	}
	// some things may seem odd but I am trying to make the switch to letters easier 
	// for next program
	fprintf(stdout, "           ");
	sprintf(answer, "%d", dividend / divisor);
	printA(answer, key);
	fprintf(stdout, "\n");
	fprintf(stdout, "     +----------\n");
	if (strLength < 5)
	{
		if (strLength == 4)
			fprintf(stdout, " ");
		else if (strLength == 5)
			fprintf(stdout, "  ");
	}
	printA(divisorA, key);
	fprintf(stdout, "| ");
	// moving to where i calculate length of dividend to print that 

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
	if (dividendL < 9)
	{
		if (9 - dividendL == 1)
			fprintf(stdout, " ");
		else
			fprintf(stdout, "  ");
	}
	printA(dividendA, key);
	fprintf(stdout, "\n");

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
	fprintf(stdout, "-");
	printA(other, key);
	fprintf(stdout, "\n");
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
		
		printA(sub, key);
		fprintf(stdout, "\n");
	
		for (i = 0; i < 6 + space; i++)
			fprintf(stdout, " ");
		
		tmp = atoi(sub);
		scale = tmp / divisor;
		tmp = divisor * scale;
		for (i = 0; i < 7; i++)
			sub[i] = 0;

		sprintf(sub, "%d", tmp);
		fprintf(stdout, "-");
		printA(sub, key);
		fprintf(stdout, "\n");
	
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
	printA(sub, key);
	fprintf(stdout, "\n");

	fprintf(stdout, "LETTERDIVISION: %s\n", key);	


	return(0);
}

void printA(char *array, char *key) // prototype for lettering variation 
{
	int i	   = 0;
	int length = strlen(array);
	for (i = 0; i <= length; i++)
	{
		if (array[i] == '0')
			fprintf(stdout, "%c", key[0]);
		else if (array[i] == '1')
			fprintf(stdout, "%c", key[1]);
		else if (array[i] == '2')
			fprintf(stdout, "%c", key[2]);
		else if (array[i] == '3')
			fprintf(stdout, "%c", key[3]);
		else if (array[i] == '4')
			fprintf(stdout, "%c", key[4]);
		else if (array[i] == '5')
			fprintf(stdout, "%c", key[5]);
		else if (array[i] == '6')
			fprintf(stdout, "%c", key[6]);
		else if (array[i] == '7')
			fprintf(stdout, "%c", key[7]);
		else if (array[i] == '8')
			fprintf(stdout, "%c", key[8]);
		else if (array[i] == '9')
			fprintf(stdout, "%c", key[9]);
	}
}
