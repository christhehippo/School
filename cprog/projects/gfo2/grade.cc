#include "grade.h"

grade :: grade()
{
	int index = 0;
	for (index = 0; index < 100; index++)
	{
		grades[index] = 0;
	}
}

void grade :: gradesFill(FILE* fp)
{
	int count = 0;
	while (fscanf(fp, "%d", &grades[count]) != EOF)
	{
//		fprintf(stdout, " grades[%d] = %d\n", count, grades[count]);
		count++;
	}
}

int grade :: getPos(int pos)
{
	int index = 0;
	while (grades[index] != pos)
	{
		index++;
	}
	return (index); 
}

int grade :: getGrade(int pos)
{
	position = pos;
	return (grades[position]);
}
int grade :: eC(int num)
{
	if (num == 0)
	{
		return(grades[42]);
	}
	else if (num == 1)
	{
		return(grades[21]);
	}
	else
	{
		return(grades[71]);
	}
}
int grade :: esJour()
{
	int score = 0;
	int index = 1;
	for (index = 1; index < 21; index = index + 2)
	{
		score = score + grades[index];	
//		fprintf(stdout, "esPart: %d\n", score);
	}
//	jourEC = grades[index+2];	
	return(score);
}

int grade :: msJour()
{
	int index = 2;
	int score = 0;
	for (index = 2; index < 22; index = index + 2)
	{
		score = score + grades[index];
	}
	return(score);
}

int grade :: esPart()
{
	int score = 0;
	int index = 24;
	for (index = 24; index < 48; index = index + 2)
	{
		score = score + grades[index];	
//		fprintf(stdout, "esPart: %d\n", score);
	}
	score = score - 24;
//	partEC = 24;
	return(score);
}

int grade :: msPart()
{
	int score = 0;
	int index = 25;
	for (index = 25; index < 49; index = index + 2)
	{
		score = score + grades[index];
	}
	return(score);
}
int grade :: esProj()
{
	int score = 0;
	int index = 49;
	for (index = 49; index < 73; index = index + 2)
	{
		score = score + grades[index];	
//		fprintf(stdout, "esProj: %d\n", score);
	}
	score = score - 108;
//	partEC = grades[index+2];	
	return(score);
}

int grade :: msProj()
{
	int score = 0;
	int index = 50;
	for (index = 50; index < 72; index = index + 2)
	{
		score = score + grades[index];
	}
	return(score);
}

int grade :: scoreOutOf(int a, int b, int newBase)
{
	float score = (newBase * a) / b;
	return(score);
}

int grade :: totalInt(int a, int b, int c)
{
	int total = a + b + c;
	return(total);
}

float grade :: totalFloat(int a, int b, int newBase)
{
	float score = ((float)newBase * (float)a) / (float)b;
	return(score);
}

void grade :: letGrade(float i)
{
	fprintf(stdout, "Grade:                             ");
	if (i >= 100.00)
	{
		fprintf(stdout, " A");
	}
	else if (i >= 94.00)
	{
		fprintf(stdout, "A-");
	}
	else if (i >= 88.00)
	{
		fprintf(stdout, "B+");
	}
	else if (i >= 82.00)
	{
		fprintf(stdout, " B");
	}
	else if (i >= 76.00)
	{
		fprintf(stdout, "B-");
	}
	else if (i >= 70.00)
	{
		fprintf(stdout, "C+");
	}
	else if (i >= 64.00)
	{
		fprintf(stdout, "C");
	}
	else if (i >= 58.00)
	{
		fprintf(stdout, " D");
	}
	else
	{
		fprintf(stdout, " F");
	}
}
