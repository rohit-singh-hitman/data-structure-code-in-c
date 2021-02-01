#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
struct stack
{
	int size;
	int top;
	char *s;
};

void create(struct stack *st)
{
	printf("enter sizze of stack");
	scanf("%d",&st->size);
	st->s=(char *)malloc(st->size*sizeof(char));
	st->top=-1;
}
void display(struct stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	{
		printf("%d\n",st.s[i]);
	}
}
void push(struct stack *st,int x)
{
	if(st->top==st->size-1)
	{
		printf("stack full");
	}
	else
	{
		st->top++;
		st->s[st->top]=x;
	}
}
int pop(struct stack *st)
{   int x=-1;
	if(st->top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		x=st->s[st->top];
		st->top--;
	}
	return x;
	
}
int peek(struct stack st,int pos)
{
	int x=-1;
	if(st.top-pos+1<0)
	{
		printf("invalid position");
	}
	else
	{
		x=st.s[st.top-pos+1];
	}
	return x;
}
char stacktop(struct stack *st)
{
	if(st->top==-1)
	{
		return -1;
	}
	else
	{
		return st->s[st->top];
	}
}
int isoperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
	    return 0;
	else
	    return 1;
}
int prec(char x)
{
		if(x=='+' || x=='-')
		    return 1;
		else if(x=='*' || x=='/')
		    return 2;
	return 0;
}
int isempty(struct stack st)
{
	if(st.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char * convert(char * infix)
{
	char *postfix;
	int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0')
    {
    	if(isoperand(infix[i]))
    	    postfix[j++]=infix[i++];
    	else
    	{
    		if(prec(infix[i])>prec(stacktop(&st)))
    		{
    			push(&st,infix[i++]);
			}
			else
			{
				postfix[j++]=pop(&st);
			}
		}
	}
	while(!isempty(st))
	{
		postfix[j++]=pop(&st);
	}
	postfix[j]='\0';
	return postfix;
}
int isfull(struct stack st)
{
	if(st.top==st.size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	struct stack st;
	
 create(&st);
 char *infix="a+b*c-d/e";
 push(&st,'#');

 char *postfix=convert(infix);

 printf("%s ",postfix);


 return 0;


 
 return 0;
	
}
