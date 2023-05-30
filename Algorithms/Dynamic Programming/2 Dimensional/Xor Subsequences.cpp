#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
	cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i];
    vector<bool> freq(1024, false);
    for(auto ele : v) 
	{
        for(int i = 0; i < 1024; i++) 
		{
            if(freq[i]) 
                freq[i ^ ele] = true;
        }
		  freq[ele] = true;
        int c = 0;
        for(int i = 0; i < 1024; i++) 
		{
            if(freq[i]) 
                c++;
        }
		  cout << c << ' ';
    }
	cout << endl;
}
