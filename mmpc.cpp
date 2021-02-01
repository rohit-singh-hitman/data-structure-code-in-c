#include<iostream>
using namespace std;
float fun(float a,float b)
{
	float x;
	x=(a*a)+(b*b);
	return x;
}
int main()
{
	float a0=0,b0=1,b,b1,b11,a1;
	float h=0.1;
	int i,j;
	for(i=1;i<=3;i++)
	{
		b1=b0+(h*(fun(a0,b0)));
		a1=a0+h;
		for(j=1;j<=2;j++)
		{
			
			b11=b0+((h/2)*(fun(a0,b0)+fun(a1,b1)));
			b1=b11;
			
		}
		b0=b11;
		a0=a1;
		cout<<"Value of A"<<i<<" is "<<a0<<endl;
		cout<<"Value of B"<<i<<" is "<<b0<<endl;
	}

}
