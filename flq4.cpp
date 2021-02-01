#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int noc,tp,flag=0,e,e1,p,p1,p2,i,flag1=0,m=0;
	    cin>>noc>>tp;
	    int a[noc];
	    for(i=0;i<noc;i++)
	    {
	        cin>>a[i];
	    }
	    for(i=0;i<noc;i++)
	    {
	        if(tp%a[i]!=0)
	        {
	            p=i;
	            e=a[i];
	            flag=1;
	            break;
	        }
	    }
	    if(flag==1)
	    {
	    	cout<<"YES ";
	        for(i=0;i<noc;i++)
	        {
	            if(i==p)
	            {
	                cout<<(tp/a[i])+1<<" ";
	            }
	            else
	            {
	                cout<<0<<" ";
	            }
	        }
	        cout<<endl;
	    }
	    else
	    {
	    //	cout<<"********";
	        for(i=0;i<noc;i++)
	        {
	            if(a[i]>m)
	            {
	                p1=i;
	                m=a[i];
	            }
	        }
	       // cout<<"********";
	        for(i=0;i<noc;i++)
	        {
	           if(m%a[i]!=0&&a[i]!=m)
	           {
	               p2=i;
	                e1=a[i];
	                flag1=1;
	                break;
	               
	           }
	        }
	      //  cout<<"+++++++++++++";
	        if(flag1==1)
	        {
	        	cout<<"YES ";
	            for(i=0;i<noc;i++)
	            {
	                if(i==p1)
	                {
	                    cout<<(tp/m)-1<<" ";
	                }
	                if(i==p2)
	                {
	                    cout<<(m/e1)+1<<" ";
	                }
	                else
	                {
	                    cout<<0<<" ";
	                }
	            }
	            cout<<endl;
	        }
	        else
	        {
	            cout<<"NO"<<endl;
	        }
	    }
	    
	}
	return 0;
}

