#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *lchild;
	int data;
	struct node *rchild;
};
struct node *root=NULL;

struct node * rinsert(struct node *p,int key)
{ 
struct node *t;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data)
	{
		p->lchild=rinsert(p->lchild,key);
	}
	else if(key>p->data)
	{
		p->rchild=rinsert(p->rchild,key);
	}
	return p;
}

void insert(int key)
{
	struct node *p=root;
	struct node *r=NULL,*t;
	if(root==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		root=t;
		return;
	}
	while(p!=NULL)
	{
		r=p;
		if(key<p->data)
		{
		    p=p->lchild;
		}
		else if(key>p->data)
		{
	        p=p->rchild;
	    }
	    else
	    {
	        return;
	    }
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->data=key;
	t->lchild=t->rchild=NULL;
    if(key>r->data)
    {
	    r->rchild=t;
	 }
	else
	{
	   r->lchild=t;  
    }
}
void inorder(struct node *p)
{if(p!=NULL)
    {
	    inorder(p->lchild);
	    printf("->\t%d",p->data);
	    inorder(p->rchild);
    }
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
struct node * inpre(struct node *p)
{
	while(p!=NULL && p->rchild!=NULL)
	{
		p=p->rchild;
	}
	return p;
}
struct node * insucc(struct node *p)
{
	while(p!=NULL && p->lchild!=NULL)
	{
		p=p->lchild;
	}
	return p;
}
struct node *delet(struct node *p,int key)
{   struct node *q;
	if(p==NULL)
	{
		return NULL;
	}
	if(p->lchild==NULL && p->rchild==NULL)
	{
		if(root==NULL)
		{
			root=NULL;
		}
		free(p);
		return NULL;
	}
	if(p->data>key)
	{
		p->lchild=delet(p->lchild,key);
	}
	else if(p->data<key)
	{
		p->rchild=delet(p->rchild,key);
	}
	else
	{
		if(height(p->lchild)>height(p->rchild))
		{
			q=inpre(p->lchild);
			p->data=q->data;
			p->lchild=delet(p->lchild,q->data);
		}
		else
		{
			q=insucc(p->rchild);
			p->data=q->data;
			p->rchild=delet(p->rchild,q->data);
		}
	}
	return p;
}

int main()
{
	
	
	root=rinsert(root,10);
	rinsert(root,1);
	rinsert(root,8);
	rinsert(root,15);
	rinsert(root,7);
	insert(24);
	insert(5);
	insert(27);
	inorder(root);
	printf("\n");
	delet(root,15);
	inorder(root);
	delet(root,10);
	inorder(root);
	return 0;
	
	
	
}
