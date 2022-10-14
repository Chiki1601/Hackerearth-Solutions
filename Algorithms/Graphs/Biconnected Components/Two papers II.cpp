#include<bits/stdc++.h>
using namespace std;
vector<long long int> g[300001];
bool vis[300001];
 
void fun(long long int u)
{
	vis[u] = 1;
	for(long long int i = 0; i < g[u].size(); i++)
    {
		long long int v = g[u][i];
		if(!vis[v])
			fun(v);
	}
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int t = 1, cnt = 0; 
    while(t--)
    {
		long long int n, m, va = 0;
		cin >> n >> m;
		for(long long int i = 1; i <= m; i++)
        {
			long long int u, v, w;
			cin >> u >> v >> w;
			if(w == 0) 
            {
                g[u].push_back(v); 
                g[v].push_back(u);
            }
			else 
                va++;
		}
		bool foo = 0;
		for(long long int i = 1; i <= n; i++)
        {
			if(!vis[i])
            {
				cnt++;
				fun(i);
			}
		}
		if(cnt % 2 == 0) 
            foo = 1;
		else
        {
			if(va > cnt - 1) 
                foo = 1;
		}
		if(foo) 
            cout << "YES" << endl;
		else 
            cout << "NO" << endl;
	}
    return 0;  
}
