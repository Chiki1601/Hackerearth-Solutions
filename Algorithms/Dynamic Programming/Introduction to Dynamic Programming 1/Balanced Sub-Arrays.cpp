#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t; 
    cin >> t;
    while(t--)
    {               
        long long int n, prevEven = 0, ans = 1; 
        cin >> n;
        vector<long long int> a(n);
        for(long long int i = 0; i < n; i++)
            cin >> a[i];
        if(a[0] & 1)
            prevEven = -1;
        vector<vector<long long int>> dp(n + 1, vector<long long int>(2, 0));
        dp[0][a[0] % 2] = 1;
        for(long long int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][a[i] % 2] + ((a[i] % 2) ^ 1);
            dp[i][1] = dp[i - 1][(a[i] % 2) ^ 1] + (a[i] % 2);
            if(!(a[i] & 1))
                prevEven = i;
            if(prevEven != -1)
                ans += dp[prevEven][(i - prevEven) % 2];
            ans += (i - prevEven + 1) / 2;
        }
        cout << ans << endl;
    }   
    return 0;
}
