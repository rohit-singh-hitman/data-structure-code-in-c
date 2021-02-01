
#include<iostream>
using namespace std;
class dist2;
class dist1
{
   int m;
   int cm;
   public:
   friend void fn(dist1,dist2);
};

class dist2
{
   int f;
   int in;
   public:
   friend void fn(dist1,dist2);
};
void fn(dist1 d1,dist2 d2)
{
   float a,b,c,q,w,e;
   int s,d,x,y;
   cout<<"enter distance in m";
   cin>>d1.m;
   cout<<"enter distance in cm";
   cin>>d1.cm;
   cout<<"enter distance in feet";
   cin>>d2.f;
   cout<<"enter distance in inches";
   cin>>d2.in;
   q=d1.m*100;
   w=d2.f*30;
   e=d2.in*2.54;
   s=d1.cm+q+w+e;
   x=(q+d1.cm)-(w+e);
   cout<<"sum of distance is: "<<s/100<<" meter"<<s%100<<" centimeter"<<endl;
    cout<<"difference of distance is: "<<x/100<<" meter"<<x%100<<" centimeter"<<endl;
   a=d1.m*39.37;
   b=d1.cm*0.39;
   c=d2.f*12;
   d=a+b+c+d2.in;
   y=(a+b)-(c+d2.in);
   cout<<"sum of distance is: "<<d/12<<" feet"<<d%12<<" inches"<<endl;
   cout<<"difference of distance is: "<<y/12<<" feet"<<y%12<<" inches"<<endl;
 }
int main()
{
  dist1 d1;
  dist2 d2;
  fn(d1,d2);
  return 0;
}

   
   

