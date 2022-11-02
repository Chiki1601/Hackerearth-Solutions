#include<bits/stdc++.h>
using namespace std;
vector<int>graph[200005];
int val[200005], in[200005], out[200005], ticks, MAP[400005], trie[12400000][2], nn, root[2][400005];
long long sum;
 
int INSERT(int v, int pre)
{
    int i, ret = ++nn, t = nn;
    bool bit;
    for(i = 29; i >= 0; --i)
    {
        bit = (v & (1 << i));
        trie[t][0] = trie[pre][0];
        trie[t][1] = trie[pre][1];
        trie[t][bit] = ++nn;
        t = trie[t][bit];
        pre = trie[pre][bit];
    }
    return ret;
}
 
int SEARCH(int t, int v)
{
    int i, ans = 0;
    bool bit;
    for(i = 29; i >= 0; --i)
    {
        bit = (v & (1 << i));
        if(trie[t][bit ^ 1])
        {
            ans |= (1 << i);
            t = trie[t][bit ^ 1];
        }
        else
            t = trie[t][bit];
    }
    return ans;
}
 
int dfs(int u, int p)
{
    in[u] = ++ticks;
    MAP[ticks] = u;
    int ret = val[u];
    for(auto z : graph[u])
        if(z != p)
            ret ^= dfs(z,u);
    val[u] = ret;
    out[u] = ++ticks;
    MAP[ticks] = u;
    return ret;
}
 
void dfs1(int u, int p, int mx)
{
    if(u != 1)
    {
        int ans = mx;
        ans = max(ans, SEARCH(root[0][in[u] - 1], val[u]));
        ans = max(ans, SEARCH(root[1][out[u] + 1], val[u]));
        sum += ans;
    }
    for(auto z : graph[u])
        if(z != p)
            dfs1(z, u, max(val[u], mx));
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, i, u, v;
    cin >> N;
    for(i = 1; i <= N; ++i)
        cin >> val[i];
    for(i = 1; i < N; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for(i = 1; i <= ticks; ++i)
    {
        if(out[MAP[i]] == i)
            root[0][i] = INSERT(val[MAP[i]], root[0][i - 1]);
        else
            root[0][i] = root[0][i - 1];
    }
    for(i = ticks; i >= 1; --i)
    {
        if(in[MAP[i]] == i)
            root[1][i] = INSERT(val[MAP[i]], root[1][i + 1]);
        else
            root[1][i] = root[1][i + 1];
    }
    dfs1(1, 0, 0);
    cout << sum;
    return 0;
}
