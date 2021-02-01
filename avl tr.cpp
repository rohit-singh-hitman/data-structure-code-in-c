#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *lchild;
	int data;
	int height;
	struct node *rchild;
};
struct node *root=NULL;
int NodeHeight(struct node *p)
{
	int hl,hr;
	hl=p && p->lchild?p->lchild->height:0;
	hr=p && p->rchild?p->rchild->height:0;
	return hl>hr?hl+1:hr+1;
}
int balancefactor(struct node *p)
{
	int hl,hr;
	hl=p && p->lchild?p->lchild->height:0;
	hr=p && p->rchild?p->rchild->height:0;
	return hl-hr;
}
struct node * LLrotation(struct node *p)
{
    struct node *pl=p->lchild;	
    struct node *plr=pl->rchild;
    
    pl->rchild=p;
    p->lchild=plr;
    
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    
    if(root==p)
    {
    	root=pl;
	}
	return pl;
}
struct node * RRrotation(struct node *p)
{
    struct node *pr=p->rchild;	
    struct node *prl=pr->lchild;
    
    pr->lchild=p;
    p->rchild=prl;
    
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    
    if(root==p)
    {
    	root=pr;
	}
	return pr;
}
struct node * LRrotation(struct node *p)
{
    struct node *pl=p->lchild;	
    struct node *plr=pl->rchild;
    
    p->lchild=plr->rchild;
    pl->rchild=plr->lchild;
    
    plr->lchild=pl;
    plr->rchild=p;
    
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);
    
    if(root==p)
    {
    	root=plr;
	}
	return plr;
}
struct node * RLrotation(struct node *p)
{
    struct node *pr=p->rchild;	
    struct node *prl=pr->lchild;
    
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    
    prl->lchild=p;
    prl->rchild=pr;
    
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);
    
    if(root==p)
    {
    	root=prl;
	}
	return prl;
}
struct node * rinsert(struct node *p,int key)
{ 
struct node *t;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->height=1;
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
	
	p->height=NodeHeight(p);
	if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
	{
	    return LLrotation(p);	
	}
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
	{
	    return LRrotation(p);	
	}
	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
	{
	    return RRrotation(p);	
	}
	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
	{
	    return RLrotation(p);	
	}
	return p;
}
void inorder(struct node *p)
{if(p!=NULL)
    {
	    inorder(p->lchild);
	    printf("->\t%d",p->data);
	    inorder(p->rchild);
    }
}
int main()
{
	root=rinsert(root,20);
	rinsert(root,30);
	rinsert(root,25);
	inorder(root);
	
}

