#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> adj[300010];
vector<pair<int, pair<int, int>>> qry[300010];
int n, q, p[300010], h[300010], lca[300010][20], answer[300010], sz[300010];
 
class Bit
{
	vector<int> bit;
	public:
		Bit(){}
		Bit(int n) 
		{
			bit.resize(n + 5);
		}
		void update(int pos, int val) 
		{
			if(!pos) 
				return;
			for(; pos < bit.size(); pos += pos & (-pos)) 
				bit[pos] += val;
		}
		int sum(int pos) 
		{
			int ans = 0;
			for(; pos; pos -= pos & (-pos)) 
				ans += bit[pos];
			return ans;
		}
};Bit bit;
 
void add(char c, int pos) 
{
	p[pos] = p[pos - 1];
	while(p[pos] && s[p[pos]] != c) 
		p[pos] = p[p[pos] - 1];
	p[pos] += c == s[p[pos]];
	int u = pos + 1;
	lca[u][0] = p[pos]; 
	h[u] = h[p[pos]] + 1;
	for(int i = 1; i < 20; i++) 
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	adj[lca[u][0]].push_back(u);
}
 
void build_kmp() 
{
	adj[0].push_back(1);
	for(int i = 1; i < s.size(); i++)
		add(s[i], i);
}
 
int get_lca(int u, int v) 
{
	if(h[u] < h[v]) 
		swap(u, v);
	int d = h[u] - h[v];
	for(int i = 0; i < 20; i++)
		if(d & (1<<i)) 
		u = lca[u][i];
	if(u == v) 
		return u;
	for(int i = 19; i >= 0; i--) 
	{
		if(lca[u][i] != lca[v][i]) 
		{
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	return lca[u][0];
}
 
void build_tree(int u) 
{
	sz[u] = 1;
	for(int v : adj[u])
	{
		build_tree(v);
		sz[u] += sz[v];
	}
}
 
void dfs(int u, int val) 
{
	bit.update(u, val);
	for(int v : adj[u]) 
		dfs(v, val);
}
 
void sack(int u, int keep) 
{
	int big = -1;
	for(int v : adj[u]) 
	{
		if(big == -1 || sz[v] > sz[big])
			big = v;
	}
	for(int v : adj[u]) 
	{
		if(v == big) 
			continue;
		sack(v, 0);
	}
	if(big != -1) 
		sack(big, 1);
	for(int v : adj[u]) 
	{
		if(v == big) 
			continue;
		dfs(v, 1);
	}
	bit.update(u, 1);
	for(auto it : qry[u]) 
	{
		int id = it.first, l = it.second.first, r = it.second.second;
		answer[id] = bit.sum(r) - bit.sum(l - 1);
	}
	if(!keep)
		dfs(u, -1);
}
 
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	cin >> s;
	build_kmp();
	char c;
	int x, l, r, op;
	for(int i = 0; i < q; i++)
	{
		answer[i] = -1;
		cin >> op;
		if(op == 1) 
		{
			cin >> c;
			add(c, s.size());
			s.push_back(c);
			n++;
		}
		else
			if(op == 2) 
			{
				cin >> l >> r;
				answer[i] = get_lca(l, r);
			}
			else 
			{
				cin >> x >> l >> r;
				if(l + x - 1 > r) 
					answer[i] = 0;
				else 
					qry[x].push_back({i,{l+x-1,r}});
			}
	}
	bit = Bit(n);
	build_tree(0);
	sack(0, 0);
	for(int i = 0; i < q; i++) 
	{
		if(answer[i] == -1) 
			continue;
		cout << answer[i] << endl;
	}
}
