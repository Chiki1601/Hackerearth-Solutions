#include <bits/stdc++.h>
using namespace std;
vector<int> g[1028196];
int id[1014][1014], in[1028196], d[1028196];
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) 
	{
        int p = -1;
        for(int j = 0; j < n - 1; ++j) 
		{
            int o;
            cin >> o;
            --o;
            if(!id[i][o])
                id[i][o] = id[o][i] = cnt++;
            if(p != -1) 
			{
                g[id[i][o]].push_back(p);
                ++in[p];
            }
            p = id[i][o];
        }
    }
    memset(d, 63, sizeof d);
    queue<int> q;
    for(int i = 0; i < cnt; ++i)
        if(!in[i]) 
		{
            d[i] = 0;
            q.push(i);
        }
    while(!q.empty()) 
	{
        int v = q.front();
        q.pop();
        for(auto u : g[v])
            if(!--in[u]) 
			{
                d[u] = d[v] + 1;
                q.push(u);
            }
    }
    int ans = *max_element(d, d + cnt);
    cout << (ans > 1000000000 ? -1 : ans * 3 + 3);
}
