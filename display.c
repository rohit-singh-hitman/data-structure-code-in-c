#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct array
{
	int *a;
	int size;
	int length;
};
void display(struct array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d",arr.a[i]);
		printf("%d",arr.length);
	}
}
int main()
{
	struct array arr;
	printf("siz of array");
	scanf("%d",&arr.size);
	arr.a=(int *)malloc(arr.size*sizeof(int));
	arr.length=0;
	int n,i;
	printf("number of nos");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr.a[i]);
	}
	arr.length=n;
	display(arr);
	return 0;
}

