#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
int n, k, ar[100001], cnd;
bool ok;

int dfs(int u, int p) 
{
	if(ok) 
		return 0;
	int mx = 0;
	for(auto& v : g[u]) 
	{
		if(v == p) 
			continue;
		int child = dfs(v, u);
		if(mx + child >= k) 
			ok = true;
		mx = max(mx, child);
	}
	if(ar[u] > cnd) 
		return 0;
	return mx + 1;
}

bool okay(int x) 
{
	ok = false;
	cnd = x;
	dfs(0, -1);
	return ok;
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while(t--) 
    {
		cin >> n >> k;
		for(int i = 0; i < n; ++i) 
			cin >> ar[i];
		for(int i = 1, u, v; i < n; ++i) 
		{
			cin >> u >> v;
			--u;
			--v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int l = 0, r = 100001;
		while(l < r) 
		{
			int x = (l + r) >> 1;
			if(okay(x)) 
				r = x;
			else 
				l = x + 1;
		}
		if(r == 100001) 
			r = -1;
		cout << r << endl;
	}
}
