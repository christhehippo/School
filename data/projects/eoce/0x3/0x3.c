/////////////////////////////////////////////////////////////////////////////////////////
//
// 	compile: gcc -c 0x3.c; gcc -o 0x3 0x3.o list.mk.o node/mk.o list/append.o
//		!! assuming you already have support object files !!
//
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "node.h"
#include "list.h"

// in case my header files dont submit right, i changed nodes to have an int, not a char
int main ()
{
	Node *tmp		  	= NULL;
	List *journal     	= NULL;
	List *projects      = NULL;
	List *participation = NULL;
	FILE *grades		= NULL;
	float final		  	= 0;
	int   holder        = 0;
	int   earned		= 0; // part earned
	int   earnedGrade   = 0; // total earned
	int   max			= 0;
	int   bonus			= 0;
	int   i				= 0;
	int   div			= 0;
	


	grades = fopen("data.status.flat", "r");
	if (grades  	   == NULL)
	{
		fprintf(stderr, "Error opening 'data.status.flat'!\n");
		exit(1);
	}
	mknode(&tmp, 0);
	mklist(&journal);
	mklist(&projects);
	mklist(&participation);

	// get ride of first -1
	fscanf(grades, "%d", &holder);
	fscanf(grades, "%d", &holder);

	while (holder >= 0)
	{
		tmp -> VALUE = holder;
		append(&journal, journal -> last, tmp);
		tmp = NULL;
		mknode(&tmp, 0);
		fscanf(grades, "%d", &holder);
	}
	
	fscanf(grades, "%d", &holder);
	while (holder >= 0)
	{
		tmp -> VALUE = holder;
		append(&participation, participation -> last, tmp);
		tmp = NULL;
		mknode(&tmp, 0);
		fscanf(grades, "%d", &holder);
	}

	fscanf(grades, "%d", &holder);
	while (holder >= 0)
	{
		tmp -> VALUE = holder;
		append(&projects, projects -> last, tmp);
		tmp = NULL;
		mknode(&tmp, 0);
		fscanf(grades, "%d", &holder);
	}

	// round up the journal values
	tmp = journal -> lead;
	for (i = 0; tmp != NULL; i++)
	{
		if ((i % 2) == 0)
		{
			if (tmp -> VALUE > tmp -> right -> VALUE)
			{
				bonus = bonus + (tmp -> VALUE - tmp -> right -> VALUE);
				earned = earned + (tmp -> right -> VALUE);
			}
			else
			{
				earned = earned + tmp -> VALUE;
			}
		}
		else
		{
			if (tmp -> VALUE != 0)
			{	
				max = max + tmp -> VALUE;
				div++;
			}
		}

		tmp = tmp -> right;
	}
	fprintf(stdout, "      Journal:%4d+%-3d/%4d => %2d / 13\n", earned, bonus, max, ((earned+bonus)*13)/max);
	earnedGrade = ((earned + bonus) * 13) / max;

	earned = bonus = max = 0;

	// participation go
	tmp = participation -> lead;
	for (i = 0; tmp != NULL; i++)
	{
		if ((i % 2) == 0)
		{
			if (tmp -> VALUE > tmp -> right -> VALUE)
			{
				bonus = bonus + (tmp -> VALUE - tmp -> right -> VALUE);
				earned = earned + (tmp -> right -> VALUE);
			}
			else
			{
				earned = earned + tmp -> VALUE;
			}
		}
		else
		{
			if (tmp -> VALUE != 0)
			{	
				max = max + tmp -> VALUE;
				div++;
			}
		}

		tmp = tmp -> right;
	}
	fprintf(stdout, "Participation:%4d+%-3d/%4d => %2d / 13\n", earned, bonus, max, ((earned+bonus)*13)/max);
	earnedGrade = earnedGrade + ((earned + bonus) * 13) / max;
	earned = bonus = max = 0;
	
	// go projects 
	tmp = projects -> lead;
	for (i = 0; tmp != NULL; i++)
	{
		if ((i % 2) == 0)
		{
			if (tmp -> VALUE > tmp -> right -> VALUE)
			{
				bonus = bonus + (tmp -> VALUE - tmp -> right -> VALUE);
				earned = earned + (tmp -> right -> VALUE);
			}
			else
			{
				earned = earned + tmp -> VALUE;
			}
		}
		else
		{
			if (tmp -> VALUE != 0)
			{	
				max = max + tmp -> VALUE;
				div++;
			}
		}

		tmp = tmp -> right;
	}
	fprintf(stdout, "     Projects:%4d+%-3d/%4d => %2d / 52\n", earned, bonus, max, ((earned+bonus)*52)/max);
	earnedGrade = earnedGrade + ((earned + bonus) * 52) / max;

	fprintf(stdout, "--------------------------------------\n");
	fprintf(stdout, "Total                          %d / 78\n", earnedGrade);
	fprintf(stdout, "======================================\n");
	final = ((float)earnedGrade / 78) * 100;
	fprintf(stdout, "Score:                           %.3f\n", final);
	fprintf(stdout, "Grade                                ");

			

	if (final >= 100)
		fprintf(stdout, " A\n");
	else if (final >= 94)
		fprintf(stdout, "A-\n");
	else if (final >= 88)
		fprintf(stdout, "B+\n");
	else if (final >= 82)
		fprintf(stdout, " B\n");
	else if (final >= 76)
		fprintf(stdout, "B-\n");
	else if (final >= 70)
		fprintf(stdout, "C+\n");
	else if (final >= 64)
		fprintf(stdout, " C\n");
	else if (final >= 58)
		fprintf(stdout, " D\n");
	else
		fprintf(stdout, " F\n");

	fclose(grades);
	return(0);
}
