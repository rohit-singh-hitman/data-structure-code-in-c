#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	
	if(t==NULL)
	{
		printf("stack is full\n");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}
int pop()
{   int x=-1;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		struct node *p=top;
		top=top->next;
		x=p->data;
		free(p);
	}
	return x;
}
void display()
{
 struct node *p=top;
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}
int main()
{
	
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();
	
	
}
