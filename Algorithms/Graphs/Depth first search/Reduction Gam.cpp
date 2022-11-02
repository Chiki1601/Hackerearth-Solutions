#include <bits/stdc++.h>
using namespace std;
int n, a[10239];
long long c1, c2;
bool used[10239];
map<int, int> id;
 
void dfs(int p)
{
    used[p] = true;
    for(int i = 0; i < 30; i++)
    {
        int r = (1 << i) ^ a[p];
        if(id.find(r) == id.end()) 
            continue;
        r = id[r];
        if(!used[r]) 
            dfs(r);
    }
}
 
void dfs2(int p)
{
    used[p] = true; 
    for(int i = 0; i < n; i++)
        if(!used[i] && __builtin_popcount(a[i] ^ a[p]) > 1)
            dfs2(i);
}
 
void solve()
{
    cin >> n >> c1 >> c2;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if(c2 <= c1)
    {
        if(n > 100) 
        {
            cout << (long long)c2 * (long long)(n - 1) << endl;
            return;
        }
        for(int i = 0; i < n; i++) 
            used[i] = false;
        long long w = -1;
        for(int i = 0; i < n; i++)
            if(!used[i])
            {
                w++;
                dfs2(i);
            }
        cout << w * (long long)c1 + (long long)(n - 1 - w) * (long long)c2 << endl;
        return;
    }
    id.clear();
    for(int i = 0; i < n; i++) 
        id[a[i]] = i;
    for(int i = 0; i < n; i++) 
        used[i] = false;
    long long w = -1;
    for(int i = 0; i < n; i++)
        if(!used[i])
        {
            w++;
            dfs(i);
        }
    cout << w * (long long)c2 + (long long)(n - 1 - w) * (long long)c1 << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) 
        solve();
    return 0;
}
