#include<bits/stdc++.h>
using namespace std;
 
bool valid(int x, int y, string s[], int n, int m)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
    if(s[x][y] == '#')
        return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    long long int cost[4];
    for(int i = 0; i < 4; i++)
        cin >> cost[i];
    int stx, sty;
    cin >> stx >> sty;
    stx--, sty--;
    priority_queue<pair<long long int,pair<int,int>>, vector<pair<long long int,pair<int,int>>>, greater<pair<long long int,pair<int,int>>>>pq;
    pq.push({0, {stx, sty}});
    long long int dis[n][m];
    int dx[] = {0, 0, -1, 1}, dy[]={-1, 1, 0, 0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis[i][j] = 1000000000000000;
            dis[stx][sty] = 0;
            while(!pq.empty())
            {
                pair<long long int,pair<int,int>> p = pq.top();
                int x = p.second.first, y = p.second.second;
                pq.pop();
                for(int i = 0; i < 4; i++)
                {
                    if(valid(x + dx[i], y + dy[i], s, n, m))
                    {
                        if(dis[x + dx[i]][y + dy[i]] > dis[x][y] + cost[i])
                        {
                            dis[x + dx[i]][y + dy[i]] = dis[x][y] + cost[i];
                            pq.push({dis[x + dx[i]][y + dy[i]], {x + dx[i], y + dy[i]}});
                        }
                    }
                }
            }       
            vector<long long int>v;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    if(dis[i][j] != 1000000000000000)
                        v.push_back(dis[i][j]);
            }
            sort(v.begin(), v.end());
            int q;
            cin >> q;
            while(q--)
            {
                long long int x;
                cin >> x;
                int ind = upper_bound(v.begin(), v.end(), x) - v.begin();
                cout << ind << endl;
            }
}
