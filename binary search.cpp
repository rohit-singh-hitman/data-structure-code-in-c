#include<stdio.h>
struct Array
{
 int A[10];
 int size;
 int length;
};
 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
void swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }
int LinearSearch(struct Array *arr,int key)
{
 int i;
 for(i=0;i<arr->length;i++)
 {
 if(key==arr->A[i])
 {
 swap(&arr->A[i],&arr->A[0]);
 return i;
 }
 }
 return -1;
}
int bin(struct array *arr,int a,int b,int k)
{
	if(a<=b)
	{
		int m=(a+b)/2;
		printf("%d",m);
		if(k==arr->A[m])
		{
			return m;
		}
		else if(k<arr->A[m])
		{
			return bin(&arr,a,m-1,k);
		}
		else
		{
			return bin(&arr,m-1,b,k);
		}
		
	}
	return -1;
}
int main()
{
 struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
 printf("%d",LinearSearch(&arr1,14));
 Display(arr1);

 return 0;
}
