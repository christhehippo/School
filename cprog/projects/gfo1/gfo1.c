#include <stdio.h>
#include <stdlib.h>

FILE* fileOpen();
int sumEarned(int ar[], int ec);
int sumPossible(int ar[], int ec);
int baseChanger(int earned, int possible, int newBase);
float decimalGrade(int total);
void dashMaker9001();
void equaMaker9001();
void lettaG(float grade);

int main()
{
	// Open file with function
	FILE *fp = fileOpen();

	int count     =  0;
	int nums[100] = {0};
	while (fscanf(fp, "%d", &nums[count]) != EOF)
	{
		++count; //Placing the numbers in the file into an initial array
	}			 //Variable count to help with next array loop

	// Break the array up into 3 pieces
	int journalArray[30] = {0};
	int jFill = 1;
	int pos = 1;
	int jEC = 0;
	for (jFill=1; nums[jFill] != -2; jFill=jFill+1)
	{
		journalArray[jFill-1] = nums[jFill];
		pos++;
		if (nums[jFill+2] == -2)
		{
			jEC = nums[jFill];
		}
	}
	// fix jFill for later use
	jFill = jFill - 1;

	int participationArray[30] = {0};
	int parFill = 0;
	int parEC = 0;
	for (parFill=0; nums[pos+1] != -3; parFill++)
	{
		participationArray[parFill] = nums[pos+1];
		pos++;
		if (nums[pos+5] == -3)
		{	
			parEC = nums[pos+1];// WHY IS THE EXTRA CREDIT NOT THE LAST THING IN PARTICIPATION
		}
	}

	int projectArray[30] = {0};
	int proFill = 0;
	int proEC = 0;
	for (proFill=0; nums[pos+2] != -4; proFill++)
	{
		projectArray[proFill] = nums[pos+2];
		pos++;
		if (nums[pos+4] == -4)
		{
			proEC = nums[pos+2];
		}
	}
	// loop above is third and last chunk of initial array

	// function call for scores earned
	int jTotal   = sumEarned(journalArray, jFill);	
	int parTotal = sumEarned(participationArray, parFill);
	int proTotal = sumEarned(projectArray, proFill);
	// function call for possible scores 
	int jPoss   = sumPossible(journalArray, jFill);	
	int parPoss = sumPossible(participationArray, parFill);
	int proPoss = sumPossible(projectArray, proFill);
	// function call for base changing 
	int jBase13   = baseChanger(jTotal, jPoss, 13);
	int parBase13 = baseChanger(parTotal, parPoss, 13);
	int proBase52 = baseChanger(proTotal, proPoss, 52);
	int total = jBase13 + parBase13 + proBase52;
	float dGrade = decimalGrade(total);
	// output time cool
	fprintf(stdout, "Participation: %3d+%-3d/%3d =>%3d / 13\n", (parTotal-parEC), parEC, parPoss, parBase13);
	fprintf(stdout, "      Journal: %3d+%-3d/%3d =>%3d / 13\n", (jTotal-jEC), jEC, jPoss, jBase13);
 	fprintf(stdout, "     Projects: %3d+%-3d/%3d =>%3d / 52\n", (proTotal-proEC), proEC, proPoss, proBase52);
	dashMaker9001(); // bring in the heavy machinery
	fprintf(stdout, "Total:                        %2d / 78\n", total);
	equaMaker9001(); // more machinery
	fprintf(stdout, "Score:                         %.3f\n", dGrade);
	lettaG(dGrade);
	fprintf(stdout, "\n");
	fclose(fp);
	return(0);
}

FILE* fileOpen() // Open a file, well just the cprog file, could maybe change to any file but dont know how
{
	FILE *fp;
	fp = fopen("cprog.status.flat", "r");
	return (fp);
}

int sumEarned(int ar[], int ec) // take array and add even elements together (0 is even in this logic)
{
	int i = 0;
	int total = 0;
	for (i=0; i <= ec-1; i=i+2)
	{
		total = total + ar[i];
	}
	return(total);
}

int sumPossible(int ar[], int ec) // take an array and add the odd elements of it together
{
	int i = 1;
	int total = 0;
	for (i=1; i <= ec; i=i+2)
	{
		total = total + ar[i];
	}
	return(total);
}

int baseChanger(int earned, int possible, int newBase) // all purpose bse changer, started with one for 13 and one for 52
{													   // but I realized that I could just enter the base I wanted
	int score = (earned*newBase) / possible;
	return(score);
}

float decimalGrade(int total) // Takes total out of 78 and converts it to floating point decimal
{
	float score = (float)total / 78.0;
	score = score * 100.0;
	return(score);
}

void dashMaker9001() // If there were more line like this to print it might be useful

{
	fprintf(stdout, "-------------------------------------\n");
}

void equaMaker9001() // If there were more line like this to print it might be useful
{
	fprintf(stdout, "=====================================\n");
}

void lettaG(float grade) // lots of ifs to make the letter grade, dont see any other way to do this
{
	fprintf(stdout, "Grade:                             ");
	if (grade >= 100.00)
	{
		fprintf(stdout, " A");
	}
	else if (grade >= 94.00)
	{
		fprintf(stdout, "A-");
	}
	else if (grade >= 88.00)
	{
		fprintf(stdout, "B+");
	}
	else if (grade >= 82.00)
	{
		fprintf(stdout, " B");
	}
	else if (grade >= 76.00)
	{
		fprintf(stdout, "B-");
	}
	else if (grade >= 70.00)
	{
		fprintf(stdout, "C+");
	}
	else if (grade >= 64.00)
	{
		fprintf(stdout, "C");
	}
	else if (grade >= 58.00)
	{
		fprintf(stdout, " D");
	}
	else
	{
		fprintf(stdout, " F");
	}
}
