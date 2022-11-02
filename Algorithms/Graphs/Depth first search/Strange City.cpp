#include <bits/stdc++.h>
using namespace std;
long long int cost[100005];
vector<int> adj[100005], tree[4000020];
int start[100005], end_[100005], time_[100005], vis[100005], k = 0;
 
void dfs(int src)
{
    vis[src] = 1; 
    k++;
    time_[k] = src;
    start[src] = k;
    for(auto i : adj[src])
    {
        if(!vis[i])
            dfs(i);
    }
    end_[src] = k;
}
 
void build(int n, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[n].push_back(cost[time_[l]]);
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * n, l, mid);
    build(2 * n + 1, mid + 1, r);
    merge(tree[2 * n].begin(), tree[2 * n].end(), tree[2 * n + 1].begin(), tree[2 * n + 1].end(), back_inserter(tree[n]));
}
 
long long int query(int n, int l, int r, int k, int strt, int en)
{
    if(strt > r || en < l)
        return 0;
    if(strt >= l && en <= r)
    {
        if(tree[n].size() == 0)
            return 0;
        long long int pos = lower_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
       return (tree[n].size() - pos);
    }
    int mid = (en + strt) / 2;
    long long int t1 = query(2 * n, l, r, k, strt, mid), t2 = query(2 * n + 1, l, r, k, mid + 1, en);
    return (t1 + t2);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, d, u, v;
    cin >> n >> q >> d;
    for(int i = 1; i <= n; i++)
    {
        cin >> cost[i]; 
        vis[i] = 0;
    }
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(d);
    build(1, 1, n);
    long long int last = 0;
	while(q--)
    {
        long long int r, x, y;
        cin >> r >> x >> y;
        r = r ^ last;
        x = x ^ last;
        y = y ^ last;
        long long int lo = x - cost[r] - cost[d], up = y - cost[r] - cost[d];
        last = query(1,start[r]+1,end_[r],lo,1,n) - query(1, start[r] + 1, end_[r], up + 1, 1, n);
        cout << last << endl;
    }
}
