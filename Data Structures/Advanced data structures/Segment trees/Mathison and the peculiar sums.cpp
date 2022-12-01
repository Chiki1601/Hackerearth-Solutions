#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int n, curr, val[100005], _rank[100005], ans[100005];
 
typedef struct $
{
    int cnt, sum_o, sum_e;
} Node;
Node tree[400020];
 
void update(int node, int l, int r, int idx, int adder)
{
    if(l == r)
	{
        tree[node].cnt = adder;
        tree[node].sum_e = adder * val[idx];
        tree[node].sum_o = 0;
        return;
    }
    int m = (l + r) >> 1;
    (_rank[idx] <= m) ? update(2 * node, l, m, idx, adder) : update(2 * node + 1, m + 1, r, idx, adder);
    tree[node].cnt = tree[2 * node].cnt + tree[2 * node + 1].cnt;
    if(tree[2 * node].cnt & 1)
	{
        tree[node].sum_e = (tree[2 * node].sum_e + tree[2 * node + 1].sum_o) % 1000000007;
        tree[node].sum_o = (tree[2 * node].sum_o + tree[2 * node + 1].sum_e) % 1000000007;
    }
    else
	{
        tree[node].sum_e = (tree[2 * node].sum_e + tree[2 * node + 1].sum_e) % 1000000007;
        tree[node].sum_o = (tree[2 * node].sum_o + tree[2 * node + 1].sum_o) % 1000000007;
    }
    return;
}
 
void dfs(int start, int parent = 0)
{
    update(1, 1, n, start, 1);
    ans[start] = (1ll * tree[1].sum_o * tree[1].sum_e) % 1000000007;
    for(auto next : v[start])
        if(next != parent)
            dfs(next, start);
    update(1, 1, n, start, 0);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, a, b;
    cin >> n;
	pair<int, int> M[100005];
    for(i = 0; i < n; i++)
	{
        cin >> val[i + 1];
        M[i] = {val[i + 1], i + 1};
    }
    sort(M, M + n);
    for(i = 0; i < n; i++)
        _rank[M[i].second] = ++curr;
    for(i = 1; i < n; i++)
	{
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(i = 1; i <= n; i++)
    	cout << ans[i] << endl;
    return 0;
}
