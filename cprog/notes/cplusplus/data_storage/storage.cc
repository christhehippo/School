#include "storage.h"

storage :: storage()
{
	int index = 0;
	for (index = 0; index < 256; index++)
	{
		data[index] = 0;
	}
	address = 0;
}

uc storage :: get()
{
	return (data[address]);
}

void storage :: put (uc byte)
{
	data[address] = byte;
}

void storage :: set (uc location)
{
	address = location;
}

uc storage :: ret()
{
	return (address);
}



