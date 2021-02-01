
#include<iostream>
using namespace std;
class studet
{
public:
int id;
string name;
string dept;
string college;
public:
void input()
{
cout<<"Enter ID of student"<<endl;
cin>>id;
cout<<"Enter name of student"<<endl;
cin>>name;
cout<<"Enter department of student"<<endl;
cin>>dept;
cout<<"Enter College name"<<endl;
cin>>college;
}
};
class stuexam : public studet
{
public :
int arr[6];
public:
void enter()
{
int i;
cout<<"Enter marks of six subjects"<<endl;
for(i=0;i<6;i++)
{
cin>>arr[i];
}
}

};
class sturesult :public stuexam
{
float cgpa;
public:
void display()
{
int i,s=0;
cout<<"Id of student is-"<<id<<endl;
cout<<"Name of student is-"<<name<<endl;
cout<<"Department of student is-"<<dept<<endl;
cout<<"College name is-"<<college<<endl;
for(i=0;i<6;i++)
s=s+arr[i];
cgpa=s/6;
cout<<"cgpa of student is- "<<cgpa;
}

};
int main()
{
studet o;
stuexam o1;
sturesult o2;
o2.input();
o2.enter();
o2.display();
}
