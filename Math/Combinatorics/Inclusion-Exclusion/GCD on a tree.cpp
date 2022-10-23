#include<bits/stdc++.h>
using namespace std;
vector<long long> g[1000005];
long long ans[1000005], cnt = 0;
 
void dfs(long long v, long long p, long long gcd) 
{
    if(gcd == 1)
        return;
    ans[gcd]++;
    cnt++;
    for(auto u : g[v]) 
	{
        if(u != p) 
            dfs(u, v, __gcd(gcd, u));
    }
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long t = 1;
    while(t--) 
    {
		long long n;
		cin >> n;
		for(long long i = 1; i <= n - 1; i++) 
		{
			long long u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(long long i = 1; i <= n; i++) 
		{
			cnt = 0;
			dfs(i, -1, i);
			ans[1] += n - cnt;
		}
		for(long long i = 1; i <= n; i++) 
			cout << ans[i] << " ";
		cout << endl;
	}
    return 0;
}
