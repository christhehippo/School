#include <stdio.h>
#include <stdlib.h>




int main (int argc, char **argv)
{
	FILE *grades	  = NULL;
	int   i           = 0;
	int   tmp 		  = 0;
	int   tmp2        = 0;
	int   earned      = 0;
	int   max         = 0;
	int   bonus       = 0;
	int   weeks       = 0;
	int   earnedGrade = 0;
	float final		  = 0;
	

	grades = fopen(argv[1], "r");
	if (grades     == NULL)
	{
		fprintf(stderr, "Error opening %s\n", argv[1]);
	}

	// skip first -1
	fscanf(grades, "%d", &tmp);

	// get initial values for first loop iteration
	fscanf(grades, "%d", &tmp);
	fscanf(grades, "%d", &tmp2);

	while (tmp >= 0)
	{
		// check if bonus was earned
		if (tmp > tmp2)
			bonus = bonus + (tmp - tmp2);
		// check if we add to the avg divisor
		if (tmp2 != 0)
			weeks++;

		earned = earned + tmp;
		max    = max    + tmp2;

		fscanf(grades, "%d", &tmp);
		// if we hit the end, lets not store the next earned grade in tmp2
		if (tmp >= 0)
			fscanf(grades, "%d", &tmp2);
	}

	fprintf(stdout, "      Journal:%4d+%-3d/%4d => %2d / 13\n", earned - bonus, bonus, max, (earned*13)/max);
	earnedGrade = earnedGrade + ((earned*13) / max); // add up total so far
	// journal done --------------------------------------------------

	earned = max = weeks = bonus = 0;
	// get initial values for first 
	fscanf(grades, "%d", &tmp);
	fscanf(grades, "%d", &tmp2);

	while (tmp >= 0)
	{
		// check if bonus was earned
		if (tmp > tmp2)
			bonus = bonus + (tmp - tmp2);
		// check if we add to the avg divisor
		if (tmp2 != 0)
			weeks++;

		earned = earned + tmp;
		max    = max    + tmp2;

		fscanf(grades, "%d", &tmp);
		// if we hit the end, lets not store the next earned grade in tmp2
		if (tmp >= 0)
			fscanf(grades, "%d", &tmp2);
	}
	
	fprintf(stdout, "Participation:%4d+%-3d/%4d => %2d / 13\n", earned - bonus, bonus, max, (earned*13)/max);
	earnedGrade = earnedGrade + ((earned*13) / max); // add up total so far
	// Participation done -------------------------------------------
	
	earned = max = weeks = bonus = 0;
	// get initial values for first 
	fscanf(grades, "%d", &tmp);
	fscanf(grades, "%d", &tmp2);

	while (tmp >= 0)
	{
		// check if bonus was earned
		if (tmp > tmp2)
			bonus = bonus + (tmp - tmp2);
		// check if we add to the avg divisor
		if (tmp2 != 0)
			weeks++;

		earned = earned + tmp;
		max    = max    + tmp2;

		fscanf(grades, "%d", &tmp);
		// if we hit the end, lets not store the next earned grade in tmp2
		if (tmp >= 0)
			fscanf(grades, "%d", &tmp2);
	}
	
	fprintf(stdout, "     Projects:%4d+%-3d/%4d => %2d / 52\n", earned - bonus, bonus, max, (earned*52)/max);
	earnedGrade = earnedGrade + ((earned*52) / max); // add up total so far

	// final outputs
	fprintf(stdout, "--------------------------------------\n");
	fprintf(stdout, "Total:                         %d / 78\n", earnedGrade);
	fprintf(stdout, "======================================\n");
	final = ((float)earnedGrade / 78) * 100;

	fprintf(stdout, "Score:                          %.3f\n", final);
	fprintf(stdout, "Grade:                              ");

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
