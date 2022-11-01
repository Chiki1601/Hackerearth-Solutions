#include <bits/stdc++.h> 
using namespace std;
bool dp[111][1000001];
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    t = 1;
    while(t--)
    {
        int l, n, x, y, q, mn = INT_MAX, mx = INT_MIN;
        cin >> l >> n >> x >> y;
        memset(dp, 0, sizeof(dp));
        dp[0][l] = true;
        int A[n + 1];
        for(int i = 1; i <= n; ++i) 
            cin >> A[i];
        for(int i = 1; i <= n; ++i)
        {
            for(int j = x; j <= y; ++j)
            {
                if(j - A[i] >= x)
                    dp[i][j] |= dp[i - 1][j - A[i]];
                if(j + A[i] <= y)
                    dp[i][j] |= dp[i - 1][j + A[i]];
            }
        }
        for(int j = x; j <= y; ++j)
        {
            if(dp[n][j])
                mx = max(mx, j);
                mn = min(mn, j);
        }
        cin >> q;
        while(q--)
        {
            char op; 
            int m;
            cin >> op >> m;
            op == '<' ? (m <= mn ? cout << "NO" : cout << "YES") : (m >= mx ? cout << "NO" : cout << "YES");
            cout << endl;
        }
    }
    return 0;
}
