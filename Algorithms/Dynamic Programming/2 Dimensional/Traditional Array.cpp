#include<bits/stdc++.h>
using namespace std;
 
void fix_mod(long long& x) 
{
	if(x < 0) 
		x += 1000000007;
	else if(x >= 1000000007) 
		x -= 1000000007;
}
  
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, m;
	cin >> t;
	while(t--) 
	{
        cin >> n >> m;
        vector<long long> dp(m + 1, 1);
        for(int i = 1; i < n; i++) 
        {
            vector<long long> aux(m + 1);
            for(int j = 1; j <= m; j++) 
            {
                fix_mod(aux[j] += dp[j]);
                for(int k = j << 1; k <= m; k += j) 
                {
                    fix_mod(aux[k] += dp[j]);
                    fix_mod(aux[j] += dp[k]);
                }
            }
            dp.swap(aux);
        }
        long long ans = 0;
        for(int i = 1; i <= m; i++) 
            fix_mod(ans += dp[i]);
        cout << ans << endl;
    }
	return 0;
}
