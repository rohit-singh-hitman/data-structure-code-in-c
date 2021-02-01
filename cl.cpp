#include<iostream>
using namespace std;
class base
{
	public:
	fun()
	{
		cout<<"1";
	}
	fun(int i)
	{
		cout<<"2";
	}
	fun(int i,int j)
	{
		cout<<"3";
	}
};
class der:public base
{
	public:
	fun(int i)
	{
		cout<<"4";
	}
	
};
int main()
{
	der d1;
	d1.fun(2);
}

