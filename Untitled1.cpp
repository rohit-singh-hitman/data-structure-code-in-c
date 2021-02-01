#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,k=0,j;
	    int c=0;
	    cin>>n;
	    long int a[n];
	    long int arr[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<n-1;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            if(a[i]<a[j])
	            c++;
	        }
	        arr[k]=c;
	        c=0;
	        k++;
	    }
	    for(i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	   /* b[a[n-1]]={0}
	    for(i=0;i<n;i++)
	    {
	        b[a[i]]+=1;
	    }
	    for(i=0;i<a[n-1];i++)
	    {
	        if(b[i]!=0)
	        {
	            c++;;
	           // j++;
	        }
	    }
	    int arr[c];
	    for(i=0;i<c-1;i++)
	    {
	        for(j=i+1;j<c;j++)
	        {
	            
	        }
	    }*/
	    
	}
	return 0;
}

