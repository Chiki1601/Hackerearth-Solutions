#include <bits/stdc++.h>
using namespace std;
int n, m, d[1003];
vector<int> a[1003];
 
void dfs(int u, int p) 
{
    for (int v : a[u]) 
    {
        if (d[v] > d[u] + 1) 
        {
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        d[i] = 1000000000;
    d[1] = 0;
    while(m--) 
    {
        int type, x, y;
        cin >> type;
        if (type == 1) 
        {
            cin >> x;
            if (d[x] == 1000000000) 
                cout << -1 << endl;
            else 
                cout << d[x] << endl;
        }
        else 
        {
            cin >> x >> y;
            a[x].push_back(y);
            if (d[y] > d[x] + 1) 
            {
                d[y] = d[x] + 1;
                dfs(y, -1);
            }
        }
    }
}
