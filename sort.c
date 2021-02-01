#include<stdio.h>
#include<stdlib.h>

struct array 
{
	int a[10];
	int size;
	int length;
};
void display(struct array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d",arr.a[i]);
	}
}
void swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }
int sort(struct array *arr)
{
	for(i=0;i<arr->length;i++)
	{
		for(j=i+1;j<arr->length,j++)
		{
			if(arr->a[i]>arr->a[j])
			{
				swap(&arr->a[j],&arr[i]);
			}
		}
	}
	
}
int main()
{
	struct array arr1={{10,8,6,4,2},10,5};
	sort(&arr1);
	display(arr1);
	return 0;
