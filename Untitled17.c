#include<stdio.h>
#include<stdlib.h>

struct array 
{
	int a[10];
	int size;
	int length;
};
int get(struct array arr,int k)
{
	if(k>=0 && k<length)
	{
		return arr.a[k];e
	}
	return -1;
}
int set(struct array *arr,int k,int x)
{
	if(k>=0 && k<length)
	{
		return arr->a[k]=x;
		
	}
	return -1;
}
int max(struct array arr)
{
	int max=arr.a[0];
	for(int i=0;i<arr.length;i++)
	{
		if(max<arr.a[i])
		{
			max=a[i]
		}
	}
	return max;
}
int min(struct array arr)
{
	int min=arr.a[0];
	for(int i=0;i<arr.length;i++)
	{
		if(min>arr.a[i])
		{
			min=a[i]
		}
	}
	return min;
}
int sum(struct array arr)
{
	total=0;
	for(int i=0;i<arr.length;i++)
	{
		total=total+a[i];
	}
	return total;
}

void display(struct array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d",arr.a[i]);
	}
}
void ins(struct array *arr,int ind,int x)
{
	int i;
	if(ind>=0 && ind<=arr->length)
	for(i=arr->length;i>ind;i--)
	{
		arr->a[i]=arr->a[i-1];
	}
	arr->a[ind]=x;
	arr->length++;
}
void rmv(struct array *arr,int ind)
{
	int i,x;
	x=arr->a[ind];
	if(ind>=0 && ind<=arr->length)
	for(i=ind;i<arr->length-1;i++)
	{
		arr->a[i]=arr->a[i+1];
	}
	
	arr->length--;
}
void app(struct array *arr,int x)	
{
	if(arr->length<arr->size)
	{
		arr->a[arr->length++]=x;
	}
}	
		
int main()
{
	struct array arr={{2,4,6,8,10},10,5};
	app(&arr,10);
	ins(&arr,4,15);
	display(arr);
	rmv(&arr,0);
	return 0;
				
}
