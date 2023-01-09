#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long k, i = 0, ans = 0, j;
    cin >> s >> k;
    vector<long long> a[26];
    while(i < s.size())
    {
   	    a[s[i] - 'a'].push_back(i);
   	    i++;
    }
    i = 0;
    while(i < 26)
    {
   	    j = 1;
   	    while(j < a[i].size())
   	    {
   		    if(a[i][j] - a[i][j - 1] + 1 <= k)
   		    {   
   			    a[i][j] = a[i][j - 1];
   			    ans++;
   		    }
   		    j++;
   	    }
   	    i++;
    }
    cout << ans << endl;
}   	
