#ifndef _TAPE_H
#define _TAPE_H

#include "storage.h"


typedef unsigned short int usi;

class tape : public storage
{
	public:
		tape();
		tape(uc);
		tape(uc, uc);		 // format tape and set location
		void forward();		 // advance 1 byte
		void forward(uc);	 // advance X bytes
		void fast_forward(); // forward until the end
		void back();		 // go back 1 byte
		void back(uc);		 // go back X bytes
		void rewind();		 // go back to start
		uc play();			 // retrieve byte at position
		void record(uc);	 // store byte at position

	private:
		uc position;	
};



#endif
