#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>> &con, int x, vector<int> &d) 
{
	queue<int> q;
	d[x] = 0;
	for(q.push(x); !q.empty();) 
	{
		x = q.front();
		q.pop();
		for(int y : con[x]) 
		{
			if(d[y] < 0) 
			{
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}


int main() 
{
	int z;
	for(scanf("%d", &z); z; --z) 
	{
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		--x;
		--y;
		long long r = (n - 1LL) * n / 2LL - m;
		vector<vector<int>> con(n);
		for(; m; --m) 
		{
			int s, t;
			cin >> s >> t;
			--s;
			--t;
			con[s].push_back(t);
			con[t].push_back(s);
		}
		vector<int> dx(n, -1), dy(n, -1);
		bfs(con, x, dx);
		bfs(con, y, dy);
		vector<int> d(n);
		for(int x : dy) 
			++d[x];
		for(int i = 1; i < n; ++i) 
			d[i] += d[i - 1];
		for(int i = 0; i < n; ++i) 
		{
			const int temp = dx[y] - dx[i] - 2;
			if(temp >= 0) 
				r -= d[temp];
		}
		cout << r << "\n";
	}
	return 0;
}
