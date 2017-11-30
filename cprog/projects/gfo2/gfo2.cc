#include "grade.h"

int main()
{
	// make object
	grade grade;
	// open file
	FILE* fp = fopen("cprog.status.flat", "r");
	// fill array with file data
	grade.gradesFill(fp);
	// print stuff
	// Partic line 
	fprintf(stdout, "Participation: %3d+%-3d/", grade.esPart(), grade.eC(0));
	fprintf(stdout, "%3d", (grade.msPart()));
	fprintf(stdout, " => %2d / 13\n", grade.scoreOutOf((grade.esPart()+grade.eC(0)), grade.msPart(), 13));
	// Journ line
	fprintf(stdout, "      Journal: %3d+%-3d/", grade.esJour(), grade.eC(1));
	fprintf(stdout, "%3d", (grade.msJour()));
	fprintf(stdout, " => %2d / 13\n", grade.scoreOutOf((grade.esJour()+grade.eC(1)), grade.msJour(), 13));
	// Project line
	fprintf(stdout, "     Projects: %3d+%-3d/", grade.esProj(), grade.eC(2));
	fprintf(stdout, "%3d", (grade.msProj()));
	fprintf(stdout, " => %2d / 52\n", grade.scoreOutOf((grade.esProj()+grade.eC(2)), grade.msProj(), 52));
	// total line
	fprintf(stdout, "-------------------------------------\n");	
	fprintf(stdout, "Total:                        %2d / 78\n", grade.totalInt((grade.scoreOutOf((grade.esProj()+grade.eC(2)), grade.msProj(), 52)), (grade.scoreOutOf((grade.esJour()+grade.eC(1)), grade.msJour(), 13)), (grade.scoreOutOf((grade.esPart()+grade.eC(0)), grade.msPart(), 13))));
	// other lines
	fprintf(stdout, "=====================================\n");
	fprintf(stdout, "Score:                         %.3f\n", grade.totalFloat((grade.totalInt((grade.scoreOutOf((grade.esProj()+grade.eC(2)), grade.msProj(), 52)), (grade.scoreOutOf((grade.esJour()+grade.eC(1)), grade.msJour(), 13)), (grade.scoreOutOf((grade.esPart()+grade.eC(0)), grade.msPart(), 13)))), 78, 100));
	
	grade.letGrade(grade.totalFloat((grade.totalInt((grade.scoreOutOf((grade.esProj()+grade.eC(2)), grade.msProj(), 52)), (grade.scoreOutOf((grade.esJour()+grade.eC(1)), grade.msJour(), 13)), (grade.scoreOutOf((grade.esPart()+grade.eC(0)), grade.msPart(), 13)))), 78, 100));
	fprintf(stdout, "\n");
	
// This was a bit of a learning experience combined with poor time management	
// Sorry for the massive lines	
	
	
	
	
	// close file
	fclose(fp);

		
		
	return(0);
}
