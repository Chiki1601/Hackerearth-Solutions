#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
long long int solve()
{
    long long int n;
    cin >> n;
    vector<long long int>dp(n + 5, 0), marks(n), bound(n), temp(n);
    for(long long int i = 0; i < n; i++) 
    {
        cin >> marks[i] >> bound[i];
        dp[i + 1] = 1000000000000000ll;
        temp[i] = i;
    }
    sort(temp.begin(), temp.end(), [&](const ll& i1, const ll& i2)
    {
        return marks[i1] + bound[i1] < marks[i2] + bound[i2];
        
    });
    for(long long int i = 0; i < n; i++) 
    {
        int idx = temp[i];
        for(long long int j = i; j >= 0; j--) 
        {
            if(dp[j] <= marks[idx]) 
                dp[j + 1] = min(dp[j + 1], dp[j] + bound[idx]);
        }
    }
    for(long long int i = n; i >= 0; i--) 
    {
        if(dp[i] < 1000000000000000ll) 
            return i;
    }
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
    cin >> t; 
    while(t--)
       cout << solve() << endl;
	return 0;
}
