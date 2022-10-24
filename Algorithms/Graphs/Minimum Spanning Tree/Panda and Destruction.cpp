#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m;
	cin >> n >> m;
	map<long long, vector<long long>>mp;
	for(long long i = 1; i <= m; i++)
	{
		long long x, y;
		cin >> x >> y;
		if(mp.find(x) != mp.end())
			mp[x].push_back(y);
		else if(mp.find(y) != mp.end())
			mp[y].push_back(x);
		else
			mp[x].push_back(y);
	}
	cout << mp.size();
}
