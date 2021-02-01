#include<stdio.h>
#include<stdlib.h>
struct matrix
{
	int *a;
	int n;
};
void uset(struct matrix *m,int i,int j,int x)
{
	if(i<=j)
	{
		m->a[j*j-1/2+i-1]=x;
	}
}
void dset(struct matrix *m,int i,int j,int x)
{
	if(i==j)
	{
		m->a[i]=x;
	}
}
void lset(struct matrix *m,int i,int j,int x)
{
	if(i>=j)
	{
		m->a[i*i-1/2+j-1]=x;
	}
}
int uget(struct matrix m,int i,int j)
{
	if(i<=j)
	{
		return m.a[j*j-1/2+i-1];
	}
	else
	{
		return 0;
	}
}
int lget(struct matrix m,int i,int j)
{
	if(i>=j)
	{
		return m.a[i*i-1/2+j-1];
	}
	else
	{
		return 0;
	}
}
int dget(struct matrix m,int i,int j)
{
	if(i==j)
	{
		return m.a[i];
	}
	else
	{
		return 0;
	}
}
void udisplay(struct matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i<=j)
			    printf("%d",m.a[j*j-1/2+i-1]);
			else
			    printf("0");
		}
	    printf("\n");	
	}
}
void ldisplay(struct matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i>=j)
			    printf("%d",m.a[i*i-1/2+j-1]);
			else
			    printf("0");
		}
	    printf("\n");	
	}
}
void display(struct matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i==j)
			    printf("%d",m.a[i]);
			else
			    printf("0");
		}
	    printf("\n");	
	}
}
int main()
{
	struct matrix m;
	int i,j,x;
	printf("entr dim");
	scanf("%d",&m.n);
	m.a=(int *)malloc(m.n*m.n+1/2*sizeof(int));
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			scanf("%d",&x);
			lset(&m,i,j,x);
			dset(&m,i,j,x);
			uset(&m,i,j,x);
		}
	}
	printf("lowr triangular matrix is\n");
	ldisplay(m);
	printf(" diagonal matrix is\n\n");
	display(m);
	printf("uppr triangular matrix is\n\n");
	udisplay(m);
	return 0;
}
