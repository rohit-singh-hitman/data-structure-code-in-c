#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void selection(int a[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
    	for(j=k=i;j<n;j++)
    	{
    		if(a[j]<a[k])
    		{
    			k=j;
			}
			swap(&a[i],&a[k]);
		}
	}
}
void insertion(int a[],int n)
{
	int i,j;
	
	for(i=1;i<n;i++)
	{   int x=a[i];
		for(j=i-1;j>=0 && a[j]>x;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=x;
	}
}
void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			   swap(&a[j+1],&a[j]);
		}
	}
}
int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l;
	int j=h;
	//printf("%d %d  ",i,j);
	while(i<j)
	{
		while(a[i]<=pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[l],&a[j]);
	
	return j;
}
void quick(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		
		quick(a,l,j);
		quick(a,j+1,h);
	}
}
int main()
{
	int a[]={3,7,8,1,9,11,13,4,10},n=10;
	selection(a,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
