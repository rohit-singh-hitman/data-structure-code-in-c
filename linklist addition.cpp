#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coe;
	int exp;
	struct node *next;
	
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
void data(struct node *head)
{
	int n,i;
	printf("enter the number of node");
	scanf("%d",&n);
	struct node *temp,*prev=head;
	for(i=0;i<n;i++)
	{	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the coe");
	scanf("%d",&temp->coe);
	scanf("%d",&temp->exp);
	temp->next=NULL;
	if(head==NULL)
	head=prev=temp;
	else
	{
	prev->next=temp;
	prev=temp;
}
}
}
void add()
{
	printf("hhdfgdcjd");
	struct node *temp3=head3,*temp1=head1,*temp2=head2,*p=head3;
	while(temp1!=NULL)
	{
		temp3=(struct node *)malloc(sizeof(struct node));
		if(head3==NULL)
		head3=p=temp3;
	if(temp1->exp>temp2->exp)
	{
		temp3->exp=temp1->exp;
		temp3->coe=temp1->coe;
		temp1=temp1->next;
		temp3->next=NULL;
	}
	else if(temp2->exp>temp1->exp)
	{
	temp3->exp=temp2->exp;
	temp3->coe=temp2->coe;
	temp2=temp2->next;	
	temp3->next=NULL;
	}
	else
	{
		temp3->coe=temp2->coe+temp1->coe;
		temp3->exp=temp1->exp;
		temp2=temp2->next;
		temp1=temp1->next;
		temp3->next=NULL;
	}
	p->next=temp3;
	p=temp3;
	}
}
void display()
{
	struct node *d;
	d=head3;
	while(d!=NULL)
	{
		printf("%d",d->coe);
		printf("%d",d->exp);
		d=d->next;
	}
	
	}

void main()
{
	struct node *head=NULL;
	 data(head1);
	 data(head2);
	 add();
	 display();
}


