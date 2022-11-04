#include<bits/stdc++.h>
using namespace std;
int dp[2][1024];
 
int solve (vector<int> a) 
{
    memset(dp,0,sizeof(dp));
    int m = INT_MIN;
    for(int i = 0; i < a.size(); i++)
    {  
        int ind = i & 1, prev = ind ^ 1;
        for(int j = 0; j < 1024; j++)
        dp[ind][j] = dp[prev][j];
        for(int j = 0; j < 1024; j++)
        {
            if(dp[prev][j])
                dp[ind][a[i] ^ j] = max(dp[ind][a[i] ^ j], 1 + dp[prev][j]);
        }
        dp[ind][a[i]] = max(dp[ind][a[i]], 1);
        m = max(m, a[i]);
    }
    long long int ans = 0,temp = 129032259;
    for(int i = 0; i <= m; i++)
    {
        temp = (temp * 31) % 1000000007;
        ans = (ans + (temp * dp[a.size() & 1 ^ 1][i])) % 1000000007;
    }
    return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    int out_;
    out_ = solve(a);
    cout << out_;
}
