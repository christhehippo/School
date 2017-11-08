#include "disk.h"

disk :: disk() : disk(0x0000) { }
disk :: disk(usi pattern)
{
	int index = 0;
	for (index = 0; index < 128; index++)
	{
		// pattern == 0xAA 0x5
		set(2*index);
		put(pattern >> 8);
		set(2*index+1);
		put(pattern & 0x00FF);
	}
	location = 0;
}

usi disk :: load()
{
	uc byte1, byte2;
	usi value;
	set(location);
	byte1 = get();
	set(location+1);
	byte2 = get();

	value = byte1 << 8;
	value = value | byte2;
	
	location = location + 2;
	
	return(value);
}

void disk :: save(usi data)
{
	set(location);
	put(data >> 8);
	set(location+1);
	put(data & 0x00FF);
	location = location + 2;
	
}

void disk :: seek(uc place)
{
	location = place;
	set(location);
}
