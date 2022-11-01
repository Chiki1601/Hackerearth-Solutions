#include <bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int in[100005], out[100005], c1, c2;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        out[u]++;
        in[v]++;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(in[i] == 0)
            c1++;
    for(int i = 1; i <= n; i++)
        if(out[i] == 0)
            c2++;  
    cout << max(c1, c2) << endl;
    return 0;
}
