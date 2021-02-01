#include<stdio.h>
void main()
{
	
	float e1,e2,e3,pa,pb,pc;
	printf("\nenter the values of event e1,e2,e3 :");
	scanf("%f%f%f",&e1,&e2,&e3);
	pa=e1/(1-((1-e1)*(1-e2)*(1-e3)));
	pb=(1-e1)*(e2)/(1-((1-e1)*(1-e2)*(1-e3)));
	pc=(1-e1)*(1-e2)*(e3)/(1-((1-e1)*(1-e2)*(1-e3)));
	printf("\nprobability of winnig a is %f",pa);
	printf("\nprobability of winnig b is %f",pb);
	printf("\nprobability of winnig c is %f",pc);
}
