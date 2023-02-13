#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> a;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                a.push_back({x, i, j});
            }
        }
        sort(a.rbegin(), a.rend());
        int k = a.size();
        vector<int> dp(k), dp1(n), dp2(m);
        dp[0] = 1;
        dp1[a[0][1]] = 1;
        dp2[a[0][2]] = 1;
        for(int i = 1; i < k; i++)
        {
            dp[i] = 1 + max(dp1[a[i][1]], dp2[a[i][2]]);
            dp1[a[i][1]] = dp[i];
            dp2[a[i][2]] = dp[i];
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;         
    }      
    return 0;
}
