#include<bits/stdc++.h>
using namespace std;
map<int,int>col[100001];
int par[100001], R[100001];
 
int find(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=find(par[n]);
}
 
void merge(int a, int b)
{
    if(R[a] < R[b])
        swap(a, b);
    par[b] = a;
    map<int, int>::iterator it = col[b].begin();
    while(it != col[b].end())
    {
        col[a][it->first]++;
        it++;
    }
    R[a] += R[b];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        col[i][c]++;
    }
    pair<int, int>edges[m + 1], queries[q];
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }
    bool freq[m + 1];
    memset(freq, true, sizeof(freq));
    for(int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        queries[i] = make_pair(u, v);
        if(u == 1)
            freq[v] = false;
    }
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        R[i] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        if(freq[i])
        {
            int a = edges[i].first, b = edges[i].second;
            a = find(a), b = find(b);
            if(a != b)
            merge(a, b);
        }
    }
    int ans[q];
    memset(ans, -1, sizeof(ans));
    for(int i = q - 1; i >= 0; i--)
    {
        int x = queries[i].first, y = queries[i].second;
        if(x == 2)
        {
            int b = find(y);
            ans[i] = col[b].size();
        }
        else
        {
            x = edges[y].first, y = edges[y].second;
            x = find(x), y = find(y);
            if(x != y)
                merge(x, y);
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(ans[i] != -1)
            cout << ans[i] << endl;
    }
}
