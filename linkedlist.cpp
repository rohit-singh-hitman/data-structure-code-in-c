#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};
struct node *first=NULL,*second=NULL,*third=NULL;
int count(struct node *p)
{
	int c=0;
	while(p!=NULL)
	{   
	    c++;
		p=p->next;
	}
	return c;
}
int sum(struct node *p)
{
	 int total=0;
	while(p!=NULL)
	{  
	    total+=p->data;
		p=p->next;
	}
	return total;
}
void display(struct node *p)
{
	while(p!=NULL)
	{   
	    printf("%d\n",p->data);
		p=p->next;
	}
}

struct node * search(struct node *p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
int maxi(struct node *p)
{
	int max=-93;
	while(p!=NULL)
	{
		if(max<p->data)
		    max=p->data;
		p=p->next;
    }
    return max;
}
int mini(struct node *p)
{
	int min=32756;
	while(p!=NULL)
	{
		if(min>p->data)
		    min=p->data;
		p=p->next;
    }
    return min;
}
struct node * rsearch(struct node *p,int key)
{
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		if(key==p->data)
		{
			return p;
		}
		else
		{
			return rsearch(p->next,key);
		}
	}
}
struct node * tsearch(struct node *p,int key)
{
	struct node *q=NULL;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
		}
		q=p;
		p=p->next;
	}
}
void create(int A[],int n)
{
 int i;
 struct node *t,*last;
 first=(struct node *)malloc(sizeof(struct node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct node*)malloc(sizeof(struct node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void create2(int b[],int n)
{
 int i;
 struct node *t,*last;
 second=(struct node *)malloc(sizeof(struct node));
 second->data=b[0];
 second->next=NULL;
 last=second;

 for(i=1;i<n;i++)
 {
 t=(struct node*)malloc(sizeof(struct node));
 t->data=b[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void insert(struct node *p,int index,int x)
{
	struct node *t;
	if(index<0 || index>count(p))
	{
		return;
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	if(index==0)
	{
		t->next=first;
		first=t;
    }
	else
	{
		for(int i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
		
	}
	
}
void last(struct node *p,int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=t;
	}
	else
	{
	    while(p->next!=NULL)
	    {
		    p=p->next;
	    }
	    p->next=t;
	    t->next=NULL;
    }
	
}
void firt(struct node *p,int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=t;
	}
	else
	{
	    t->next=first;
	    first=t;
    }
	
}
void insertsort(struct node *p,int x)
{
	struct node *q=NULL;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	if(p==NULL)
	{
		first=t;
	}
	else
	{
	
	    while(p!=NULL && p->data<x)
	    {
		    q=p;
		    p=p->next;
	    }
	    t->next=p;
	    q->next=t;
    }    
}
int delet(struct node *p,int index)
{
	if(index<1 && index>count(p))
	{
		return -1;
	}
	struct node *q=NULL;
	int x=-3,i;
	if(index==1)
	{
		x=first->data;
		first=first->next;
		free(p);
		return x;
	}
	else
	{
		p=first;
		for(i=0;i<index-1 && p!=NULL;i++)
		{
		    q=p;
		    p=p->next;
		    
		}
		x=p->data;
		q->next=p->next;
		free(p);
		return x;
	}
}
void issorted(struct node *p)
{ int c=1;
	while(p!=NULL)
	{
	    if(p->data>p->next->data)
	    {
	    	c=0;
	    	break;
		}
		else
		{
			c=1;
		    p=p->next;
		    
		}
	}
	if(c==1)
	    printf("sorted\n");
	else
	    printf("not sorted\n");
	
}
void removedup(struct node *p)
{
	struct node *q=first->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
			
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}
void reverse(struct node *p)
{
	struct node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void recreverse(struct node *q,struct node *p)
{
	struct node *r=NULL;
	if(p!=NULL)
	{
		recreverse(p,p->next);
		p->next=q;
	}
	else
	    first=q;
}
void concat(struct node *p,struct node *q)
{
	third=p;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	
	
}
void merge(struct node *p,struct node *q)
{
	struct node *last=NULL;
	if(p->data<q->data)
	{
		third=last=p;
		p=p->next;
		last->next=NULL;
	}
	else
	{
		third=last=q;
		q=q->next;
		last->next=NULL;
	}
	while(p!=NULL && q!= NULL)
	{
		if(p->data<q->data)
	    {
		    last->next=p;
		    last=p;
		    p=p->next;
		    last->next=NULL;
	    }
	    else
	    {
		    last->next=q;
		    last=q;
		    q=q->next;
		    last->next=NULL;
	    }
	}
	if(p!=NULL)
	{
		last->next=p;
	}
	if(q!=NULL)
	{
		last->next=q;
	}
}
int main()
{   
    int A[]={10,20,30,40,50};
    int b[]={1,2,3,4,5};
    create(A,5);
    create2(b,5);
    //insertsort(first,1);
    //last(first,15);
    //last(first,25);
    //last(first,25);
    //last(first,25);
    //last(first,25);
    //insertsort(first,10);
    //printf("deleted number is %d\n",delet(first,1));
    //removedup(first);
    //reverse(first);
    //display(first);
    //recreverse(NULL,first);
    display(first);
    printf("\n\n");
    display(second);
    merge(second,first);
    
    printf("\n\n");
    display(third);
    //printf("count is %d\n",count(first));
    //printf("max is %d\n",maxi(first));
    //printf("sum is %d\n",sum(first));
    //printf("min is %d\n",mini(first));
	return 0;
}
