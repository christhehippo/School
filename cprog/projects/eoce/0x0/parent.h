#ifndef _PARENT_H
#define _PARENT_H

class parent
{
	public:
		parent();

		//set value for starting value
		float getStartingVal();
		
		//convert tools
		float bitsToBytes(float val);
		float bytesToBits(float val);
		//functions that both multi or div based on i to create that unit
		float deka(float val, char i);
		float dibi(float val, char i);
		float hecto(float val, char i);
		float hibi(float val, char i);
		float kilo(float val, char i);
		float kibi(float val, char i);
		float mega(float val, char i);
		float mibi(float val, char i);
		float giga(float val, char i);
		float gibi(float val, char i);
		float tera(float val, char i);
		float tibi(float val, char i);
	private:
		float startingVal;
		



};

#endif
