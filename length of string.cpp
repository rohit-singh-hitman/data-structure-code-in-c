#include<stdio.h>
#include<stdlib.h>
void countvc(char *a)
{
	int i=0,ccount=0,vcount=0;
	for(int i=0;a[i]!='\0';i++)
 	{
 		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' ||a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
 		{
 			vcount++;
		}
		 else if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
		 {
		 	ccount++;
		 }
    }
    printf("vowel is%d\nconsonant is%d\n",vcount,ccount);
}
void palindrome(char *a)
{
 	int i,j=0;
 	for(int i=0;a[i]!='\0';i++)
 	{	
	}
	printf("\n%d",i);
	for(j=0;j<i;j++,i--)
	{
	    if(a[i]==a[j])
	 	{
	 		printf("palindrome");
		 }
		 else
		 {
		 	printf("not a ");
		 }
	 	
	 }
}
void wordcount(char *a)
{
	int word=0;
 	for(int i=0;a[i]!='\0';i++)
 	{
 		if(a[i]=='\0' && a[i-1]!='\0')
 		{
 			word++;
		}
    }
    printf("word is %d\n",word);
}
 void upprcas(char *a)
 {
 	for(int i=0;a[i]!='\0';i++)
 	{
 		a[i]=a[i]-32;
	 }
	 printf("uppercase is %s\n",a);
 }
 void lowrcas(char *a)
 {
 	for(int i=0;a[i]!='\0';i++)
 	{
 		a[i]=a[i]+32;
	 }
	 printf("lower case is %s\n",a);
 }
 void rvrs2(char *a)
 {
 	int i;
 	char t;
 	for(int i=0;a[i]!='\0';i++)
 	{
	}
	printf("%d",i);
	for(int j=0;j<=i;j++,i--)
	{
		t=a[j];
		a[j]=a[i];
		a[i]=t;
	}
	printf("%s\n",a);
 }
 void rvrs(char *a)
 {
 	char b[10];
 	int i,j;
 	for(int i=0;a[i]!='\0';i++)
 	{	
	}
	printf("%d",i);
	for(int j=0;i>=0;j++,i--)
	{
		b[j]=a[i];
	}
	b[j]='\0';
	printf("%s\n",b);
 }
int main()
{
	char a[]="madam";
	

	int i;
	for(i=0;a[i]!='\0';i++)
	{
	}
	printf("length is %d\n",i);
	upprcas(a);
	lowrcas(a);
	countvc(a);
	rvrs2(a);
	palindrome(a);
	return 0;
}
