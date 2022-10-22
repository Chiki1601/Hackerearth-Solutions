#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include<vector>
using namespace std;
 
 
 
long int setBits(int n)
{
	long int count=0;
	while(n>0)
	{
		count++;
		n=n&(n-1);
	}
	
	return count;
}
 
 
bool comparison(pair<int,int> a,pair<int,int> b)
{
	if(a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
	 
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	
    int t;
    cin>>t;
    
    while(t--)
    {
    	long int n;
    	cin>>n;
    	int* arr=new int[n];
    	//stores the count and set bits and the index
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
        	cin>>arr[i];
        	v.push_back(make_pair(setBits(arr[i]),i));
        }
        
        sort(v.begin(),v.end(),comparison);
        
        for(auto it=v.begin();it!=v.end();it++)
        {
        	cout<<arr[it->second]<<" ";
        }
        cout<<endl;
        v.clear();
        delete [] arr;
    	
    }
    
    
    
    
    return 0;
}
