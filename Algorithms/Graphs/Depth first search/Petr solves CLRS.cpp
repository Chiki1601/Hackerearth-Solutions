#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m, q, co = 0;
    cin >> n >> m;
    long long k;
    cin >> k;
    vector<int> gr[n];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    cin >> q;
    vector<int> vis(n, -1);
    vector<long long> cou(n, 0);
    for(int i = 1; i < q + 1; i++)
    {
        int a;
        cin >> a;
        long long b;
        cin >> b;
        a--;
        if(cou[a] < k)
        {
            cou[a] += b;
            for(auto c : gr[a])
            {
                if(vis[c] == -1)
                {
                    int tot = 0;
                    bool bo = 0;
                    for(auto d : gr[c])
                    {
                        tot += cou[d];
                        if(tot >= k)
                        {
                            bo = 1; 
                            break;
                        }
                    }
                    if(bo)
                    {
                        vis[c] = i;
                        co++;
                    }
                }
            }
        }
        if(co == n)
            break;
    }
    for(int i = 0; i < n; i++)
        cout << vis[i] << " ";
}
