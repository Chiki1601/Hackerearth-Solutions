#include <bits/stdc++.h>
using namespace std;
int n, m, fa[1000014];
 
int root(int u)
{
    if(fa[u] == u) 
        return u;
    return fa[u] = root(fa[u]);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> e[31];
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        r = 2 * n - r + 1;
        for(int i = 30; i >= 0; --i)
            if((1 << i) <= len)
                e[i].push_back({l, r}), l += (1 << i), r += (1 << i), len -= (1 << i);
    }
    for(int k = 30; k >= 0; --k)
    {
        for(int i = 1; i <= 2 * n; ++i) 
            fa[i] = i;
        for(auto it : e[k]) 
            fa[root(it.first)] = root(it.second);
        if(k == 0) 
            break;
        for(int u = 1; u <= 2 * n; ++u)
        {
            int ru = root(u), np = (1 << (k - 1));
            if (u != ru)
                e[k - 1].push_back({u, ru}), e[k - 1].push_back({u + np, ru + np});
        }
    }
    for(int i = 1; i <= n; ++i) 
        fa[root(i)] = root(2 * n - i + 1);
    set<int> s;
    for(int i = 1; i <= 2 * n; ++i) 
        s.insert(root(i));
    cout << s.size();
    return 0;
}
