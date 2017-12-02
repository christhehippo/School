#include "parent.h"
#include <stdio.h>

parent :: parent()
{
	sVal = 0;
}

float parent :: retSVal()
{
	fprintf(stdout, "Enter source value: ");
	fscanf(stdin, "%f", &sVal);
	return(sVal);
}

float parent :: meter(float val, char check)
{
	if (check == 0)
	{
		return(val);
	}				 // function exists to be consista(e?)nt
	else             // but it is not needed technically
	{
		return(val);
	}
}

float parent :: mm(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.001;
		return(val);
	}
	else
	{
		val = val / 0.001;
	}
	
}

float parent :: cm(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.01;
		return(val);
	}
	else
	{
		val = val / 0.01;
	}
	
}

float parent :: dm(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.1;
		return(val);
	}
	else
	{
		val = val / 0.1;
	}
	
}

float parent :: Dm(float val, char check)
{
	if (check == 0)
	{
		val = val * 10;
		return(val);
	}
	else
	{
		val = val / 10;
	}
	
}
float parent :: hm(float val, char check)
{
	if (check == 0)
	{
		val = val * 100;
		return(val);
	}
	else
	{
		val = val / 100;
	}
	
}
float parent :: km(float val, char check)
{
	if (check == 0)
	{
		val = val * 1000;
		return(val);
	}
	else
	{
		val = val / 1000;
	}
	
}
float parent :: Mm(float val, char check)
{
	if (check == 0)
	{
		val = val * 1000000;
		return(val);
	}
	else
	{
		val = val / 1000000;
	}
	
}
float parent :: inch(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.0254;
		return(val);
	}
	else
	{
		val = val / 0.0254;
	}
	
}
float parent :: lea(float val, char check)
{
	if (check == 0)
	{
		val = val * 73.152;
		return(val);
	}
	else
	{
		val = val / 73.152;
	}
	
}
float parent :: foot(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.3048;
		return(val);
	}
	else
	{
		val = val / 0.3048;
	}
	
}
float parent :: yard(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.9144;
		return(val);
	}
	else
	{
		val = val / 0.9144;
	}
	
}
float parent :: mile(float val, char check)
{
	if (check == 0)
	{
		val = val * 1609.344;
		return(val);
	}
	else
	{
		val = val / 1609.344;
	}
	
}
float parent :: greekStadion(float val, char check)
{
	if (check == 0)
	{
		val = val * 184.9;
		return(val);
	}
	else
	{
		val = val / 184.9;
	}
	
}
float parent :: romanFoot(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.2957;
		return(val);
	}
	else
	{
		val = val / 0.2957;
	}
	
}
float parent :: romanMile(float val, char check)
{
	if (check == 0)
	{
		val = val * 1478.5848;
		return(val);
	}
	else
	{
		val = val / 1478.5848;
	}
	
}
float parent :: romanLeague(float val, char check)
{
	if (check == 0)
	{
		val = val * 2217.75;
		return(val);
	}
	else
	{
		val = val / 0.001;
	}
	
}
float parent :: league(float val, char check)
{
	if (check == 0)
	{
		val = val * 4000;
		return(val);
	}
	else
	{
		val = val / 4000;
	}
	
}
float parent :: cubit(float val, char check)
{
	if (check == 0)
	{
		val = val * 0.4572;
		return(val);
	}
	else
	{
		val = val / 0.4572;
	}
	
}

