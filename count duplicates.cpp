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
	int lastdup=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			j=i;
			while(a[j]==a[i])
			{
				j++;
			}
			printf("%d is times%d\n",a[i],j-i);
			i=j-1;
			
		}
	}
	return 0;
}
