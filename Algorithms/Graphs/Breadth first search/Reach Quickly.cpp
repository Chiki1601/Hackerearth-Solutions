#include <bits/stdc++.h> 
using namespace std; 

template<typename T> istream& operator>>(istream& s, vector<T>& self) 
{ 
    for(size_t i = 0; i < self.size(); ++i)  
        s >> self[i];  
    return s; 
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t; 
    while(t--)
    {
        int n, m, x, y, ans = 0;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin >> x >> y;
        vector<int> a(x), b(y), inB(n, 0);
        cin >> a >> b;
        vector<long long int> dist(n, 1000000000);
        long long int val = 0;
        for(auto e : b)
        {
            val += dist[e]; 
            inB[e] = 1;
        }
        long long int sum = val;
        queue<pair<int, int>> que;
        for(int i = 0, u, d; i < x; i++)
        {
            que.push({a[i], 0});
            while(que.size())
            {
                u = que.front().first;
                d = que.front().second;
                que.pop();
                if(inB[u])      
                    sum -= dist[u] - d;
                dist[u] = d;
                for(auto v : graph[u])
                {
                    if(dist[v] <= d + 1)      
                        continue;
                    que.push({v, d + 1});
                }
            }
            if(sum < val)
            {
                val = sum;
                ans = i;
            }
        }
        cout << ans << endl;
    }
}
