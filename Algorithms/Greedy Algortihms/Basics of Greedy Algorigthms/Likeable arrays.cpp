#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t, n, x; 
    cin >> t; 
    while(t--)
    {
	cin >> n;
       	map<long long int, long long int>mp;
       	for(int i = 0; i < n; i++)
	{
            cin >> x;
            mp[x]++;
       	}
       	long long int ans = 0;
       	for(auto it:mp)
	{
            if(it.second >= it.first) 
		ans += (it.second - it.first);
            else 
	  	ans += min(it.first - it.second, it.second);
       	}
       	cout << ans << endl;
    }
    return 0;
}
