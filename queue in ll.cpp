#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
	{
		printf("queue is full\n");
	}
	else
	{
		t->data=x;
		if(front==NULL)
		{
		    front=rear=t;	
		}
		t->next=NULL;
		rear->next=t;
		rear=t;
	}
}
int dequeue()
{   int x=-1;
	struct node *p;
	p=front;
	if(front==NULL)
	{
		printf("queue is empty\n");
		
	}
	else
	{
		front=front->next;
		x=p->data;
		free(p);
	}
	return x;
}
void display()
{
	struct node *p;
	p=front;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	dequeue();
	int r=dequeue();
	printf("%d\n",r);
	display();
	
}
