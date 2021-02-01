#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[5];
	int B[5]={1,2,3,4,5};
	int C[10]={1,2,3};
	int D[5]={0};
	int E[]={1,2,3,4,5,6};
	int *p;
	p=(int*)malloc(5*sizeof(int));
	p[0]=10;
	p[1]=11;
	p[2]=12;
	p[3]=13;
	p[4]=14;
	printf("%d\n",A[1]);
	for(int i=0;i<5;i++)
	{
			printf("%d\n",*(E+i));
		
	}
	for(int i=0;i<5;i++)
	{
			printf("%d",p[i]);
		
	}
	return 0;
	
}
