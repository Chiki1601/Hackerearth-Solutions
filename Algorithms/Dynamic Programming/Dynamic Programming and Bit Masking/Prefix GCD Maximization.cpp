#include <bits/stdc++.h>
using namespace std;
 
long long solve(int mask, vector<long long>&ar, vector<long long>&dp) 
{
    int n = ar.size();
    if(mask == (1<<n) - 1)
        return 0;
    long long &val = dp[mask], current_gcd = 0;
    if(val != -1)
        return val;
    val = 0;
    for(int i = 0; i < n; i++)
    {
        if(mask & (1<<i))
            current_gcd = __gcd(current_gcd, ar[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if((mask & (1<<i)) == 0)
            val = max(val, __gcd(current_gcd, ar[i]) + solve(mask+(1<<i), ar, dp));
    }
    return val;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> ar(n), dp(1<<n, -1);
    for(int i = 0; i < n; i++)
        cin >> ar[i]; 
    cout << solve(0, ar, dp) << "\n";
}
