#include<stdio.h>
#include<stdlib.h>

struct node
{
	int exp;
	int coe;
	struct node *next;

};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;

void insert1()
{
	struct node *new,*temp;
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter exp");
	scanf("%d", &new->exp);
	printf("coef");
	scanf("%d", &new->coe);
	if(head1==NULL)
	{
		head1=new;
		head1->next=NULL;
		temp=head1;
	}
	else
	{ 
	
		temp->next=new;
		new->next=NULL;
		temp=new;
	}
}

void insert2()
{
	struct node *new;
	struct node *temp;
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter exp");
	scanf("%d", &new->exp);
	printf("coef");
	scanf("%d", &new->coe);
	if(head2==NULL)
	{
		head2=new;
		head2->next=NULL;
		temp=head2;
	}
	else
	{
		
		temp->next=new;
		new->next=NULL;
		temp=new;
	}
}

void add()
{
	struct node *temp1,*temp2,*temp3;
	temp1=head1;
	temp2=head2;
	temp3=head3;
	while(temp1 && temp2)
	{ temp3=(struct node *)malloc(sizeof(struct node));
		  temp3->next=NULL;
		if(temp1->exp>temp2->exp)
		{ 
			temp3->exp=temp1->exp;
			temp3->coe=temp1->coe;
			temp1=temp1->next;
			
		}
		if(temp2->exp>temp1->exp)
		{
		    temp3->exp=temp2->exp;
			temp3->coe=temp2->coe;
			temp2=temp2->next;
		}
		if(temp2->exp==temp1->exp)
		{
			temp3->coe=temp1->coe+temp2->coe;
			temp3->exp=temp1->exp;
			temp1=temp1->next;
		temp2=temp2->next;
		}
	}
	if(temp1!=NULL)
	{
		while(temp1!=NULL)
		{   temp3=(struct node *)malloc(sizeof(struct node));
		    temp3->next=NULL;
			temp3->exp=temp1->exp;
			temp3->coe=temp1->coe;
			temp1=temp1->next;
			temp3=temp3->next;
		}
	}
	if(temp2!=NULL)
	{
		while(temp2!=NULL)
		{   temp3=(struct node *)malloc(sizeof(struct node));
		    temp3->next=NULL;
			temp3->exp=temp2->exp;
			temp3->coe=temp2->coe;
			temp2=temp2->next;
			temp3=temp3->next;
		}
	}
}

void display()
{
	struct node *temp;
	temp=head3;
	while(temp!=NULL)
	{
		printf("%d\n",temp->exp);
		printf("%d\n",temp->coe);
		temp=temp->next;
	}
}

void main()
{
	int c;
	while(1)
	{
		scanf("%d",&c);
	switch(c)
	{
	case 1: insert1();
	break;
	
	case 2: insert2();
	break;
	
	case 3: add();
	break;
	
	case 4: display();
	break;
	
	case 5:exit(0);
		
	}
}
}
