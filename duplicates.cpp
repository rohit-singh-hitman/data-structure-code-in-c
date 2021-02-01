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
	int lastdup=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1] && a[i]!=lastdup)
		{
			
			printf("%d\n",lastdup);
			lastdup=a[i];
		}
	}
	return 0;
}
