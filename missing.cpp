#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int diff=0;
	diff=a[0]-0;
	for(int i=0;i<n;i++)
	{
		if(a[i]-i!=diff)
		{
			while(diff<a[i]-i)
			{
				printf("%d\n",i+diff);
				diff++;
			}
		}
	}
	return 0;
}
