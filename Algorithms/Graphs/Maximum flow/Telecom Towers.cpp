#include <bits/stdc++.h>
using namespace std;
 
struct Hopcraft 
{
	vector<vector<pair<int, int>>> g;
	vector<int> odd, fr, first, sat;
	vector<pair<int, int>> p;
	queue<pair<int, int>> q;
	int n, m {}, mat {};
	Hopcraft(int n) : n {n} 
    {
		g.resize(n);
		odd.assign(n, -1);
		p.resize(n);
		fr.assign(n, true);
		first.resize(n);
	}
	void add_edge(int u, int v) 
    {
		g[u].emplace_back(v, m);
		g[v].emplace_back(u, m);
		++m;
	}
	void dfs(int v, int x) 
    {
		if(odd[v] != -1) 
            return;
		odd[v] = x;
		for(auto& edge : g[v]) 
            dfs(edge.first, 1 ^ x);
	}
	bool bfs() 
    {
		bool flag = false;
		fill(first.begin(), first.end(), -1);
		for(int v = 0; v < n; ++v) 
        {
			if(odd[v] || !fr[v]) 
                continue;
			q.push({v, 0});
			p[v] = {v, -1};
			first[v] = v;
		}
		while(!q.empty()) 
        {
			int v = q.front().first, t = q.front().second, w = first[v];
			q.pop();
			if(!fr[w]) 
                continue;
			else if(t && fr[v]) 
            {
				flag = true;
				fr[v] = fr[w] = false;
				++mat;
				for(; ; t ^= 1) 
                {
					int u = p[v].first, e = p[v].second;
					if(u == v) 
                        break;
					sat[e] = t;
					v = u;
				}
				continue;
			}
			for(auto& edge : g[v]) 
            {
				int u = edge.first, e = edge.second;
				if(first[u] != -1 || sat[e] != t) 
                    continue;
				p[u] = {v, e};
				first[u] = w;
				q.push({u, t ^ 1});
			}
		}
		return flag;
	}
	int matching() 
    {
		for(int v = 0; v < n; ++v) 
            dfs(v, 0);
		sat.assign(m, 0);
		while(bfs());	
		return mat;
	}
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--) 
    {
        int n, d;
        cin >> n >> d;
        vector<pair<int, int>> p(n);
        Hopcraft h(n);
        for(auto& v : p) 
            cin >> v.first >> v.second;
        sort(p.begin(), p.end());
        for(int i = 0; i < n; ++i) 
        {
            int x = p[i].first, y = p[i].second;
            for(int z = max(1, x - d); z <= min(200, x + d); ++z) 
            {
                int k = d * d - (x - z) * (x - z);
                int j = sqrt(k);
                if(j * j != k) 
                    continue;
                auto a = lower_bound(p.begin(), p.end(), pair<int, int>(z, y - j));
                auto b = lower_bound(p.begin(), p.end(), pair<int, int>(z, y + j));
                if(a != p.end() && *a == pair<int, int>(z, y - j)) 
                    h.add_edge(i, a - p.begin());
                if(b != p.end() && *b == pair<int, int>(z, y + j)) 
                    h.add_edge(i, b - p.begin());
            }
        }
        cout << h.matching() << endl;
    }
	return 0;
}
