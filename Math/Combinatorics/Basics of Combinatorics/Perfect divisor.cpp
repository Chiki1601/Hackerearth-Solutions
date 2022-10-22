#include<bits/stdc++.h>
using namespace std;
 
long long binpow(long long a, long long b)
{
	long long ans = 1;
	while(b > 0)
	{
		if(b % 2)
            ans = (ans * a) % 1000000007;
		a = (a * a) % 1000000007;
		b>>=1;
	}
	return ans;
}
 
void factorize(long long n, map<long long, long long>& mp)
{
	for(long long i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			mp[i]++;
			n /= i;
		}
	}
	if(n != 1)
        mp[n]++;
}
 
long long inv(long long n)
{
	return binpow(n, 1000000005);
}
 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, a, b, ans = 1;
	cin >> n;
	map<long long, long long> mp;  
	for(long long i = 0; i < n; i++)
	{
		cin >> a >> b;
		map<long long, long long> m;
		factorize(a, m);
		for(auto it : m)
		{
			it.second = (it.second * b) % 1000000007;
			mp[it.first] = (mp[it.first] + it.second) % 1000000007;
		}
	}
	for(auto it : mp)
	{
		long long val = it.second % 2 ? it.second - 1 : it.second, cnt = val / 2;
		long long r = binpow(it.first, 2);
		long long num = (binpow(r, cnt + 1) - 1 + 1000000007) % 1000000007;
		long long denm = (r - 1 + 1000000007) % 1000000007;
		long long new_num = inv(denm);
		long long curr_ans = (num * new_num) % 1000000007;
		ans = (ans * curr_ans) % 1000000007;
	}
	cout << ans;
}
