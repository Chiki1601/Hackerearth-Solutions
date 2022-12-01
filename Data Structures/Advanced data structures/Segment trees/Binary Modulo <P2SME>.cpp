#include <bits/stdc++.h>
using namespace std;
long long a[10005];
 
long long binexp(long long a, long long b, long long m)
{
	long long res = 1;
	a %= m;
	while(b)
	{
		if(b & 1)
			res = (a * 1LL * res) % m;
		a = (a * 1LL * a) % m;
		b>>=1;
	}
	return res;
}
 
void update(int indx, int v)
{
	while(indx < 10005)
	{
		a[indx] = (a[indx] + v) % 5LL;
		indx += indx & -indx;
	}
}
 
int query(int indx)
{
	int sum = 0;
	while(indx)
	{
		sum = (a[indx] + sum) % 5LL;
		indx -= indx & -indx;
	}
	return sum;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long inv[5] = {0, 1, 3, 2, 4}, t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		long long n = s.size(), q;
		for(long long i = 0; i < n; i++)
		{
			if(s[i] == '1')
				update(i + 1, binexp(2, n - i - 1, 5LL));
		}
		cin >> q;
		while(q--)
		{
			long long t;
			cin >> t;
			if(t == 0)
			{
				long long l, r;
				cin >> l >> r;
				l++;
				r++;
				long long sum = (query(r) - query(l - 1) + 5LL) % 5LL;
				sum = (sum * inv[binexp(2, n - r, 5LL)]) % 5LL;
				cout << sum << "\n";
			}
			else
			{
				long long x, v;
				cin >> x >> v; 
				if(s[x] - '0' != v)
				{
					if(v)
						update(x + 1, binexp(2, n - x - 1, 5LL));
					else
						update(x + 1, 5LL - binexp(2, n - x - 1, 5LL));
					s[x] = v + '0';
				}
			}
		}
		memset(a, 0, sizeof a);
	}
	return 0;
}
