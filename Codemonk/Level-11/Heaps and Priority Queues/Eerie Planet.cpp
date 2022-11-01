#include <bits/stdc++.h>
using namespace std; 

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	int h, t, c, q, i, j, x, y, z, a, b, ans[100005];
	cin >> h >> c >> q;
	multiset<int> pq;
	multiset<pair<int, int>> leave;
	pair<pair<int, int>, int> emp[100005], query[100005];
	for(i = 0; i < c; ++i) 
	{
		cin >> x >> y >> z;
		emp[i] = make_pair(make_pair(y, z), x);
	}
	for(i = 0; i < q; ++i) 
	{
		cin >> x >> y;
		query[i] = make_pair(make_pair(y, x), i);
	}
	sort(emp, emp + c);
	sort(query, query + q);
	int cur = 0, start = 0, end = 0;
	j = 0;
	for(i = 0; i < q; ++i) 
	{
		int entry = query[i].first.first, height = query[i].first.second, idx = query[i].second;
		while(j < c && emp[j].first.first <= entry) 
		{
			pq.insert(emp[j].second);
			leave.insert(make_pair(emp[j].first.second, emp[j].second));
			j += 1;
		}
		while(!leave.empty() && leave.begin()->first < entry) 
		{
			pq.erase(pq.find(leave.begin()->second));
			leave.erase(leave.begin());
		}
		if(!pq.empty() && *(--pq.end()) >= height) 
			ans[idx] = 0;
		else 
			ans[idx] = 1;
	}
	for(i = 0; i < q; ++i) 
		puts(ans[i] == 0 ? "NO" : "YES");
	return 0;
}
