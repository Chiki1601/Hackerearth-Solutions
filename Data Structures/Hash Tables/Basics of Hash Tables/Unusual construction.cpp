#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
   	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
   	cin >> t;
   	while(t--)
   	{
       	long long n, m, maxm = 0, ans = 0, l, r, w;
	  	cin >> n >> m;
       	map<pair<long long, long long>, pair<long long, long long>>mp;
       	for(int i = 0; i < m; i++)
		{
           	cin >> l >> r >> w;
           	if(mp.find({l, r}) != mp.end())
			{
               	mp[{l, r}].first++;
               	mp[{l, r}].second += w;
           	}
           	else
               	mp[{l, r}] = {1ll, w};
           	maxm = max(maxm, mp[{l, r}].first);
       	}
       	for(auto it : mp)
		{
           	if(it.second.first != maxm)
               	ans += it.second.second;
        }
       	cout << ans << endl;
    }
	return 0;
}
