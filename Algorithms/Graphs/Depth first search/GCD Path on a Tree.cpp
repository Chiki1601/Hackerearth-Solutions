#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> dp[100009];
vector<int> pf[1000009], al[100009];
int n, k, ans, val[100009], mx[100009];
 
void primeFactors(vector<int> v[], int n)
{
    for(int i = 2; i <= n; i++)
	{
        if(v[i].empty())
		{
            for(int j = i; j <= n; j += i)
                v[j].push_back(i);
        }
    }
}
 
bool inline check(int v, int p, int m)
{
    if(dp[v].find(p) == dp[v].end() || dp[v][p][m] == -1)
		return 0;
    return 1;
}
 
void calc(int v, int p)
{
    map<int, vector<int>> bst_mp;
    int bst = 0;
    vector<int> &factors = pf[val[v]];
    mx[v] = 0;
    for(int i = 0; i < (int)factors.size(); i++)
	{
        int prime = factors[i];
        dp[v][prime] = vector<int>(k + 1, -1);
        bst_mp[prime] = vector<int>(k + 1, -1);
        dp[v][prime][1] = 1;
        if(k == 1)
			dp[v][prime][k] = mx[v] = 1;
    }
    for(int i = 0; i < (int)al[v].size(); i++)
	{
        int u = al[v][i];
        if(u == p)
			continue;
        for(int j = 0; j < (int)factors.size(); j++)
		{
            int prime = factors[j];
            dp[v][prime][1] = max(dp[v][prime][1], mx[u] + 1);
            for(int m = 2; m <= k; m++)
			{
                if(!check(u, prime, m - 1))
					continue;
                dp[v][prime][m] = max(dp[v][prime][m], dp[u][prime][m - 1] + 1);
            }
            mx[v] = max(mx[v], dp[v][prime][k]);
        }
        if(k == 1)
			ans = max(ans, bst + 1 + mx[u]);
        else
		{
            for(int j = 0; j < (int)factors.size(); j++)
			{
                int prime = factors[j];
                if(bst_mp[prime][k - 1] != -1)
					ans = max(ans, bst_mp[prime][k - 1] + 1 + mx[u]);
                if(check(u, prime, k - 1))
					ans = max(ans, bst + 1 + dp[u][prime][k - 1]);
                for(int m = 1; m <= k - 2; m++)
				{
                    if(bst_mp[prime][k - m - 1] != -1 && check(u, prime, m))
                        ans = max(ans, bst_mp[prime][k - m - 1] + 1 + dp[u][prime][m]);
                }
            }
            for(int j = 0; j < (int)factors.size(); j++)
			{
                int prime = factors[j];
                for(int m = 1; m <= k; m++)
				{
                    if(check(u, prime, m))
						bst_mp[prime][m] = max(bst_mp[prime][m], dp[u][prime][m]);
                }
            }
        }
        bst = max(bst, mx[u]);
    }
    ans = max(ans, mx[v]);
}
 
void dfs(int v, int p)
{
    for(int i = 0; i < (int)al[v].size(); i++)
	{
        int u = al[v][i];
        if(u == p)
			continue;
        dfs(u, v);
    }
    calc(v, p);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 1000009; i++)
		pf[i].clear();
    primeFactors(pf, 1000008);
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
		al[i].clear();
    for(int i = 0; i < n - 1; i++)
	{
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
		cin >> val[i];
    ans = 0;
    dfs(1, 0);
    cout << ans << endl;
}
