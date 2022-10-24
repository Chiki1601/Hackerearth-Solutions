#include<bits/stdc++.h>
using namespace std;
long long int h[300003], st[1200012];
 
void build(int si, int ss, int se)
{
	if(ss == se)
	{
		st[si] = h[ss];
		return;
	}
	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);
	st[si] = max(st[2 * si], st[2 * si + 1]);
}
 
long long int query(int si, int ss, int se, int qs, int qe)
{
	if(qs > se || qe < ss)
		return -100000000000;
	if(ss >= qs && se <= qe)
		return st[si];
	int mid = (ss + se) / 2;
	long long int l = query(2 * si, ss, mid, qs, qe), r = query(2 * si + 1, mid + 1, se, qs, qe);
	return max(l, r);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	pair<long long int, long long int>p[n];
	for(int i = 0; i < n; i++)
	{
		long long int u, v;
		cin >> u >> v;
		p[i] = {u, v};
	}
	sort(p, p + n);
	map<long long int, int>mp;
	mp[-100000000000] = 0;      //for ower edge cases
	for(int i = 0; i < n; i++)
	{
		h[i + 1] = p[i].second; // for making 1 based index segment tree
		mp[p[i].first] = i + 1;
	}
	build(1, 1, n);
	while(q--)
	{
		long long int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;
		if(sx > fx)
		swap(sx, fx);
		map<long long int, int>::iterator it1, it2;
		it1 = mp.lower_bound(sx);
		it2 = mp.upper_bound(fx);
		it2--;
		int ind1 = it1->second, ind2 = it2->second;
		long long int ans;
		int Max = query(1, 1, n, ind1, ind2);
		if(Max >= max(fy, sy))
			ans = abs(fx - sx) + abs(sy - Max) + abs(fy - Max) + 2;
		else
			ans = abs(fx - sx) + abs(sy - fy);
		cout << ans << endl;
	}
}
