#include "grade.h"

grade :: grade()
{
	int index = 0;
	for (index = 0; index < 100; index++)
	{
		grades[index] = 0;
	}
	position = 0;
}

FILE* grade :: fileOpen()
{
	FILE* fp;
	fp = fopen("cprog.status.flat", "r");
	return (fp);
}

void grade :: fileClose(FILE* fp)
{
	fclose(fp);
}

void grade :: gradesFill(FILE* fp)
{
	int count = 0;
	while (fscanf(fp, "%d", &grades[count]) != EOF)
	{
		count++;
	}
}

int grade :: getPos(int neg)
{
	int index = 0;
	while (grades[index] != neg)
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

int grade :: getEarned(int pos)
{
	int earnedScore = 0;
	position = pos + 1;
	while (grades[position-1] >= 0)
	{
		earnedScore = earnedScore + grades[position];
		position = position + 2;
	}
	earnedScore = earnedScore - grades[position-3];
	return (earnedScore);
}

// int grade :: getMax(int pos)
//{

//}
