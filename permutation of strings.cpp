#include<stdio.h>
#include<stdlib.h>


void perm(char s[],int k)
{
	static int a[10]={0};
	static char res[10];
	if(s[k]=='\0')
	{
		printf("%s\n",res);
	}
	else
	{
	    for(int i=0;s[i]!='\0';i++)	
	    {
	    	if(a[i]==0)
	    	{
	    	
	    		res[k]=s[i];
	    		a[i]=1;
	    		perm(s,k+1);
	    		a[i]=0;
			}
		}
	}
	
}
int main()
{
	char a[]="abcdef";
	int i,fact=1;
	for(i=0;a[i]!='\0';i++)
	{
	}
	for(int j=1;j<=i;j++)
	{
		fact=fact*j;
	}
	printf("length is %d\n",i);
	printf("the number of permutations is total=%d\n",fact);
	perm(a,0);
	return 0;
}
