#include<bits/stdc++.h>
using namespace std;

int find(int n, vector<int>& par)
{
    if(par[n] < 0)
        return n;
    return par[n] = find(par[n], par);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, cnt = 0;
    cin >> n >> m >> q;
    vector<int> par(n * m , -1);
    vector<vector<int>> vis(n , vector<int>(m , 0));
    while(q--)
    {
        int code;
        cin >> code;
        if(code == 1)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if(vis[x][y] == 1)
                continue;
            vis[x][y] = 1;
            vector<int>neigh;
            for(int i = 0 ; i < 4 ; i++)
            {
                if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && vis[x + dx[i]][y + dy[i]])
                    neigh.push_back(m * (x + dx[i]) + y + dy[i]);
            }
            cnt++;
            bool f = true;
            for(auto it : neigh)
            {
                int u = find(it, par), v = find(m * x + y, par);
                if(u != v)
                {
                    cnt--;
                    par[u] = v;
                }
            }
        }
        else
            cout << cnt << "\n";
    }
}
