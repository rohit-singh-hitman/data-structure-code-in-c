#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class profile
{
string name, ar;
    char password[50];
public :   
void defaul(string y)
    {
      int i;
      ar="X";
      for (i=0;i<3;i++)
       password[i]=y[i];
       password[i]='\0';
    }
    void getdata()
    {
    cout<<"Enter Name : "; cin>>name;
    defaul(name);
    }
    void change()
    { 
    int ch;
    cout<<"Press 1 : Password change\nPress 2 : Access right change\nPress 3 : Both change\n";
        cin>>ch;
        if (ch>3)
        cout<<"Wrong choice ! \n";
         
        switch (ch)
        {
        case 1 : cout<<"Enter your new password : "; cin>>password;
            break;
    case 2 : cout<<"Enter new access right (W/R/X) : "; cin>>ar;
                 break;
        case 3 : cout<<"Enter your new password : "; cin>>password; 
                 cout<<"Enter new access right (W/R/X) : "; cin>>ar;
                 break;
        }                         
    }
    void displaydata()
    {
    cout<<endl<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Password : "<<password<<endl;
    cout<<"Access Right : "<<ar<<endl;
    cout<<endl<<endl;
    }
};
int main()
{
profile p;
p.getdata();
p.displaydata();
p.change();
p.displaydata();
return 0;
}
