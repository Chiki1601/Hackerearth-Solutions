#include <bits/stdc++.h>
using namespace std;
int n, A[100005], q, y, cnt[100005], up = 10000;
long long dp[100005], ndp[100005], sum[100005], df = 1LL;
 
void shift(long long mul, int del)
{
    long long sum = 0;
	for(int j = 1; j <= up; ++j)
	{
		sum += dp[j - 1];
		sum *= mul;
		if(j - del >= 0) 
			sum -= dp[j - del] * df;
		sum %= 1000000007;
		ndp[j] = sum;
	}
}
 
void factor(int val)
{
	int sq = sqrt(val);
	for(int i = 2; i <= sq; ++i)
	{
		while(val % i == 0)
		{
			cnt[i]++;
			val /= i;
		}
	}
	if(val > 1) 
		cnt[val]++;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	dp[0] = 1LL;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		factor(A[i]);
	}
	for(long long i = 1; i < 100005; ++i)
	{
		if(cnt[i] == 0) 
			continue;
        df = 1LL;
        for(int j = 1; j <= cnt[i] + 1; ++j) 
			df = (df * i) % 1000000007;
		shift(i, cnt[i] + 1);
		for(int j = 1; j <= up; ++j)
		{
			dp[j] =  (dp[j] + ndp[j]) % 1000000007; 
			ndp[j] = 0;
		}
	}
	for(int i = 1; i <= q; ++i)
	{
		cin >> y;
		if(dp[y] < 0) 
			dp[y] += 1000000007;
		cout << dp[y] << endl;
	}
	return 0;
}
