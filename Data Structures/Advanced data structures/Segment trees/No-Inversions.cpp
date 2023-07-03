#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int tc, N, q, l, r, cnt[200009], m[200009];
	long long dp[200009];
	string s;
	cin >> tc;
	while(tc--) 
	{
		cin >> N;
		cin >> s;
		for(int i = 0; i < N; i++) 
		{
			cnt[i] = 0;
			dp[i] = 0;
			m[i] = 0;
		}
		int cnt1 = N - 1, cnt2 = N - 1;
		for(int i = N - 1; i >= 1; i--) 
		{
			if(s[i - 1] <= s[i]) 
				cnt2--;
			else 
			{
				for(int j = cnt2; j <= cnt1; j++) 
					cnt[j] = j - cnt2;
				cnt1 = cnt2 - 1;
				cnt2 = cnt1;
			}
		}
		for(int i = cnt2; i <= cnt1; i++) 
			cnt[i] = i - cnt2;
		cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < N - 1; i++) 
		{
			if(s[i + 1] >= s[i]) 
				cnt2++;
			else 
			{
				for(int j = cnt1; j <= cnt2; j++) 
					m[j] = cnt2;
				cnt1 = cnt2 + 1;
				cnt2 = cnt1;
			}
		}
		for(int i = cnt1; i <= cnt2; i++)
			m[i] = cnt2;
		for(int i = 1; i < N; i++) 
			dp[i] = dp[i - 1] + cnt[i];
		cin >> q;
		for(int i = 0; i < q; i++) 
		{
			cin >> l >> r;
			long long ans =  dp[r - 1] - dp[l - 1] + 1LL * (r - l + 1);
			int buf = min(m[l - 1], r - 1);
			ans -= (max(0, l - buf + cnt[buf] - 1) * (buf - l + 1) * 1LL);
			cout << ans << "\n";
		}
	}
	return 0;
}
