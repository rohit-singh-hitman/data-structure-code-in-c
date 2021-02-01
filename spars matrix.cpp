#include<stdio.h>
#include<stdlib.h>
struct elm
{
	int a;
	int b;
	int x;
};
struct spars
{
	int m;
	int n;
	int num;
	struct elm *e;
	};
void crate(struct spars *s)
{
	int i;
	printf("dimns");
	scanf("%d%d",&s->m,&s->n);
	printf("no of non zro numbbe");
	scanf("%d",&s->num);
	s->e=(struct elm *)malloc(s->num*sizeof(struct elm));
	printf(" non zro numbber");
	for(i=0;i<s->num;i++)
	{
	    scanf("%d%d%d",&s->e[i].a,&s->e[i].b,&s->e[i].x);	
	}
}
void display(struct spars s)
{
	int i,j,k=0;
	for(i=1;i<=s.m;i++)
	{
		for(j=1;j<=s.n;j++)
		{
			if(i==s.e[k].a && j==s.e[k].b)
			{
				printf("%d ",s.e[k].x);
				k++;
		    }
		    else
			{
			    printf("0");
		    }
	    }
		printf("\n");
    }
}

int main()
{
	struct spars s1;
	crate(&s1);
 printf("First Matrix\n");
 display(s1);
 return 0;
}
