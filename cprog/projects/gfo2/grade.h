#ifndef _GRADE_H
#define _GRADE_H

#include <stdio.h>
#include <stdlib.h>

class grade
{
	public:
		grade(); // Constructor, initializes a 100 element array of 0
		void gradesFill(FILE* fp); // Populate grades array
		int getPos(int pos); // Return position in array of 'neg'
		int getGrade(int pos); // Return the grade at that value
//		int getEarned(int pos); // Calculates the earned portion of your grade
//		int getMax(int pos); // Returns max possible score
		int test(int a);
		int esPart();
		int msPart();
		int esJour();
		int msJour();
		int esProj();
		int msProj();
		int eC(int num);
		int total(int total, int ec);
		int scoreOutOf(int a, int b, int newBase);
		int totalInt(int a, int b, int c);
		float totalFloat(int a, int b, int newBase);
		void letGrade(float a);
	private:
		int position;
		int grades[100];
		int partEC;
		int jourEC;
		int projEC;
			
};


#endif
