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
struct array* un(struct array *arr1,struct array *arr2)
{
    struct array *arr3;
    int j=0;
    int i=0;
    int k=0;
    arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->l && j<arr2->l)
    {
    	if(arr1->a[i]<arr2->a[j])
    	{
    	    arr3->a[k]=arr1->a[i];
    	    k++;
    	    i++;
    	}
    	else if(arr1->a[i]>arr2->a[j])
    	{
    		arr3->a[k]=arr2->a[j];
    	    k++;
    	    j++;
		}
		else
		{
			arr3->a[k]=arr2->a[i];
    	    k++;
    	    j++;
    	    i++;
		}
	}
	for(;i<arr1->l;i++)
	{
        arr3->a[k++]=arr1->a[i];
    }
    for(;j<arr2->l;j++)
    {
	
        arr3->a[k++]=arr2->a[j];
    }
	
	arr3->l=k;
	arr3->s=10;
    	
}

int main()
{
    struct array ar={{3,5,10,4,6},10,5};
    struct array br={{12,4,7,2,5},10,5};
    struct array *cr;
    cr=un(&ar,&br);
    Display(*cr);
    return 0;
}
   
