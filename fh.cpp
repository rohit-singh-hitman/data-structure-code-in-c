#include <bits/stdc++.h> 
using namespace std; 
  
// Driver code 
int main() 
{ 
int arr[100][100];
   fstream file; 
  file.open("raj.txt",ios::in); 
  string word;
  int i,co=0,k=0,li;
  int book[100],lib[100],day[100];
 while(file>>word)
 {
 	co++;
 	if(co==1)
 	{
	 	book[k]=stoi(word);
	 	//cout<<book[0];
	 }
 	else if(co==2)
 	{ 
 		lib[k]=stoi(word);
 		if(k==1)
 		{
 			li=lib[0];
 		}
 	}
	 else if(co==3) 
 	day[k]=stoi(word);
 	else if(co>3)
 	{		 
	 	arr[k][co-4]=stoi(word);
			 
	 }
	 if(co==book[k]+3)
	 {
	 co=0;
	 k++;
	}
 }
 /*for(i=0;i<=lib[0];i++)
 {
 	for(int j=0;j<book[i];j++)
 	{
		cout<<arr[i][j]<<" "; 		
	 }
 }
/*for(i=0;i<3;i++)
{
	cout<<book[i]<<" ";
}*/

 map<int,int>mp;
 for(i=0;i<book[0];i++)
 {
 	mp.insert({arr[0][i],i});
 }
 for(auto it =mp.begin();it!=mp.end();it++)
 {
 	cout<<it->first<<" "<<it->second<<endl;
 }
 
  //file.close();
  
   return 0; 
} 
