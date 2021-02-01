#include<stdio.h>
int pow(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	if(b>0)
	return pow(a,b-1)*a;
}
int fact(int m)
{
	if(m==0)
	{
		return 1;
	}
	if(m>0)
	return fact(m-1)*m;
}
double e(int x,int n)
{
	if(n==0)
	{
		return 1;
	}
	return e(x,n-1)+pow(x,n)/fact(n);
}
int main()
{
	printf("%lf",e(4,15));
	return 0;
}
