#include<iostream>
using namespace std;
class rct
{
	private:
		int l;
		int b;
	public:
		rct()
		{
			l=b=1;
		}
		rct(int a,int b);
		int area();
		int perimeter();
		void set();
		void get();
};
rct::rct(int a,int b)
{
	this->l=a;
	this->b=b;
	}
int rct::area()
{
	return l*b;
	
}
int rct::perimeter()
{
	return 2*(l+b);
}
void rct::get()
{
	cout<<l<<b;
}

int main()
{
	rct r(5,6);
	cout<<r.area()<<'\n';
	cout<<r.perimeter()<<'\n';

	r.get();
}
		
		
		
