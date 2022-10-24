#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    long long int vis[1002], dis[1002], n, m, k, x, y, c; 
    while(t--)
    {
        vector<long long int>v[1002], r[1002];
        for(int i = 0; i < 1002; i++) 
        {
            v[i].clear();
            r[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 1002; i++) 
            dis[i] = 1000000000000000LL;
        cin >> n >> m >> k;
        while(m--)
        {
            cin >> x >> y >> c;
            v[x].push_back(y);
            r[x].push_back(c);
            v[y].push_back(x);
            r[y].push_back(c);
        }
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>>q;
        q.push(pair<long long int, long long int>(0, 1));
        dis[1] = 0;
        while(!q.empty())
        {
            pair<long long int, long long int> p = q.top(); q.pop();
            long long int d = p.first, in = p.second;
            if(dis[in] < d) 
                continue;
            if(in <= k)
            {
                vis[in] = 1;
                for(int i = 0; i < v[in].size(); i++)
                {
                    long long int u = v[in][i];
                    c = r[in][i];
                    if(vis[u] == 0 && dis[u] > c)
                    {
                        dis[u] = c;
                        q.push(pair<long long int, long long int>(c, u));
                    }
                }
            }
            else
            {
                for(int i = 0; i < v[in].size(); i++)
                {
                    long long int u = v[in][i];
                    c = r[in][i];
                    if(vis[u] == 0 && dis[u] > dis[in] + c)
                    {
                        dis[u] = dis[in] + c;
                        q.push(pair<long long int, long long int>(dis[u], u));
                    }
                }
            }
        }
        long long int sum = 0;
        for(int i = 1; i <= k; i++) 
            sum += dis[i];
        cout << sum << endl;  
    }
    return 0;
}
