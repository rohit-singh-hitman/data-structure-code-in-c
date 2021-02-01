#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		int c=1;
		if(a[i]>0)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]==a[j])
				{
					c++;
					a[j]=-1;
				}
			}
			if(c>1)
			{
				printf("%d%d\n",a[i],c);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
	return 0;
}
