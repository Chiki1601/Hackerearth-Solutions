#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edgelist;
vector<int> par;
 
bool dfs(int i, map<int, bool> &m)
{
    for(auto child : edgelist[i])
    {
        if(m.find(child) == m.end())
        {
            m[child] = true;
            if(par[child] == -1 || dfs(par[child], m))
            {
                par[child] = i;
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    int n, m, a, ans = 0;
    cin >> n >> m;
    edgelist.assign(n, {});
    par.assign(m + 1, -1);
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        for(int j = 1; j * j <= a; ++j)
        {
            if(a % j == 0)
            {
                if(j <= m) 
                    edgelist[i].push_back(j);
                if(a / j != j && a / j <= m) 
                    edgelist[i].push_back(a / j);
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        map<int, bool> m;
        if(dfs(i, m))  
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
