#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, dp[1 << 17], old[1 << 17];
    cin >> n;
    map<int, int> bu;
    for(int i = 0; i < n; i++)
	{
        int x;
        cin >> x;
        bu[x]++;
    }
    dp[0] = 1;
    for(auto [tmp, c] : bu)
	{
        copy(dp, end(dp), old);
        fill(dp, end(dp), 0);
        for(int i = 0; i < 1 << 17; i++)
            dp[i] = (old[i] + old[c ^ i]) % 1000000007;
    }
    cout << dp[0] << endl;
}
