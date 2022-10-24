#include <bits/stdc++.h>
using namespace std;
 
int findset(int a, int parent[])
{
    if(parent[a] == a)
        return a;
    return parent[a] = findset(parent[a], parent);
}
 
void unionset(int a, int b, int parent[])
{
    if(a < b)
        parent[a] = b;
    else
        parent[b] = a;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int I = 1; I <= t; I++)
    {
        int n, p, m;
        cin >> n >> p >> m;
        int parent[n + 1];
        for(int i = 0; i <= n; i++)
            parent[i] = i;
        vector<pair<int, pair<int, int>>>edge, ans;
        while(p--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({c, {a, b}});
        }
        sort(edge.begin(), edge.end());
        for(auto e : edge)
        {
            int a = e.second.first, b = e.second.second;
            if(findset(a, parent) != findset(b, parent))
            {
                unionset(findset(a, parent), findset(b, parent), parent);
                ans.push_back(e);
            }
        }
        vector<pair<int, int>>v[n + 1];
        for(auto e : ans)
        {
            v[e.second.first].push_back({e.second.second, e.first});
            v[e.second.second].push_back({e.second.first, e.first});
        }
        long long int ar[n + 1][n + 1];
        for(int i = 1; i <= n; i++)
        {
            queue<int>q;
            long long int depth[n + 1];
            depth[i] = 0;
            bool visited[n + 1];
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            q.push(i);
            while(!q.empty())
            {
                int f = q.front();
                q.pop();
                for(auto it : v[f])
                {
                    if(visited[it.first])
                        continue;
                    visited[it.first] = true;
                    q.push(it.first);
                    depth[it.first] = depth[f] + it.second;
                }
            }
            for(int j = 1; j <= n; j++)
                ar[i][j] = depth[j];
        }
        cout << "Case: " << I << "\n";
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            cout << ar[a][b] << "\n";
        }
    }
}
