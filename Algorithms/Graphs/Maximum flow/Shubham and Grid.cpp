#include<bits/stdc++.h>
using namespace std;
int l[405], ptr[405], rr[] = {0, 0, -1, 1}, cc[] = {-1, 1, 0, 0};
 
struct cou
{
    int f, s, c;
};
 
bool bfs(vector<vector<int>>&v, vector<cou>&ed, int s, int t)
{
    l[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(auto &i : v[f])
        {
            int b = ed[i].s;
            if(l[b] == -1 and ed[i].c)
            {
                l[b] = l[f] + 1;
                q.push(b);
            }
        }
    }
    return l[t] != -1;
}
 
int dfs(int s, vector<vector<int>>&v, vector<cou>&ed, int t, int mx)
{
    if(mx == 0 or s == t) 
        return mx;
    for(int &h = ptr[s]; h < v[s].size(); h++)
    {
        int i = v[s][h], b = ed[i].s;
        if(l[b] == l[s] + 1 and ed[i].c)
        {
            int temp = dfs(b, v, ed, t, min(mx, ed[i].c));
            ed[i].c -= temp;
            ed[i^1].c += temp;
            if(temp) 
                return temp;
        }
    }
    return 0;
}
 
void add(vector<vector<int>>&v, vector<cou>&ed, int s, int t)
{
    v[s].push_back(ed.size());
    ed.push_back({s, t, 1});
    v[t].push_back(ed.size());
    ed.push_back({t, s, 0});
}
 
void find(int x, int y, vector<vector<char>>&v, vector<vector<int>>&g, vector<cou>&ed)
{
    int n = v.size(), m = v[0].size();
    for(int h = 0; h < 4; h++)
    {
        int f = rr[h] + x, s = cc[h] + y;
        if(f >= 0 and f < n and s < m and s >= 0 and v[f][s] == v[x][y] + 1)
            add(g, ed, x * m + y, f * m + s);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int s = n * m;
    int t = s + 1, ans = 0;
    vector<vector<int>>v(n * m + 2);
    vector<cou>ed;
    vector<vector<char>>g(n, vector<char>(m));
    for(int h = 0; h < n; h++)
    {
        for(int j = 0; j < m; j++)
            cin >> g[h][j];
    }
    for(int h = 0; h < n; h++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[h][j] == 'd')
            {
                add(v, ed, h * m + j, t);
                continue;
            }
            if(g[h][j] == 'a')
                add(v, ed, s, h * m + j);
            find(h, j, g, v, ed);
        }
    }
    memset(l, -1, sizeof(l));
    while(bfs(v, ed, s, t))
    {
        memset(ptr, 0, sizeof(ptr));
        int res = 0;
        while(res = dfs(s, v, ed, t, INT_MAX))
            ans += res;
        memset(l, -1, sizeof(l));
    }
    cout << ans << endl;
}
