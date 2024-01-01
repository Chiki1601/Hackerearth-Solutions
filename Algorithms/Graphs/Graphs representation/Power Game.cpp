#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> W(m), low(n, -1), H(n), cands;
	for(int& a : W) 
		cin >> a;
	vector<vector<pair<int, int>>> E(n);
	for(int i = 0; i < m; ++i) 
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		E[a].push_back({b, i});
		E[b].push_back({a, i});
	}
	function<void(int)> go = [&](int x) 
	{
		low[x] = H[x];
		for(auto [y, eid] : E[x]) 
		{
			if(low[y] == -1) 
			{
				H[y] = H[x] + 1;
				go(y);
				low[x] = min(low[x], low[y]);
				if(low[y] == H[y]) 
					cands.push_back(W[eid]);
			} 
			else if(H[y] < H[x] - 1) 
				low[x] = min(low[x], H[y]);
		}
	};
	go(0);
	sort(cands.rbegin(), cands.rend());
	long long mn = 0, mx = 0;
	for(int i = 0; i < cands.size(); ++i) 
	{
		if(i & 1) 
			mn += cands[i];
		else 
			mx += cands[i];
	}
	cout << mx << ' ' << mn << endl;
}
