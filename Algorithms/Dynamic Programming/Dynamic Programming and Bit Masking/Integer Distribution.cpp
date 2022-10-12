#include<bits/stdc++.h>
using namespace std;
int n, arr[20];
pair<long long, long long> dp[1500000];
 
pair<long long, long long> solve(int mask)
{
    if(mask + 1 == (1<<n))
        return {0, 0};
    if(dp[mask].first != -1)
        return dp[mask];   
    pair<long long, long long> ans = {1e16,-1e16};
    for(int i = 0; i < n; i++)
    {
        if(!(mask & (1<<i))) // check if value of i is present or not if yes
        {
            mask|=(1<<i); 
            for(int j = i + 1; j < n; j++)
            {
                if(!(mask & (1<<j))) 
                {
                    pair<long long, long long> next = solve(mask|(1<<j));
                    ans.first = min(ans.first, (arr[i] ^ arr[j]) + next.first);  
                    ans.second = max(ans.second, (arr[i] ^ arr[j]) + next.second);
                }
            }
            mask -= (1<<i);
            break; 
        }
    }
    return dp[mask] = ans;
}
 
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int mask = 0; mask < (1<<n); mask++)
        dp[mask] = {-1, -1};
    pair<long long, long long> ans = solve(0);
    cout << ans.first << " " << ans.second << endl;
}
