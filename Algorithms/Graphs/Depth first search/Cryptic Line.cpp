#include<bits/stdc++.h>
using namespace std;
long long n, q, in[200005], out[200005], tim = 0;
vector<long long> g[200005];

void dfs(long long node, long long par)
{
    tim++;
    in[node] = tim;
    for(auto i : g[node])
    {
        if(i != par)
            dfs(i, node);
    }
    tim++;
    out[node] = tim;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(long long i = 1; i < n; i++)
    {
        long long u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    while(q--)
    {
        long long x, y;
        cin >> x >> y;
        if(in[y] > in[x] && out[y] < out[x]) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}

//Method-2
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    cin.tie(0)->sync_with_stdio(0);
    int n, q, timer = 0;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int e = 1, u, v; e < n; ++e) 
    {
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> time_in(n), time_out(n);
    auto dfs = [&](auto self, int v, int p) -> void {
        time_in[v] = ++timer;
        for(int u : g[v]) 
        {
            if(u != p) 
                self(self, u, v);
        }
        time_out[v] = ++timer;
    };
    dfs(dfs, 0, -1);
    auto is_ancestor = [&](int x, int y) 
    {
        if(x == y) 
            return false; 
        return time_in[x] <= time_in[y] && time_out[y] <= time_out[x];
    };
    while(q--) 
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << (is_ancestor(x, y) ? "YES" : "NO") << "\n";
    }
}
