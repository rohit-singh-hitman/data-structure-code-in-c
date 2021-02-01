#include<stdio.h>
#include<stdlib.h>

struct poly
{
	int coe;
	int exp;
	struct poly *next;
};
struct poly *first=NULL;
struct poly *second=NULL;
struct poly *third=NULL;
int pow(int m,int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return pow(m,n-1)*m;
	}
}
void create()
{
	struct poly *t,*last=NULL;
	int num,i=0;
	printf("enter number of terms");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		t=(struct poly *)malloc(sizeof(struct poly));
		printf("enter coeff");
		scanf("%d",&t->coe);
		printf("enter exponent");
		scanf("%d",&t->exp);
		t->next=NULL;
		if(first==NULL)
		{
			first=last=t;
		}
		else
		{
			last->next=t;
			last=t;
		}
	}
}
void create2()
{
	struct poly *t,*last=NULL;
	int num,i=0;
	printf("enter number of terms");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		t=(struct poly *)malloc(sizeof(struct poly));
		printf("enter coeff");
		scanf("%d",&t->coe);
		printf("enter exponent");
		scanf("%d",&t->exp);
		t->next=NULL;
		if(second==NULL)
		{
			second=last=t;
		}
		else
		{
			last->next=t;
			last=t;
		}
	}
}
void display(struct poly *p)
{
	while(p!=NULL)
	{
		printf("%d%d",p->coe,p->exp);
		p=p->next;
		printf("\n");
	}
}
void represent(struct poly *p)
{
	float res=0;
	while(p!=NULL)
	{
	    res=p->coe*pow(1,p->exp)+res;
		p=p->next;	
	}
	printf("%f\n",res);
}
void polyadd(struct poly *poly1, struct poly *poly2, struct poly *poly3) 
{ 
while(poly1->next && poly2->next) 
    { 
        if(poly1->exp > poly2->exp) 
        { 
            poly3->exp = poly1->exp; 
            poly3->coe = poly1->coe; 
            poly1 = poly1->next; 
        } 
    
        else if(poly1->exp < poly2->exp) 
        { 
            poly3->exp = poly2->exp; 
            poly3->coe = poly2->coe; 
            poly2 = poly2->next; 
        } 
        else
        { 
            poly3->exp = poly1->exp; 
            poly3->coe = poly1->coe+poly2->coe; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        poly3->next = (struct poly *)malloc(sizeof(struct poly)); 
        poly3 = poly3->next; 
        poly3->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly3->exp = poly1->exp; 
            poly3->coe = poly1->coe; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly3->exp = poly2->exp; 
            poly3->coe = poly2->coe; 
            poly2 = poly2->next; 
        } 
        poly3->next = (struct poly *)malloc(sizeof(struct poly)); 
        poly3 = poly3->next; 
        poly3->next = NULL; 
    } 
} 
void show(struct poly *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coe, node->exp); 
    node = node->next; 
    if(node->next != NULL) 
        printf(" + "); 
    } 
}
int main()
{
	struct poly *q;
	q=(struct poly *)malloc(sizeof(struct poly));
	create();
	display(first);
	create2();
	display(second);
	represent(first);
	represent(second);
	polyadd(first,second,q);
	show(q);
    return 0;
}
