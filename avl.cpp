#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *lchild;
	int data;
	int height;
	struct node *rchild;
};
struct node *root=NULL;
int nodeheight(struct node *p)
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
struct node *llrotation(struct node *p)
{
	struct node *pl=p->lchild;
	struct node *plr=pl->rchild;
	
	pl->rchild=p;
	p->lchild=plr;
	
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	
	if(root==p)
	{
		root=pl;
	}
	return pl;
}
struct node *rrrotation(struct node *p)
{
	struct node *pr=p->rchild;
	struct node *prl=pr->lchild;
	
	pr->lchild=p;
	p->rchild=prl;
	
	p->height=nodeheight(p);
	pr->height=nodeheight(pr);
	
	if(root==p)
	{
		root=pr;
	}
	return pr;
}
struct node *lrrotation(struct node *p)
{
	struct node *pl=p->lchild;
	struct node *plr=pl->rchild;
	
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	
	plr->lchild=pl;
	plr->rchild=p;
	
	
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	plr->height=nodeheight(plr);
	
	if(root==p)
	{
		root=plr;
	}
	return plr;
}
struct node *rlrotation(struct node *p)
{
	struct node *pr=p->rchild;
	struct node *prl=pr->lchild;
	
	pr->lchild=prl->rchild;
	p->rchild=prl->lchild;
	
	prl->rchild=pr;
	prl->lchild=p;
	
	
	p->height=nodeheight(p);
	pr->height=nodeheight(pr);
	prl->height=nodeheight(prl);
	
	if(root==p)
	{
		root=prl;
	}
	return prl;
}
struct node * rinsert(struct node *p,int key)
{   struct node *t;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
	    t->lchild=t->rchild=NULL;
	    t->data=key;
	    t->height=1;
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
	
	p->height=nodeheight(p);
	if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
	    return llrotation(p);
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
	    return lrrotation(p);
	else if(balancefactor(p)==-2 && balancefactor(p->lchild)==1)
	    return rlrotation(p);
	else if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
	    return rrrotation(p);    
	return p;
}
struct node *Delete(struct node *p,int key)
{   
   struct node *q;
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
		p->lchild=Delete(p->lchild,key);
	}
	else if(key>p->data)
	{
		p->rchild=Delete(p->rchild,key);
	}
	else
	{
		if(nodeheight(p->lchild)>nodeheight(p->rchild))
		{
			q=inpre(p->lchild);
			p->data=q->data;
			p->lchild=Delete(p->lchild,q->data);
		}
		else
		{
			q=insuc(p->rchild);
			p->data=q->data;
			p->rchild=Delete(p->rchild,q->data);
		}
	}
	p->height=nodeheight(p);
	if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
	    return llrotation(p);
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
	    return lrrotation(p);
	else if(balancefactor(p)==-2 && balancefactor(p->lchild)==1)
	    return rlrotation(p);
	else if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
	    return rrrotation(p);
	else if(balancefactor(p)==-2 && balancefactor(p->lchild)==0)
	    return rrrotation(p);
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==0)
	    return llrotation(p);
	return p;
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
int main()
{
	root=rinsert(root,10);
	rinsert(root,20);
	rinsert(root,60);
	rinsert(root,40);
	rinsert(root,2);
	Delete(root,10);
	preorder(root);
	rinsert(root,10);
	preorder(root);
	return 0;
}
