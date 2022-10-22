#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> mp[32];
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        long x;
        cin >> x;
        for(int j = 0; j < 32; j++)
        {
            if(x % 2) 
                mp[j].push_back(i + 1);
                x /= 2;
        }
    }
    for(int i = 0; i < q; i++)
    {
        int l, r, val;
        cin >> l >> r >> val;
        for(int j = 0; j < 32; j++)
        {
            if(val % 2 == 0)
            {
                auto it1 = lower_bound(mp[j].begin(), mp[j].end(), l);
                auto it2 = lower_bound(mp[j].begin(), mp[j].end(), r + 1);
                if(it1 != it2) 
                    mp[j].erase(it1, it2);
            }
            val /= 2;
        }
    }
    int ans[n + 5];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 32; i++)
    {
        auto it = mp[i].begin();
        for(; it != mp[i].end(); ++it) 
            ans[*it] += (pow(2, i));
    }
    for(int i = 1; i <= n; i++) 
        cout << ans[i] << " ";
    return 0;
}
