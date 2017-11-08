#ifndef _DISK_H
#define _DISK_H

#include "storage.h"

typedef unsigned short int usi;

class disk : public storage
{
	public:
		disk();   
		disk(usi); 
		usi load(); 	// load 2-byte word from current location
		void save(usi); // save 2 byte word to current location
		void seek(uc);	// set our location

	private:
		uc location;

};

#endif
