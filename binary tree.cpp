#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};
struct node *root=NULL;
struct queue
{
	int size;
	int f;
	int r;
	struct node **a;
};
struct stack
{
	int si;
	int top;
	struct node **b;
};
void create2(struct stack *s)
{
	printf("enter the size of stack");
	scanf("%d",&s->si);
	s->b=(struct node **)malloc(s->si*sizeof(struct node *));
	s->top=-1;
}
int isempt(struct stack s)
 {
 	if(s.top==-1)
 	{
 		return 1;
 		
	 }
	 else
	     return 0;
 }
 int isful(struct stack *s)
 {
 	if(s->top==s->si-1)
 	{
 		return 1;
 		
	 }
	 else
	     return 0;
 }

 void push(struct stack *s,struct node *x)
 {
 	if(s->top==s->si-1)
 	 {
 		 printf("stack is full");
	 }
	 else
	 {
	    
	    s->top++;
	    s->b[s->top]=x;
	 }
 }
 struct node * pop(struct stack *s)
 {  struct node *x=NULL;
 	if(s->top==-1)
 	{
 		printf("stack is empty");
    }
    else
    {
    	x=s->b[s->top--];
	}
	return x;
 }
void create(struct queue *q)
{
	printf("enter the size of queeue");
	scanf("%d",&q->size);
	q->f=q->r=-1;
	q->a=(struct node **)malloc(q->size*sizeof(struct node *));
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isfull(struct queue *q)
{
	if(q->r==q->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(struct queue *q,struct node * x)
{
	if((q->r+1)%q->size==q->f)
	{
		printf("queue is full");
	}
	else
	{
		q->r=(q->r+1)%q->size;
		q->a[q->r]=x;
	}
}
struct node * dequeue(struct queue *q)
{
	struct node * x=NULL;
	if(q->f==q->r)
	{
		printf("queue is empty");
	}
	else
	{
	    q->f=(q->f+1)%q->size;
		x=q->a[q->f];	
	}
	return x;
}
void create1()
{
	struct node*p,*t;
	int x;
	struct queue q;
	create(&q);
	
	printf("enter root value");
	scanf("%d",&x);
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isempty(&q))
	{
		p=dequeue(&q);
		printf("enter left value of %d ",p->data);
	    scanf("%d",&x);
	    if(x!=-1)
	    {
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);	
		}
		printf("enter right value of %d ",p->data);
	    scanf("%d",&x);
	    if(x!=-1)
	    {
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);	
		}
		
	}
}
void preorder(struct node *p)
{
	if(p)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void iterpreorder(struct node *p)
{    struct stack s;
     create2(&s);
	while(p!=NULL || !isempt(s))
	{
		if(p!=NULL)
		{  
		    printf("%d ",p->data);
		    push(&s,p);
		    p=p->lchild;
		    
		}
		else
		{
			p=pop(&s);
			p=p->rchild;
		}
    }
}
void inorder(struct node *p)
{
	if(p)
	{
		
		preorder(p->lchild);
		printf("%d ",p->data);
		preorder(p->rchild);
	}
}
void postorder(struct node *p)
{
	if(p)
	{
		
		preorder(p->lchild);
		preorder(p->rchild);
		printf("%d ",p->data);
	}
}
 void levelorder(struct node *p)
{
	struct queue q;
	create(&q);
	printf("%d",p->data);
	enqueue(&q,p);
	while(!isempty(&q))
	{
		p=dequeue(&q);
		if(p->lchild)
		{
			printf("%d",p->lchild->data);
			enqueue(&q,p->lchild);
		}
		if(p->rchild)
		{
			printf("%d",p->rchild->data);
			enqueue(&q,p->rchild);
		}
	}
}
int count(struct node *p)
{   
    int x=0,y=0;
	if(p!=NULL)
	{
		x=count(p->lchild);
		y=count(p->rchild);
		return x+y+1;
	}
	return 0;
	
}
int sum(struct node *p)
{   
    int x=0,y=0;
	if(p!=NULL)
	{
		x=count(p->lchild);
		y=count(p->rchild);
		return x+y+p->data;
	}
	return 0;
	
}
int height(struct node *p)
{   
    int x=0,y=0;
	if(p!=NULL)
	{
		x=count(p->lchild);
		y=count(p->rchild);
		if(x>y)
		{
			return x+1;
		}
		else
		   return y+1;
	}
	return 0;
	
}
int main()
{
	create1();
	iterpreorder(root);
	levelorder(root);
	printf("%d is",count(root));
	printf("%d is",sum(root));
	printf("%d is",height(root));
	
}
