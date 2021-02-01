#include <iostream>
using namespace std;
class height
{
    int f;
    int i;
    public:
    void input()
    {
        cout<<"enter the height in feet & inches";
        cin>>f>>i;
        
    }
    void add(height h1,height h2)
    {
        
        f=h1.f+h2.f+(h1.i+h2.i)/12;
        i=(h1.i+h2.i)%12;
       /* i=h1.i+h2.i;
        f=h1.f+h2.f;
        if(i>12)
        {
            f=f+(i/12);
            i=i%12;
            
        }*/
    }
    void print(height h)
    {
        cout<<"sum of height is"<<h.f<<"feet"<<h.i<<"inches";
    }
};

int main() {
	height h1,h2,h;
	h1.input();
	h2.input();
	h.add(h1,h2);
	h.print(h);
	return 0;
}

