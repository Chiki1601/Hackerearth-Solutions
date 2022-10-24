#include <bits/stdc++.h>
using namespace std;
int logn;
vector<int> level;
vector<vector<int>> par;
 
int lca(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);
    int d = level[b] - level[a];
    for (int i = logn - 1; ~i; --i)
        if (d >> i & 1)
            b = par[b][i];
    if (a == b)
        return a;
    for (int i = logn - 1; ~i; --i)
        if (par[a][i] != par[b][i])
            a = par[a][i], b = par[b][i];
    return par[a][0];
}
 
int dis(int a,int b) 
{
    return level[a] + level[b] - 2 * level[lca(a, b)];
}
 
void solve() 
{
    int q;
    cin >> q;
    int N = 2 * q + 5;
    logn = log(N) + 1;
    level.clear(), level.resize(N);
    par.clear(), par.resize(N, vector<int>(logn));
    int n = 1, d1 = 1, d2 = 1, dia = 0;
    while(q--) 
	{
        int k, x;
        cin >> k >> x;
        if(k == 1) 
		{
            ++n;
            level[n] = level[x] + 1;
            par[n][0] = x;
            for (int i = 1; i < logn; ++i)
                par[n][i] = par[par[n][i - 1]][i - 1];
            int nd = dis(d1, n);
            if (dia < nd) 
				d2 = n, dia = nd;
            if (d2 != n) 
			{
                nd = dis(d2, n);
                if (dia < nd) 
					d1 = n, dia = nd;
            }
        } 
		else
            cout << max(dis(d1, x), dis(d2, x)) << endl;
    }
}
 
int main() 
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t; 
	cin >> t; 
	while(t--)
        solve();
	return 0;
}
