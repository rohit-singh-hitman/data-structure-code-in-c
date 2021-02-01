#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
    {
    	vector<pair<long int,int>>vect;
    	int n,m,c=0,j;
    	cin>>n>>m;
    	int arr[m]={0};
    	int i;
    	long int fn,ln,min,min1=100000000,d;
    	for(i=0;i<m;i++)
    	cout<<arr[i];
    	for(i=0;i<n;i++)
    	{
    	    cin>>arr[i];
    	    vect.push_back(make_pair(arr[i],i));
    	}
    	sort(vect.begin(),vect.end());
    	for(i=0;i<n;i++)
    	{
    	    vect[i].second=vect[i].second%m;
    	    cout<<vect[i].second;
    	}
    	for(i=0;i<n-1;i++)
    	{
    	    if(vect[i].second==vect[i+1].second)
    	    {
    	        continue;
    	    }
    	    else
    	    {
    	        for(j=i;j<n;j++)
    	        {
        	        if(c==0)
        	        {
        	            fn=vect[j].first;
        	            cout<<fn<<" ";
        	        }
        	        cout<<vect[j].second;
        	        d=vect[j].second;
        	        if(arr[d]==0)
        	        {
        	            cout<<"1";
        	            arr[vect[j].second]=1;
        	            c++;
        	        }
        	        cout<<endl;
        	        if(c==m)
        	        {
        	            c=0;
        	            ln=vect[j].first;
        	            min=ln-fn;
        	         //   cout<<min<<" ";
        	            break;
        	        }
    	        }
    	        for(int k=0;k<m;k++)
    	        arr[k]=0;
    	    }
    	     if(min<min1)
    	        min1=min;
    	}
    	cout<<min1<<endl;
}
	return 0;
}

