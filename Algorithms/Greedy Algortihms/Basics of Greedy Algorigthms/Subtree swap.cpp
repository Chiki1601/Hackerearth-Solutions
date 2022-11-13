#include<bits/stdc++.h>
using namespace std;
 
void dfs(long long int s, vector<long long int>*adj, long long int p, long long int &t, vector<long long int>&temp, vector<long long int>&first, vector<long long int>&last)
{
    first[s] = t++;
    temp.push_back(s);
    for(auto k : adj[s])
    {
        if(k != p)
            dfs(k, adj, s, t, temp, first, last);
    }
    last[s] = t++;
    temp.push_back(s);
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int n, a, b;
        cin >> n;
        vector<long long int> cost(n + 1), first(n + 1), last(n + 1), temp;
        temp.push_back(0);
        vector<long long int> pre(2 * n + 1, 0), adj[n + 1];
        for(long long int i = 1; i <= n; i++)
            cin >> cost[i];
        for(long long int i = 1; i < n; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        a = 1;
        dfs(1, adj, -1, a, temp, first, last);
        for(long long int i = 1; i <= 2 * n; i++)
            pre[i] = pre[i - 1] + cost[temp[i]];
        long long int q;
        cin >> q;
        while(q--)
        {
            long long int u, v, x;
            cin >> u >> v >> x;
            if(first[u] > last[v] || first[v] > last[u])
            {
                bool check1 = false, check2 = false;
                if(first[u] > first[x] && first[u] < last[x])
                    check1 = true;
                if(first[v] > first[x] && first[v] < last[x])
                    check2 = true;
                if(check1 == check2)
                {
                    long long int a = first[x], b = last[x];
                    cout << (pre[b] - pre[a - 1]) / 2 << " ";
                }
                else if(check1 == true)
                {
                   long long int sum = pre[last[x]] - pre[first[x] - 1] - (pre[last[u]] - pre[first[u] - 1]) + (pre[last[v]] - pre[first[v] - 1]);
                    cout << sum / 2 << " ";
                }
                else
                {
                    long long int sum = pre[last[x]] - pre[first[x] - 1] - (pre[last[v]] - pre[first[v] - 1]) + (pre[last[u]] - pre[first[u] - 1]);
                    cout << sum / 2 << " ";
                }
            }
            else
            {
                long long int a = first[x], b = last[x];
                cout << (pre[b] - pre[a - 1]) / 2 << " ";
            }
        }
        cout << endl;
    }
}
