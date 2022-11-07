#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)
	{
		string s; 
		cin >> s;
		long long n = s.size() + 1, dp[n] = {0}, ans = LONG_LONG_MIN;
		for(int i = 3; i <= s.size(); i++)
		{
			long long c = i - 1;
			if(!(s[c-2] == s[c - 1] && s[c - 1] ==s [c]))
			{
				dp[i] = 3;
				dp[i] += dp[i - 3];
			}
			ans = max(ans, dp[i]);
		}
		cout << s.size() - ans << endl;
	}
	return 0;
}
