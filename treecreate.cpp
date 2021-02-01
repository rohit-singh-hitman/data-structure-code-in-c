#include<stdio.h>
#include<stdlib.h>
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
	struct node * *Q;
};
void create(struct queue *q)
{
	printf("enter size of queue");
	scanf("%d",&q->size);
	q->Q=(struct node **)malloc(q->size*sizeof(struct node *));
	q->f=q->r=-1;
}
void enqueue(struct queue *q,struct node * x)
{
	if(q->r==q->size-1)
	{
		printf("full queue");
	}
	else
	{
		q->r++;
		q->Q[q->r]=x;
	}
}
struct node * dequeue(struct queue *q)
{
	struct node * x=NULL;
	if(q->f==q->r)
	{
		printf("empty queue");
	}
	else
	{
		q->f++;
		x=q->Q[q->f];
		
	}
	return x;
}
int isempty(struct queue q)
{
	if(q.f==q.r)
		return 1;
	else
		return 0;
}
int isfull(struct queue q)
{
	if(q.r==q.size-1)
		return 1;
	else
		return 0;
}
void treecreate()
{
	struct node *p,*t;
	int x;
	struct queue q;
	create(&q);
	printf("enter the root value");
	scanf("%d",&x);
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isempty(q))
	{
		p=dequeue(&q);
		printf("enter left child of %d is",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
	        t->data=x;
	        t->lchild=t->rchild=NULL;
	        p->lchild=t;
	        enqueue(&q,t);
		}
		printf("enter right child of %d is",p->data);
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
void preorder(struct node * p)
{if(p)
{
	printf("->\t%d",p->data);
	preorder(p->lchild);
	preorder(p->rchild);
}
}
void inorder(struct node *p)
{if(p)
{

	inorder(p->lchild);
	printf("->\t%d",p->data);
	inorder(p->rchild);
}
}
void postorder(struct node *p)
{if(p)
{
	postorder(p->lchild);
	postorder(p->rchild);
	printf("->\t%d",p->data);
}
}
void levelorder(struct node*p)
{
	struct queue q;
	create(&q);
	printf("%d->\t",p->data);
	enqueue(&q,p);
	while(!isempty(q))
	{
		p=dequeue(&q);
		if(p->lchild)
		{
			printf("%d->\t",p->lchild->data);
	        enqueue(&q,p->lchild);
		}
		if(p->rchild)
		{
			printf("%d->\t",p->rchild->data);
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
		x=sum(p->lchild);
		y=sum(p->rchild);
		return x+y+p->data;
	}
	return 0;
}
int height(struct node *p)
{
	int x=0,y=0;
	if(p!=NULL)
	{
		x=height(p->lchild);
		y=height(p->rchild);
		if(x>y)
		{
			return x+1;
		}
		else
		{
		    return y+1;
		}
	}
	return 0;
}
int countleafnode(struct node *p)
{
	int x=0,y=0;
	if(p!=NULL)
	{
		x=countleafnode(p->lchild);
		y=countleafnode(p->rchild);
		if(p->lchild==NULL && p->rchild==NULL)
		    return x+y+1;
		else
		    return x+y;
	}
	return 0;
}
int count1degree(struct node *p)
{
	int x=0,y=0;
	if(p!=NULL)
	{
		x=count1degree(p->lchild);
		y=count1degree(p->rchild);
		if((p->lchild==NULL && p->rchild!=NULL) || (p->lchild!=NULL && p->rchild==NULL))
		    return x+y+1;
		else
		    return x+y;
	}
	return 0;
}
int countnonleafnode(struct node *p)
{
	int x=0,y=0;
	if(p!=NULL)
	{
		x=countnonleafnode(p->lchild);
		y=countnonleafnode(p->rchild);
		if(p->lchild && p->rchild)
		    return x+y+1;
		else
		    return x+y;
	}
	return 0;
}
int main()
{
	
	treecreate();
	printf("\npreorder is");
	preorder(root);
	printf("\ninorder is");
	inorder(root);
	printf("\npostorder is");
	postorder(root);
	printf("\nlevelorder is");
	levelorder(root);
	printf("count of node is %d  ",count(root));
	printf("\n");
	printf("count of sum of allnode is %d  ",sum(root));
	printf("\n");
	printf("count of leaf node is %d  ",countleafnode(root));
	printf("\n");
	printf("count of nonleaf node is %d  ",countnonleafnode(root));
	printf("\n");
	printf("height is %d  ",height(root));
	printf("\n");
	printf("count of 1 degree  node is %d  ",count1degree(root));
	
	
	
	
	
	
}
