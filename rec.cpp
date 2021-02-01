#include<stdio.h>

void fun(int n)
{
  if(n>0)	
  {
  	printf("%d",n);
  	fun(n-1);
  }
}
void fn(int n)
{
	if(n>0)
	{
		fn(n-1);
		printf("%d",n);
	}
}
int fp(int n)
{
	
	if(n>0)
	{
		
		return fp(n-1)*n;
	}
	return 1;
	
}
int fibb(int n)
{

	if(n>1)
	{
		
		return fibb(n-1)+fibb(n-2);
	}
	return 1;
}
int pow(int n,int m)
{
	if(m>0)
	{
		return pow(n,m-1)*n;
	}
	return 1;
}
int pow1(int m,int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n%2==0)
	{
		return pow1(m*m,n/2);
	}
	else
	{
		return m*pow1(m*m,(n-1)/2);
	}
}
int sum(int n)
{
	if(n>0)
	{
		return sum(n-1)+n;
	}
	return 0;
}
void sum1(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
	{
		s=s+i;
	}
	printf("%d",s);
}
double taylor(int x,int n)
{
	static double p=1,f=1;
	if(n==0)
	{
		return 1;
	}
	else
	{
	    double r;
	    r=taylor(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}
int main()
{
	int b=5;
	sum1(6);
	printf("%d\n",fp(5));
	printf("%d\n",pow1(2,11));
	printf("%d\n\n",pow(2,10));
	printf("%d",taylor(4,10));
	return 0;
}
