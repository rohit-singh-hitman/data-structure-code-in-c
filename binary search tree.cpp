#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};
struct node *root=NULL;

void insert(int key)
{   struct node *p=root;
	struct node *r,*t;
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=key;
		root->lchild=root->rchild=NULL;
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
		    return;
	}
	t=(struct node *)malloc(sizeof(struct node));
	t->data=key;
	t->lchild=t->rchild=NULL;
	if(key<r->data)
	{
		r->lchild=t;
	}
	else
	{
		r->rchild=t;
	}
	
}
struct node * rinsert(struct node *p,int key)
{   struct node *t;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
	    t->lchild=t->rchild=NULL;
	    t->data=key;
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

struct node * rsearch(struct node *p,int key)
{
	if(p==NULL)
	   return NULL;
	if(key==p->data)
	    return p;
	else if(key<p->data)
	{
		return rsearch(p->lchild,key);
	}
	else
	{
		return rsearch(p->rchild,key);
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
		else if(key<p->data)
		{
			p=p->lchild;
		}
		else
		{
			p=p->rchild;
		}
	}
	return NULL;
}
void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}
int height(struct node *p)
{   
    int x=0,y=0;
    if(p==NULL)
        return 0;
	if(p!=NULL)
	{
		x=height(p->lchild);
		y=height(p->rchild);
		if(x>y)
		{
			return x+1;
		}
		else
		   return y+1;
	}
	return 0;
	
}
struct node *inpre(struct node *p)
{
	while(p!=NULL && p->rchild!=NULL)
	{
		p=p->rchild;
	}
	return p;
}
struct node *insuc(struct node *p)
{
	while(p!=NULL && p->lchild!=NULL)
	{
		p=p->lchild;
	}
	return p;
}

struct node *delete(struct node *p,int key)
{   
   
   if(p==NULL)
       return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
    	if(p==root)
    	{
    		root=NULL;
    	
		}
		free(p);
		return NULL;
	}
	if(key<p->data)
	{
		p->lchild=delete(p->lchild,key);
	}
	else if(key>p->data)
	{
		p->rchild=delete(p->rchild,key);
	}
	else
	{
		if(height(p->lchild)>height(p->rchild))
		{
			q=inpre(p->lchild);
			p->data=q->data;
			p->lchild=delete(p->lchild,q->data);
		}
		else
		{
			q=insec(p->rchild);
			p->data=q->data;
			p->rchild=delete(p->rchild,q->data);
		}
	}
	return p;
}
int main()
{   insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    inorder(root);
    struct node *temp=search(root,2);
    if(temp!=NULL)
    {
    	printf("%d",temp->data);
	}
	else
	{
		printf("not found");
	}
	return 0;
	
}
