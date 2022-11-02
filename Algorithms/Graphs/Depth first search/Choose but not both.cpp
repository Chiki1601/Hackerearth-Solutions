#include <bits/stdc++.h>
using namespace std;
int n, a[300001], ans = 0, vis[300001];
long long dem[300001];
 
void dfs(int u, int p)
{
    if(vis[u]) 
        return ;
    vis[u] = true;
    if(p == 1) 
        ans++;
    dem[a[u]]--;
    if(!dem[a[u]] || p == 1)
        dfs(a[u], p ^ 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dem[a[i]]++;
    }
    for(int i = 1; i <= n; i++) 
        if(!dem[i]) 
            dfs(i, 1);
    for(int i = 1; i <= n; i++) 
        if(!vis[i]) 
            dfs(i, 0);
    cout << ans;
    return 0;
}
