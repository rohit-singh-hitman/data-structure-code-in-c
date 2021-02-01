#include<stdio.h>
#include<stdlib.h>
struct array
{
	int a[20];
	int s;
	int l;	
};
void Display(struct array arr)
{
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.l;i++)
 {
     printf("%d ",arr.a[i]);
 }
}
struct array* merg(struct array *arr,struct array *brr)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	struct array *arr3;
	arr3=(struct array *)malloc(sizeof(struct array));
	while(i<arr->l && j<brr->l)
	{
		if(arr->a[i]<brr->a[j])
		{
			arr3->a[k]=arr->a[i];
			i++;
			k++;
		}
		else
		{
			arr3->a[k]=brr->a[j];
			j++;
			k++;
		}
	}
	for(;i<arr->l;i++)
	{
        arr3->a[k++]=arr->a[i];
    }
    for(;j<brr->l;j++)
    {
	
        arr3->a[k++]=brr->a[j];
    }
    arr3->l=arr->l+brr->l;
    arr3->s=10;
 return arr3;
}
int main()
{
    struct array ar={{3,8,16,20,25},10,5};
    struct array br={{4,10,12,22,23},10,5};
    struct array *cr;
    cr=merg(&ar,&br);
    Display(*cr);
    return 0;
}
    


