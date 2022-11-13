#include<bits/stdc++.h>
using namespace std;
int n, k, ar[500031], mx, BITS[1 << 17], dp[35][1 << 12], fact[1100000], invf[1100000], S1[1 << 7][1 << 7], S2[1 << 7][1 << 7];
vector<int> v[500031];
long long inv_val[1100000];

vector<int> get_v(int x)
{
	vector<int> res;
	while(x)
	{
		res.push_back(x % k);
		x /= k;
	}
	return res;
}

int cb(int x)
{
	return BITS[x];
}

int C(int n, int m)
{
	if(n < m)
		return 0;
	long long res = fact[n];
	res *= invf[m];
	res %= 1000000007;
	res *= invf[n - m];
	return res % 1000000007;
}

int bitmask_dp()
{
	for(int i = 0; i <= mx; i++)
	{
		for(int mask = 0; mask < (1 << n); mask++)
			dp[i][mask] = 0;
	}
	dp[0][0] = 1;
	for(int lev = 0; lev < mx; lev++)
	{
		int half1 = (n + 1) / 2, half2 = n - half1;
		for(int mask1 = 0; mask1 < (1 << half1); mask1++)
		{
			for(int mask2 = 0; mask2 < (1 << half1); mask2++)
			{
				S1[mask1][mask2] = 0;
				for(int i = 0; i < half1; i++)
				{
					if(mask1&(1 << i))
					{
						if(mask2&(1 << i))
							S1[mask1][mask2] += k;
						else
							S1[mask1][mask2] += v[i][lev];
					}
				}
			}
		}
		for(int mask1 = 0; mask1 < (1 << half2); mask1++)
		{
			for(int mask2 = 0; mask2 < (1 << half2); mask2++)
			{
				S2[mask1][mask2] = 0;
				for(int i = 0; i < half1; i++)
				{
					if(mask1 & (1 << i))
					{
						if(mask2 & (1 << i))
							S2[mask1][mask2] += k;
						else
							S2[mask1][mask2] += v[i + half1][lev];
					}
				}
			}
		}
		for(int mask = 0; mask < (1 << n); mask++)
		{
			int tochange = (1 << n) - mask - 1, flag = 0;
			int nmask = tochange;
			if(dp[lev][mask] == 0)
				continue;
			for(; ; tochange = (tochange - 1) & (nmask))
			{
				if(flag)
					break;
				if(tochange == 0)
					flag = 1;
				int sum_have = 0, fixed = 0;
				for(int i = 0; i < n; i++)
				{
					if(tochange & (1 << i))
						continue;
					if(mask & (1 << i))
						continue;
					sum_have += v[i][lev];
					fixed++;
				}
				int rem_sum = k - sum_have;
				if(rem_sum < 0)
					continue;
				int total_ways = 0, mask_free = (mask | tochange), flag = 0;
				for(int ie_mask = mask_free; ; ie_mask = (ie_mask - 1) & mask_free)
				{
					if(flag)
						break;
					if(ie_mask == 0)
						flag = 1;
					int sig = cb(ie_mask);
					if(sig % 2)
						sig = -1;
					else
						sig = 1;
					int ohead = 0, part11 = (ie_mask&((1 << half1) - 1)), part12 = (mask&((1 << half1) - 1));
					ohead = S1[part11][part12] + S2[ie_mask >> half1][mask >> half1];
					if(ohead > rem_sum)
						continue;
					total_ways += C(rem_sum - ohead + (n - fixed - 1), n - fixed)*sig;
					if(total_ways < 0)
						total_ways += 1000000007;
					if(total_ways >= 1000000007)
						total_ways -= 1000000007;
				}
				dp[lev + 1][mask ^ tochange] += 1ll * dp[lev][mask] * total_ways % 1000000007;
				dp[lev + 1][mask ^ tochange] %= 1000000007;
			}
		}
	}
	int res = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		res = res + dp[mx][i],
			res %= 1000000007;
	}
	long long total = 1ll;
	for(int i = 1; i <= n; i++)
		total = total * (ar[i] + 1) % 1000000007;
	total = total - res + 1000000007;
	total %= 1000000007;
	return total;
}

int main()
{
	for(int i = 0; i < (1 << 15); i++)
		BITS[i] = BITS[i / 2] + i % 2;
	inv_val[1] = 1;
	for(int i = 2; i < 1100000; i++)
		inv_val[i] = (1000000007 - 1ll * (1000000007 / i) * inv_val[1000000007%i] % 1000000007) % 1000000007;
	fact[0] = 1;
	for(int i = 1; i < 1100000; i++)
		fact[i] = fact[i - 1] * 1ll * i % 1000000007;
	invf[0] = 1;
	for(int i = 1; i < 1100000; i++)
		invf[i] = invf[i - 1] * inv_val[i] % 1000000007;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		vector<int> V = get_v(ar[i]);
		v[i - 1] = V;
	}
	for(int i = 1; i <= n; i++)
	{
		if(v[i - 1].size() > mx)
			mx = v[i - 1].size();
	}
	for(int i = 1; i <= n; i++)
	{
		while(v[i - 1].size() < mx)
			v[i - 1].push_back(0);
	}
	for(int i = 0; i < n; i++)
		reverse(v[i].begin(), v[i].end());
	cout << bitmask_dp() << "\n";
	return 0;
}
