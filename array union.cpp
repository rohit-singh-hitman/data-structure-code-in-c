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
struct array* Un(struct array *arr1,struct array *arr2)
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
			arr3->a[k]=arr1->a[i];
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
return arr3;
    	
}
struct array* in(struct array *arr1,struct array *arr2)
{
    int j=0;
    int i=0;
    int k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->l && j<arr2->l)
    {
    	if(arr1->a[i]<arr2->a[j])
    	{
    	    i++;
    	}
    	else if(arr1->a[i]>arr2->a[j])
    	{
    	    j++;
		}
		else if(arr1->a[i]==arr2->a[j])
		{
			arr3->a[k++]=arr1->a[i++];
    	    j++;
		}
	}
	arr3->l=k;
	arr3->s=10;
	return arr3;
}

struct array* diff(struct array *arr1,struct array *arr2)
{
    int j=0;
    int i=0;
    int k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->l && j<arr2->l)
    {
    	if(arr1->a[i]<arr2->a[j])
    	{
            arr3->a[k++]=arr1->a[i++];
    	}
    	else if(arr1->a[i]>arr2->a[j])
    	{
    	    j++;
		}
		else
		{
			i++;
			j++;
		}
	}
	for(;i<arr1->l;i++)
	{
        arr3->a[k++]=arr1->a[i];
    }
	arr3->l=k;
	arr3->s=10;
	return arr3;
}
	

int main()
{
    struct array arr1={{2,9,21,28,35},10,5};
    struct array arr2={{2,3,9,18,28},10,5};
    struct array *dr;
    dr=diff(&arr1,&arr2);
    Display(*dr);
    return 0;
}
   
