#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<set<int>>& g, set<int>& nodes, int& cnt) 
{
    nodes.erase(u);
    cnt++;
    int curr = 0;
    while(1) 
	{
        auto it = nodes.upper_bound(curr);
        if(it == nodes.end()) 
            break;
        curr = *it;
        if(g[u].find(curr) != g[u].end()) 
            continue;
        dfs(curr, g, nodes, cnt);
    }
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int TEST = 1;
    cin >> TEST;
    for(int i = 1; i <= TEST; i++) 
    {
		int n, m;
		cin >> n >> m;
		vector<set<int>> g(n + 1);
		while(m--) 
		{
			int x, y;
			cin >> x >> y;
			g[x].insert(y);
			g[y].insert(x);
		}
		set<int> nodes;
		for(int i = 1; i < n + 1; ++i) 
			nodes.insert(i);
		vector<int> cmps;
		for(int i = 1; i < n + 1; ++i) 
		{
			if(nodes.find(i) != nodes.end()) 
			{
				int cnt = 0;
				dfs(i, g, nodes, cnt);
				cmps.push_back(cnt);
			}
		}
		sort(cmps.begin(), cmps.end());
		cout << cmps.size() << endl;
		for(auto& it : cmps) 
			cout << it << " ";
		cout << endl;
	}
    return 0;
}
