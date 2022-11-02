#include<bits/stdc++.h>
using namespace std;
string pr;
 
long long int dfs(long long int node, long long int par, vector<long long int>adj[])
{
    long long int dis = 1;
    for(auto u : adj[node])
	{
        if(u == par) 
			continue;
        dis -= dfs(u, node, adj);
    }
    if(dis < 0 || (dis == 1 && node == 0))
        pr = "SAFE";
    return dis;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
	cin >> t; 
	while(t--)
    {
        long long int n, l, r; 
		cin >> n;
        vector<long long int>adj[n];
        for(long long int i = 1; i < n; i++)
		{
            cin >> l >> r; 
			l--; 
			r--;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        pr = "UNSAFE";
        dfs(0, -1, adj);
        cout << pr << endl;
    }
    return 0;
}
