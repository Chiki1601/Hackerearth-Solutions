#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> E(n);
	for(int i = 0; i < n - 1; ++i) 
    {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	vector<int> A(n), B(n);
	function<void(int, int)> dfs = [&](int x, int p) 
    {
		int off = 0, dp = 0;
		for(int y : E[x]) 
        {
			if(y == p) 
                continue;
			dfs(y, x);
			dp += A[y];
			off = max(off, B[y] - A[y] + 1);
		}
		B[x] = dp;
		A[x] = dp + off;
	};
	dfs(0, -1);
	cout << A[0] << "\n";
}
