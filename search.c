#include <stdio.h>
#include <stdlib.h>

/* run this program using te console pauser or add your own getch, system("pause") or input loop */

struct array
{
	int a[10];
	int l;
	int s;
	
};
void dis(struct array arr)
{
	for(int i=0;i<arr.l;i++)
	{
		printf("%d",arr.a[i]);
	}
}
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
int lin(struct array *arr,int k)
{
	int i;
	for(i=0;i<arr->l;i++)
	{
		if(k==arr->a[i])
		{
			return i;
		}
	}
	return -1;
}
int lin1(struct array *arr,int k)
{
	int i;
	for(i=0;i<arr->l;i++)
	{
		if(k==arr->a[i])
		{
			swap(&arr->a[i],&arr->a[0]);
			return i;
		}
	}
	return -1;
}
int main()
{
	struct array arr={{2,4,6,8,10},5,10};
	printf("%d",Lin(&arr,4));
 Dis(arr);
 return 0;

}
