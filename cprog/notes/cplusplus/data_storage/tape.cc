#include "tape.h"

tape :: tape() : tape(0, 0) { }
tape :: tape(uc byte) : tape(byte, 0) { }
tape :: tape(uc byte, uc position) : storage()
{
	int index = 0;
	for (index = ret(); index < 256; index++)
	{
		this -> position = index;
		set(index);
		put(byte);
	}
	this -> position = position;
	set(position);
}

void tape :: forward()
{
	if (position < 255)
	{
		position = position + 1;
		set(position);
	}
}

void tape : forward(uc amount)
{
	int index = 0;
	for (index = 0; index < amount; index++)
	{
		forward();
	}
}

void tape :: fast_forward()
{
	while (position < 255)
	{
		forward();
	}
}

void tape :: back()
{
	if  (position > 0)
	{
		position = position - 1;
		set(position);
	}
}

void tape :: back(uc amount)
{
	int index = 0;
	for (index = 0; index < amount; index++)
	{
		back()
	}	
}

void tape :: rewind()
{
	while (position > 0)
	{
		back();
	}
}

uc tape :: play()
{
	uc result = get();
	forward();
	return (get());
}

void tape :: record(uc byte)
{
	put(byte);
	forward();
}





