#include <stdio.h>
#include <stdlib.h> /*where exit comes from*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>





int main (int argc, char **argv)
{

	struct stat buf;
	unsigned short int type = 0;
	unsigned short int perm = 0;




	if (argc == 1)
	{
		fprintf(stderr, "Error: must provide file!\n");
		fprintf(stderr, "Usage: %s FILE\n", *(argv+0));
		exit (1);


	}

	if (fopen(*(argv+1), "r") == NULL)
	{
		fprintf(stderr, "Error: Cannot open '%s' for reading!\n", *(argv+1));
		exit(1);
	}

	stat (*(argv+1), &buf);

	/*typedef mode_t int;*/
	/*gives the file permissions of a given file*/

	fprintf(stdout, "%s st_mode is: %o\n", *(argv+1), buf.st_mode);


	/* stores the value in 'type', and shifts the bits 12 to the right*/
	type = buf.st_mode >> 12;
	fprintf(stdout, "type is: %ho\n", type);

	switch(type)
	{
		case 014:
			fprintf(stdout, "socket!\n");
			break;
		case 012:
			fprintf(stdout, "link!\n");
			break;
		case 010:
			fprintf(stdout, "regular file!\n");
			break;
		case 006:
			fprintf(stdout, "block directory!\n");
			break;
		case 004:
			fprintf(stdout, "directory!\n");
			break;
		case 002:
			fprintf(stdout, "character device!\n");
			break;
		case 001:
			fprintf(stdout, "FIFO (or pipe)\n");
			break;
		default:
			fprintf(stdout, "I have no idea\n");
			break;
	}

	perm = buf.st_mode & 0007777;
	fprintf(stdout, "perm is: %ho\n", perm);

	fprintf(stdout, "user: ");
	if ((perm & 00400) == 00400)
	fprintf(stdout, "read ");

	if ((perm & 00200) == 00200)
	fprintf(stdout, "write ");

	if ((perm & 00100) == 00100)
	fprintf(stdout, "execute ");

	fprintf(stdout, "\n");



	fprintf(stdout, "group: ");
	if ((perm & 00040) == 00040);
	fprintf(stdout, "read ");

	if ((perm & 00020) == 00020);
	fprintf(stdout, "write ");

	if ((perm & 00010) == 00010);
	fprintf(stdout, "execute ");

	fprintf(stdout, "\n");


	
	return (0);
}
