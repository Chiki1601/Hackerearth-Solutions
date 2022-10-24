#include <bits/stdc++.h>
using namespace std;
int arr[110], ans = -1;
bool chosen[110], vis[110];
vector<int> v[110];
 
void dfs(int index)
{
    vis[index] = true;
    if(!chosen[index]) 
        ans = min(ans, arr[index]);
    for(int i = 0; i < (int)v[index].size(); i++)
    {
        if(vis[v[index][i]]) 
            continue;  
        int e = v[index][i];        
        dfs(e);
    }
}
 
int main()
{
    int n, pos[110];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;        
    }
    char board[110][110];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'Y')
                v[i].push_back(j);
        }
    }
    for(int i = 0; i < n; i++)
    {
        memset(vis, false, sizeof vis);     
        ans = 1000000000;
        dfs(i);
        chosen[pos[ans]] = true;          
        cout << ans << " ";
    }
    return 0;
}
