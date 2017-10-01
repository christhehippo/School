//gdfun 9/20 notes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <gd.h>

#define  BLACK     0
#define  BLUE      1
#define  GREEN     2
#define  RED       3
#define  FOOF	   4
#define  WHITE     5

int main(int argc, char **argv)
{

	char        		*outfile = NULL;
	FILE        		*out	 = NULL;
	gdImagePtr   		img		 = NULL;
	unsigned int 		color[5];
	unsigned short int  wide     = 0;
	unsigned short int  high     = 0;
	
	if (argc					== 2)
	{
		outfile					 = *(argv+1);
		fprintf(stdout, "Using '%s' as output filename\n", outfile);
	}
	else
	{
		
		outfile  = (char *) malloc (sizeof (char) * 64);
		sprintf(outfile, "/home/%s/public_html/gdfun.png", getenv("USER"));
	}
	
	wide		 = 600;
	high		 = 800;

	img			 = gdImageCreate (wide, high);
	if (img 	== NULL)
	{
		fprintf(stderr, "ERROR: Unable to create iamge!\n");
		exit (1);
	}

	color[BLACK] = gdImageColorAllocate (img, 0x00, 0x00, 0x00);
	color[BLUE]	 = gdImageColorAllocate (img, 0x00, 0x00, 0xFF);
	color[GREEN] = gdImageColorAllocate (img, 0x00, 0xFF, 0x00);
	color[RED]   = gdImageColorAllocate (img, 0xFF, 0x00, 0x00);
	color[FOOF]	 = gdImageColorAllocate (img, 0xFF, 0x00, 0xFF);
	color[WHITE] = gdImageColorAllocate (img, 0xFF, 0xFF, 0xFF);
	
	gdImageFilledRectangle (img, 0, 0, wide-1, high-1, color[BLACK]);

	gdImageRectangle (img, 20, 20, 500, 100, color[WHITE]);
	gdImageFilledRectangle (img, (wide/4), (high-(high/4)), 4000, 350, color[FOOF]);

	gdImageFilledArc (img, (wide/2), 300, 150, 80, 0, 360, color[BLACK], gdArc);
	gdImageFilledArc (img, (wide/5), 500, 180, 180, 45, 315, color[BLUE], gdArc);


	out			 = fopen (outfile, "w");
	if (out		== NULL)
	{
		fprintf(stderr, "Error openin '%s' for writing\n", outfile);
		exit(2);
	}

	gdImagePngEx (img, out, -1);

	fclose (out);
	gdImageDestroy (img);

	chmod (outfile, 0644);
	
	return (0);
}
