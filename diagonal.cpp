#include <iostream>
using namespace std;
class matrix
{
	private:
		int *a;
		int n;
	public:
		matrix(int n)
		{
			this->n=n;
			a=new int(n);
		}
		void set(int i,int j,int x);
		int get(int i,int j);
		void display();
};
void matrix::set(int i,int j,int x)
{
	if(i==j)
	    a[i]=x;
}
int matrix::get(int i,int j)
{
	if(i==j)
	{
		return a[i];
	}
	else
	    return 0;
}
void matrix::display()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				cout<<a[i];
			}
			else
			{
				cout<<"0";
			}
		}
		cout<<"\n";

	}
}
int main()
{
 int d;
 cout<<"Enter Dimensions";
 cin>>d;

 matrix m(d);

 int x;
 cout<<"Enter All Elements";
 for(int i=0;i<d;i++)
 {
 for(int j=0;j<d;j++)
 {
     cin>>x;
     m.set(i,j,x);
 }
 }

 m.display();
 return 0;
}
