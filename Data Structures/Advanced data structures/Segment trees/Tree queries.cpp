#include <bits/stdc++.h>
using namespace std;
long long int a[200001], dis[200001];
vector<long long int>v[200001];
 
void dfs(long long int root, long long int par, long long int dist) 
{
	dis[root] = dist;
	for(auto a : v[root])
		if(a != par)
			dfs(a, root, dist + 1);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long int t = 1;
	cin >> t;
	while(t--)
	{
        long long int n, q, max_dis = 0;
        cin >> n;
        for(long long int i = 1; i <= n; i++)
        {
            cin >> a[i]; 
            v[i].clear(); 
            dis[i] = 0;
        }
        for(long long int i = 0; i < n - 1; i++) 
        {
            long long int u, x;
            cin >> u >> x;
            v[x].push_back(u);
            v[u].push_back(x);
        }
        cin >> q;
        dfs(1, -1, 0);
        for(long long int i = 1; i <= n; i++)
            max_dis = max(max_dis, dis[i]);
        long long int s[max_dis + 1];
        memset(s, 0, sizeof(s));
        for(long long int i = 1; i <= n; i++)
            s[dis[i]] = max(s[dis[i]], a[i]);
        while(q--) 
        {
            long long int f; 
            cin >> f;
            if(f == 1) 
            {
                long long int u, x;
                cin >> u >> x;
                a[u] += x;
                s[dis[u]] = max(s[dis[u]], a[u]);
            }
            else 
            {
                long long int p, f = -1;
                cin >> p;
                for(long long int i = 0; i <= max_dis; i++) 
                {
                    if(s[i] > p) 
                    {
                        f = i;
                        break;
                    }
                }
                cout << f << endl;
            }
        }
    }
}
