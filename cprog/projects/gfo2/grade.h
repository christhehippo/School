#ifndef _GRADE_H
#define _GRADE_H

#include <stdio.h>
#include <stdlib.h>

class grade
{
	public:
		grade(); // Constructor, initializes a 100 element array of 0s
		
	protected:
		int getPos(int neg); // Return position in array of 'neg'
		int getGrade(int pos); // Return the grade at that value
		int getEarned(int pos); // Calculates the earned portion of your grade
		int getMax(int pos); // Returns max possible score

	private:
		FILE* fileOpen(); // Open flattened cprog status
		void fileClose(FILE* fp); // Close flattened cprog status
		void gradesFill(FILE* fp); // Populate grades array
		int position;
		int grades[100];

};


#endif
