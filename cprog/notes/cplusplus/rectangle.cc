#include <cstdio>
#include <cstdlib>

class rectangle
{
	public:
		rectangle::rectangle()
		{
			length=0;
			width =0;
		};
		rectangle::rectangle(int,int)
		{
			this->length=length;
			this->width=width;

		};
//	   ~rectangle();
		int rectangle::area()
		{
			return(length*width);
		};
		int parameter()
		{
			return((length*2)+(width*2));
		};
		int getLength()
		{
			
		};
		int rectangle::getWidth()
		{
			
		};
		void rectangle::setLength(int)
		{
			this->length=length;	
		};
		void rectangle::setWidth(int);
		{
			this->width=width;
		};


	private:
		int length;
		int width;

};





int main();
{

	return(0);
}
