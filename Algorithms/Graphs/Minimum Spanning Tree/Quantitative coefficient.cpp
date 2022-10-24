#include<bits/stdc++.h>
using namespace std;
int par[1501];
 
int find(int a)
{
	if(par[a] < 0)
		return a;
	return par[a] = find(par[a]);
}
 
void merge(int a, int b)
{
	par[a] = b;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			par[i] = -1;
		pair<long long int, pair<int, int>>p[m];
		for(int i = 0; i < m; i++)
		{
			int a, b;
			long long int c;
			cin >> a >> b >> c;
			p[i] = {c, {a, b}};
		}
		sort(p, p + m);
		long long int ans = 1;
		for(int i = 0; i < m; i++)
		{
			long long int wt = p[i].first;
			int a = p[i].second.first, b = p[i].second.second;
			a = find(a), b = find(b);
			if(a != b)
			{
				merge(a, b);
				ans = (ans * wt) % 1000000007;
			}
		}
		cout << ans << endl;
	}
}
