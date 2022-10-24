#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005], node_l[100005];
int max_l;
 
inline int binexp(int a, int b, int m)
{
    if(a == 0) 
        return 0;
    int res = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
            res = (res * 1ll * a) % m;
        a = (a * 1ll * a) % m;
        b>>=1;
    }
    return res;
}
 
inline void dfs(int n, int l) 
{
    for(auto it : g[n]) 
        dfs(it, l + 1);
    max_l = max(max_l, l);
    node_l[l].push_back(n);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int t = 1, a = 1, temp[100005];
    while(t--) 
    {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n - 1; i++)
        {
            int pr;
            cin >> pr;
            g[pr].push_back(i + 2);
        }
        dfs(1, 0);
        int lo = 0, hi = n, ans = -1;
        while(lo <= hi) 
        {
            int mid = (lo + hi) >> 1, cnt = 0;
            fill(temp, temp + n, 0ll);
            for(int i = max_l; i >= 0; i--)
            {
                int flag = 1;
                for(auto nd : node_l[i]) 
                {
                    temp[nd] = 1;
                    for(auto it : g[nd]) 
                        temp[nd] += temp[it];
                    if(temp[nd] > mid) 
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0) 
                {
                    for(auto nd : node_l[i]) 
                        temp[nd] = 0;
                    cnt++;
                }
                if(cnt > k) 
                    break;
            }
            if(cnt <= k) 
            {
                hi = mid - 1;
                ans = mid;
            }
            else 
                lo = mid + 1;
        }
        cout << ans;
        a++;
    }
    return 0;
}
