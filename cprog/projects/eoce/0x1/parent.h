#ifndef _PARENT_H
#define _PARENT_H

class parent
{
	public:
		parent();
		float retSVal(); // Return starting val

		// functions to convert to or from meters
		float meter(float val, char check);
		float mm(float val, char check);
		float cm(float val, char check);
		float dm(float val, char check);
		float Dm(float val, char check);
		float hm(float val, char check);
		float km(float val, char check);
		float Mm(float val, char check);
		float inch(float val, char check);
		float lea(float val, char check);
		float foot(float val, char check);
		float yard(float val, char check);
		float mile(float val, char check);
		float greekStadion(float val, char check);
		float romanFoot(float val, char check);
		float romanMile(float val, char check);
		float romanLeague(float val, char check);
		float league(float val, char check);
		float cubit(float val, char check);


	private:
		float sVal;





};

#endif
