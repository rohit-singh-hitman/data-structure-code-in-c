#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int *Q;
};
void enqueue(struct queue *q,int x)
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
int dequeue(struct queue *q)
{
	int x=-1;
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
int first(struct queue q)
{
	
	return q.Q[q.f+1];
}
int last(struct queue q)
{
	
	return q.Q[q.r];
}
void display(struct queue q)
{
	int i;
	for(i=q.f+1;i<=q.r;i++)
	{
		printf("%d\n",q.Q[i]);
	}
	printf("\n");
}
int main()
{
	struct queue q;
	printf("enter size of queue");
	scanf("%d",&q.size);
	q.Q=(int *)malloc(q.size*sizeof(int));
	q.f=q.r=-1;
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	enqueue(&q,50);

	display(q);
	printf("first element in queue is %d\n",first(q));
	printf("last element in queue is %d\n",last(q));
	printf(" element in queue is  %d\n",isfull(q));
	printf(" element in queue is %d\n",isempty(q));
	printf(" element in queue after delete is %d\n",dequeue(&q));
	printf(" element in queue after delete is %d\n",dequeue(&q));
	printf(" element in queue after delete is %d\n",dequeue(&q));
	display(q);
	
	
	
	
}
