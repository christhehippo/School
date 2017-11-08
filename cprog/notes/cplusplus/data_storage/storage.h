#ifndef _STORAGE_H
#define _STORAGE_H

typedef unsigned char uc;

class storage 
{
	public:
		storage();	
	protected:


		uc get();		// obtain byte of data at current address
		void put(uc);	// store byte of data at curent address
		void set(uc);	// manipulate value stored in address
		uc ret();		// retrieve the current address

	private:
		uc data[256];
		uc address;


};

#endif
