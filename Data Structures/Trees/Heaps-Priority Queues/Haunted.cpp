#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m, i, j, x;
	cin >> n >> m;
	unordered_map<long long, long long>mp;
	priority_queue<pair<long long, long long>> pq;
	for(i = 0; i < n; i++)
    {
		cin >> x;
		mp[x]++;
		pq.push({mp[x], x});
		cout << pq.top().second << " " << pq.top().first << endl;
	}
	return 0;
}
