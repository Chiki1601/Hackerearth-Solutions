#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1<<20];
 
long long get_phi(long long val, vector<int>&primes)
{
	long long res = val;
	for(int i = 0; i < primes.size(); i++)
	{
		while(val % primes[i] == 0)
			val /= primes[i];
		res = res / primes[i] * (primes[i] - 1);
	}
	if(val > 1)
		res = res / val * (val - 1);
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long l, r, k;
	int tests, pr[1<<20], ans;
	pr[1] = 1;
	for(int i = 2; i <= 1000000; i++)
		if(pr[i] == 0)
			for(int j = i * 2; j <= 1000000; j += i)
				pr[j] = 1;
	cin >> tests;
	for(; tests; --tests)
	{
		cin >> l >> r >> k;
		for(long long i = l; i <= r; i++)
			vec[i - l].clear();
		for(int i = 2; i <= 1000000; i++)
		{
			if(pr[i])
				continue;
			long long bnd = l / i * i;
			if(l % i > 0)
				bnd += i;
			for(long long j = bnd; j <= r; j += i)
				vec[j - l].push_back(i);
		}
		ans = 0;
		for(long long i = l; i <= r; i++)
		{
			long long Q = get_phi(i, vec[i - l]);
			if(Q % k == 0)
				++ans;
		}
		cout << setprecision(6) << fixed << ans * 1.0 / (r - l + 1) << endl;
	}
	return 0;
}
