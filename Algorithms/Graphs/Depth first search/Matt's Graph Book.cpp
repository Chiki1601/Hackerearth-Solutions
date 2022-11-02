#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int vis[100001], col[20000], cnt, cc_size, maxD, max_node;
 
void dfs(int node)
{
    vis[node] = 1;
    for(int child : arr[node])
    {
        if(vis[child] == 0)
            dfs(child);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, x;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    cin >> x;
    vis[x] = 1;
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1)
        cout << "Connected" << endl;
    else
        cout << "Not Connected" << endl;
}
