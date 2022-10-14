#include <bits/stdc++.h>
using namespace std;
vector<int>G[207];
int n, m, L[207], R[207], vis[207];
 
bool dfs(int i)
{
    vis[i] = 1;
    for(int j = 0; j < G[i].size(); j++)
    {
        if(R[G[i][j]] == -1)
        {
            R[G[i][j]] = i;
            L[i] = G[i][j];
            return true;
        }
        if(vis[R[G[i][j]]] == 0 && dfs(R[G[i][j]]))
        {
            R[G[i][j]] = i;
            L[i] = G[i][j];
            return true;
        }
    }
    return false;
}
 
int kuhn()
{
    int ans = 0, fl = 0;
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));
    do
    {
        fl = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            if(L[i] == -1)
            {
                bool pp = dfs(i);
                if(pp == true) 
                {
                    ans++;
                    fl = 1;
                }
            }
        }
    }while(fl != 0);
    return ans;
}    
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> n >> m >> k;
    long long int X1[n], Y1[n], X2[m], Y2[m], s[n];
    for(int i = 0; i < n; i++) 
        cin >> X1[i] >> Y1[i];
    for(int i = 0; i < m; i++) 
        cin >> X2[i] >> Y2[i];
    for(int i = 0; i < n; i++) 
        cin >> s[i];
    long long int l = 0, h = 1000000000000000LL, an;
    while(l <= h)
    {
        for(int i = 0; i < n; i++) 
            G[i].clear();
        long long int mid = (l + h) / 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                double ss = s[i] * s[i];
                long long int pp = (X1[i] - X2[j]) * (X1[i] - X2[j]) + (Y1[i] - Y2[j]) * (Y1[i] - Y2[j]);
                long long int ans = ceil(((double)pp) / ss);
                if(ans <= mid) 
                    G[i].push_back(j);
            }
        }
        int ans = kuhn();
        if(ans >= k)
        {
            an = mid;
            h = mid - 1;
        }
        else 
            l = mid + 1;
    }
    cout << an << endl;
    return 0;
}
