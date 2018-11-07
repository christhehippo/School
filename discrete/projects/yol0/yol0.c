#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *num2name_if  (unsigned char,  char **, char **);
char *num2name_tern(unsigned char,  char **, char **);
char *num2name_algo(unsigned char,  char **, char **);
unsigned char name2num_if  (char *, char **, char **);
unsigned char name2num_tern(char *, char **, char **);
unsigned char name2num_algo(char *, char **, char **);

int main ()
{
	// make arrays to be used
	char *suits [4]  = {"C","D","H","S"};
	char *values[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"}; 

	char          *name   = (char *)malloc(sizeof(char) * 3);
	char           choice = 0;
	unsigned char  num    = 0;

	while (1)
	{
		fprintf(stdout, "==== yol0 menu ====\n");
		fprintf(stdout, "0. *num2name_if\n");
		fprintf(stdout, "1. *num2name_tern\n");
		fprintf(stdout, "2. *num2name_algo\n");
		fprintf(stdout, "3.  name2num_if\n");
		fprintf(stdout, "4.  name2num_tern\n");
		fprintf(stdout, "5.  name2num_algo\n");
		fprintf(stdout, "6.  exit\n");
		fprintf(stdout, "===================\n");

		fprintf(stdout, "enter choice: ");
		fscanf(stdin, "%hhd", &choice);
		fprintf(stdout, "===================\n");
		
		switch(choice)
		{
			case 0:
			{
				fprintf(stdout, "(*num2name_if) enter num: ");
				fscanf(stdin, "%hhu", &num);
				name = num2name_if(num, suits, values);
				fprintf(stdout, "%s\n", name);
				break;
			}
			case 1:
			{
				fprintf(stdout, "(*num2name_tern) enter num: ");
				fscanf(stdin, "%hhu", &num);
				name = num2name_tern(num, suits, values);
				fprintf(stdout, "%s\n", name);
				break;
			}
			case 2:
			{
				fprintf(stdout, "(*num2name_algo) enter num: ");
				fscanf(stdin, "%hhu", &num);
				name = num2name_algo(num, suits, values);
				fprintf(stdout, "%s\n", name);
				break;
			}
			case 3:
			{	
				fprintf(stdout, "(name2num_if) enter num: ");
				fscanf(stdin, "%s", name);
				num = name2num_if(name, suits, values);
				fprintf(stdout, "%hhu\n", num);
				break;
			}
			case 4:
			{
				fprintf(stdout, "(name2num_tern) enter num: ");
				fscanf(stdin, "%s", name);
				num = name2num_tern(name, suits, values);
				fprintf(stdout, "%hhu\n", num);

				break;
			}
			case 5:
			{
				fprintf(stdout, "(name2num_algo) enter num: ");
				fscanf(stdin, "%s", name);
				num = name2num_algo(name, suits, values);
				fprintf(stdout, "%hhu\n", num);

				break;
			}
			default:
			{
				return (0);
			}
		}
	}
	
	return (0);
}

char *num2name_if  (unsigned char num, char **suits, char **values)
{
	char *name = (char *)malloc(sizeof(char) * 3);
	num = num - 1;
	
	// idk if the point of this is to be bad but I guess I can do that
	// card values then suit
	if (num % 13 == 0)
	{
		strcat(name, values[0]);
	}
	else if (num % 13 == 1)
	{
		strcat(name, values[1]);
	}
	else if (num % 13 == 2)
	{
		strcat(name, values[2]);
	}
	else if (num % 13 == 3)
	{
		strcat(name, values[3]);
	}
	else if (num % 13 == 4)
	{
		strcat(name, values[4]);
	}
	else if (num % 13 == 5)
	{
		strcat(name, values[5]);
	}
	else if (num % 13 == 6)
	{
		strcat(name, values[6]);
	}
	else if (num % 13 == 7)
	{
		strcat(name, values[7]);
	}
	else if (num % 13 == 8)
	{
		strcat(name, values[8]);
	}
	else if (num % 13 == 9)
	{
		strcat(name, values[9]);
	}
	else if (num % 13 == 10)
	{
		strcat(name, values[10]);
	}
	else if (num % 13 == 11)
	{
		strcat(name, values[11]);
	}
	else if (num % 13 == 12)
	{
		strcat(name, values[12]);
	}

	// do suit
	if (num / 13 == 0)
	{
		strcat(name, suits[0]);
	}
	else if (num / 13 == 1)
	{
		strcat(name, suits[1]);
	}
	else if (num / 13 == 2)
	{
		strcat(name, suits[2]);
	}
	else
	{
		strcat(name, suits[3]);
	}

	return(name);
}
char *num2name_tern(unsigned char num, char **suits, char **values)
{
	num = num - 1;
	char *name  = (char *)malloc(sizeof(char) * 3);
	char *suit  = (char *)malloc(sizeof(char) * 1);
	char *value = (char *)malloc(sizeof(char) * 2);
	
	// this sucks but works, itll just go through all of them
	value = ((num % 13) == 0)  ? values[0]  : value;
	value = ((num % 13) == 1)  ? values[1]  : value;
	value = ((num % 13) == 2)  ? values[2]  : value;
	value = ((num % 13) == 3)  ? values[3]  : value;
	value = ((num % 13) == 4)  ? values[4]  : value;
	value = ((num % 13) == 5)  ? values[5]  : value;
	value = ((num % 13) == 6)  ? values[6]  : value;
	value = ((num % 13) == 7)  ? values[7]  : value;
	value = ((num % 13) == 8)  ? values[8]  : value;
	value = ((num % 13) == 9)  ? values[9]  : value;
	value = ((num % 13) == 10) ? values[10] : value;
	value = ((num % 13) == 11) ? values[11] : value;
	value = ((num % 13) == 12) ? values[12] : value;

	suit  = ((num / 13) == 0)  ? suits[0]   : suit;
	suit  = ((num / 13) == 1)  ? suits[1]   : suit;	
	suit  = ((num / 13) == 2)  ? suits[2]   : suit;
	suit  = ((num / 13) == 3)  ? suits[3]   : suit;

	strcat(name, value);
	strcat(name, suit);

	return(name);
}
char *num2name_algo(unsigned char num, char **suits, char **values)
{
	num = num - 1;
	char *name = (char *)malloc(sizeof(char) * 3);

	strcat(name, values[num%13]);
	strcat(name, suits [num/13]);

	return(name);
}
unsigned char name2num_if  (char *name, char **suits, char **values)
{
	unsigned char num = 0;
	if (name[1] == *suits[0])
	{
		num = 13 * 0;
	}
	else if (name[1] == *suits[1])
	{
		num = 13 * 1;
	}
	else if (name[1] == *suits[2])
	{
		num = 13 * 2;
	}
	else if (name[1] == *suits[3])
	{
		num = 13 * 3;
	}
	else if (name[1] == '0')
	{
		// make a case where the name is 3 digits (aka 10 of X)
		if (name[2] == *suits[0])
		{
			num = 13 * 0;
		}
		else if (name[2] == *suits[1])
		{
			num = 13 * 1;
		}
		else if (name[2] == *suits[2])
		{
			num = 13 * 2;
		}
		else if (name[2] == *suits[3])
		{
			num = 13 * 3;
		}
		num = num + 10;
		
		return (num);
	}
	// I KNOW I DONT NEED THE BRACKETS, that said, I generally like using them for
	// continuity among all of my if statements, sorry for not needed lines
	if (name[0] == 'A')
	{
		num = num + 1;
	}
	else if (name[0] == '2')
	{
		num = num + 2;
	}
	else if (name[0] == '3')
	{
		num = num + 3;
	}
	else if (name[0] == '4')
	{
		num = num + 4;
	}
	else if (name[0] == '5')
	{
		num = num + 5;
	}
	else if (name[0] == '6')
	{
		num = num + 6;
	}
	else if (name[0] == '7')
	{
		num = num + 7;
	}
	else if (name[0] == '8')
	{
		num = num + 8;
	}
	else if (name[0] == '9')
	{
		num = num + 9;
	}
	else if (name[0] == 'J')
	{
		num = num + 11;
	}
	else if (name[0] == 'Q')
	{
		num = num + 12;
	}
	else if (name[0] == 'K')
	{
		num = num + 13;
	}
	return(num);
}
unsigned char name2num_tern(char *name, char **suits, char **values)
{
	unsigned char num   = 0;
	char         *value = (char *)malloc(sizeof(char) * 1);
	char         *suit  = (char *)malloc(sizeof(char) * 1);
	// single char array because why not, it looks satisfying 
	*(suit+0)  = (*(name+2) == 0) ? *(name+1) : *(name+2);
	*(value+0) =  *(name+0);
	
	num = (*suit  == 'C') ? num + (13 * 0) : num;
	num = (*suit  == 'D') ? num + (13 * 1) : num;	
	num = (*suit  == 'H') ? num + (13 * 2) : num;	
	num = (*suit  == 'S') ? num + (13 * 3) : num;

	num = (*value == 'A') ? num +  1 	   : num;
	num = (*value == '2') ? num +  2	   : num;
	num = (*value == '3') ? num +  3	   : num;
	num = (*value == '4') ? num +  4	   : num;
	num = (*value == '5') ? num +  5	   : num;
	num = (*value == '6') ? num +  6	   : num;
	num = (*value == '7') ? num +  7	   : num;
	num = (*value == '8') ? num +  8	   : num;
	num = (*value == '9') ? num +  9	   : num;
	num = (*value == '1') ? num +  10  	   : num;
	num = (*value == 'J') ? num +  11  	   : num;
	num = (*value == 'Q') ? num +  12  	   : num;
	num = (*value == 'K') ? num +  13  	   : num;

	return(num);
}

unsigned char name2num_algo(char *name, char **suits, char **values)
{
	unsigned char num = 0;
	char  suit        = 0;
	char  suit2		  = 0;
	char  value       = 0;
	int   i			  = 0;

	value = *(name+0);
	
	while (value != values[i][0])
	{
		i++;
	}
	i++;	
	num   = num + i; // got value of card, this is just added to the num value

	suit  = *(name+1);
	suit2 = *(name+2);
	
	// suits did not need to be a double pointer but I did that for some reason
	// then decided it would be way too much work to change it at this point
	for (i = 0; suit != suits[i][0] && suit2 != suits[i][0]; i++)
	{
		// do nothing, this just does its thing for me
		// this was kind of a pain to do with the suit being in two places
		// -- I tried to do this bitwise logic and I just could not see how its done
	}

	i = i * 13;    // got the card suit, this is just 0-3, multi by 13, added to card val
	num = num + i; // final number

	return(num);
}


