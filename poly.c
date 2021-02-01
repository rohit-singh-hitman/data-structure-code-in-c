#include<stdio.h>
#include<math.h>
int gcd(int,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,r,s,e;
		int a,z;
		printf("enter the sides of polygon, first angle, k \n");
		scanf("%d%d%d",&n,&a,&k);
		s=180*(n-2);
		r=a*n*(n-1)+(k-1)*(2*s-2*a*n);
		e=n*(n-1);
  			z=gcd(r,e);
		//	printf("%d",z);
			printf("%d ",r/z);
			printf("%d",e/z);
	}
     
}  
int gcd(int x,int y)
{
	int i,flag=0,q;
	for(i=1;i<=y;i++)
	{
		//flag=1;
		if(x%i==0 && y%i==0)
		{
			
			q=i;
		}
	
	}
	return q;

	
}
