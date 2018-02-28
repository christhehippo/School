#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp; //File pointer to open file 
	fp = fopen("cprog.status.flat", "r");
	
	if (fp == NULL)
	{			//Error message if the file is not found
		fprintf(stderr, "cprog.status.flat not found\n");
		exit(1);
	}

///////////////////////////////
	int nums[100] 	   = {0};
	int count     	   =  0;
//////////////////////////////
	int jourSeperator  =  0;
	int jourArray[40]  = {0};
	int jourArrayCount =  0;
	int jourEarned     =  0;
	int jourMax        =  0;
	int jourBonus      =  0;
	int jourRatio      =  0;
//////////////////////////////
	int partSeperator  =  0;
	int partArray[40]  = {0};
	int partArrayCount =  0;
	int partEarned     =  0;
	int partMax        =  0;
	int partBonus      =  0;
	int partRatio      =  0;
//////////////////////////////
	int projSeperator  =  0;
	int projArray[40]  = {0};
	int projArrayCount =  0;
	int projEarned     =  0;
	int projMax        =  0;
	int projBonus      =  0;
	int projRatio      =  0;
/////////////////////////////
	int odds    	    = 0;
	int evens   	    = 0;
	int totalEarned     = 0;
	int totalMax        = 0;
	float score 	    = 0;
/////////////////////////////

	while (fscanf(fp, "%d", &nums[count]) != EOF)
	{
		++count; //Placing the numbers in the file into an initial array
	}			 //Variable count to help with next array loop
	

	
	for (jourSeperator = 1; jourSeperator <= count; jourSeperator++)
	{
		if (nums[jourSeperator] == -2)
		{
			break;	//Break out of the loop when the grade type changes (at -2,-3,-4)
		}
		
		jourArray[jourArrayCount] = nums[jourSeperator]; //Add the values to the jouricipation array
		jourArrayCount++;
	}

	for (partSeperator = jourArrayCount+2; partSeperator <= count; partSeperator++)
	{
		if (nums[partSeperator] == -3) //Same process as prior loop, just breaking up the nums array into their 
		{							   //respective categories
			break;
		}
		
		partArray[partArrayCount] = nums[partSeperator];
		partArrayCount++;
	}

	for (projSeperator = (jourArrayCount+partArrayCount+3); projSeperator < count; projSeperator++)
	{
		if (nums[projSeperator] == -4) //And again seperating the numbers with a loop into a new array
		{
			break;
		}

		projArray[projArrayCount] = nums[projSeperator];
		projArrayCount++;
	}
	
	//Earned totals calculation done here, earned numbers are all even
	for (evens = 0; evens <= (jourArrayCount-1); evens=evens+2) //Earned credit for journals total
	{
		jourEarned = jourEarned + jourArray[evens];
		if (jourArray[evens] +jourArray[evens+1] == jourArray[evens] && jourArray[evens] != 0)
		{
			jourBonus  = jourBonus + jourArray[evens]; //Calculate the bonus
			jourEarned = jourEarned - jourArray[evens];
		}
	}
	for (evens = 0; evens <= (partArrayCount-1); evens=evens+2) //Earned credit for participation total
	{
		partEarned = partEarned + partArray[evens];
		if (partArray[evens] +partArray[evens+1] == partArray[evens] && partArray[evens] != 0)
		{
			partBonus  = partBonus + partArray[evens]; //Calculate the bonus 
			partEarned = partEarned - partArray[evens];
		}
	}
	for (evens = 0; evens <= (projArrayCount-1); evens=evens+2) //Earned credit for projects total
	{
		projEarned = projEarned + projArray[evens];
		if (projArray[evens] +projArray[evens+1] == projArray[evens] && projArray[evens] != 0)
		{
			projBonus  = projBonus + projArray[evens]; //Calculate the bonus
			projEarned = projEarned - projArray[evens];
		}
	}
	
	
	//Max possible points totals calculation done here, the max points are all odd
	for (odds = 1; odds <= jourArrayCount; odds=odds+2) //Max credit for journals total
	{
		jourMax = jourMax + jourArray[odds];
	}
	for (odds = 1; odds <= (partArrayCount-1); odds=odds+2) //Max credit for participation total
	{
		partMax = partMax + partArray[odds];
	}
	for (odds = 1; odds <= (projArrayCount-1); odds=odds+2) //Max credit for projects total
	{
		projMax = projMax + projArray[odds];
	}

	//Variables for output ratio conversion  
	partRatio = ((13*(partEarned+partBonus))/partMax);
	jourRatio = ((13*(jourEarned+jourBonus))/jourMax);
	projRatio = ((52*(projEarned+projBonus))/projMax);
	
									//Final Output
	//Participation output
	if (partBonus > 0)
	{												//Last variable in printf statement is converting the ratio to one based on 13				
		fprintf(stdout, "Participation: %3d+%-3d/%3d => %2d / 13\n", partEarned, partBonus, partMax, partRatio);
	}
	else
	{
		fprintf(stdout, "Participation: %3d    /%3d => %2d / 13\n", partEarned, partMax, partRatio);
	}

	//Journal output
	if (jourBonus > 0)
	{
		fprintf(stdout, "      Journal: %3d+%-3d/%3d => %2d / 13\n", jourEarned, jourBonus, jourMax, jourRatio);
	}
	else
	{
		fprintf(stdout, "      Journal: %3d    /%3d => %2d / 13\n", jourEarned, jourMax, jourRatio);
	}

	//Project output
	if (projBonus > 0)
	{
		fprintf(stdout, "     Projects: %3d+%-3d/%3d => %2d / 52\n", projEarned, projBonus, projMax, projRatio);
	}
	else
	{
		fprintf(stdout, "     Projects: %3d    /%3d => %2d / 52\n", projEarned, projMax, projRatio);
	}

	fprintf(stdout, "-------------------------------------\n");
	//Calculate the total score out of 78	
	totalEarned = ((13*(partEarned+partBonus))/partMax)+((13*(jourEarned+jourBonus))/jourMax)+((52*(projEarned+projBonus))/projMax);
	totalMax    = 13 + 13 + 52;
	fprintf(stdout, "Total:                        %d / %d\n", totalEarned, totalMax);
	fprintf(stdout, "=====================================\n");
	//Calculate float score
	score = ((float)totalEarned / (float)totalMax) * 100;
	fprintf(stdout, "Score:                         %-5.3f\n", score);
	fprintf(stdout, "Grade:                             ");
	//Letter grade choice logic
	if (score >= 100.00)
	{
		fprintf(stdout, " A\n");
	}
	else if (score >= 94.00 )
	{
		fprintf(stdout, "A-\n");
	}
	else if (score >= 88.00)
	{
		fprintf(stdout, "B+\n");
	}
	else if (score >= 82.00)
	{
		fprintf(stdout, " B\n");
	}
	else if (score >= 76.00)
	{
		fprintf(stdout, "B-\n");
	}
	else if (score >= 70.00)
	{
		fprintf(stdout, "C+\n");
	}
	else if (score >= 64.00)
	{
		fprintf(stdout, " C\n");
	}
	else if (score >= 58.00)
	{
		fprintf(stdout, " D\n");
	}
	else 
	{
		fprintf(stdout, " F\n");
	}

	//Close out file 
	fclose(fp);
	return(0);
}
