#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long T;
	cin >> T; 
	while(T--) 
	{
		long long l, r, ans = 0;
		cin >> l >> r;
		while(1)
		{
			if(l == 1) 
			{
				ans++; 
				break;
			}
			long long b = 64-__builtin_clzll(l - 1);
			long long t = 1LL<<b;
			if(t <= r) 
			{
				ans += t; 
				break;
			}
			t /= 2; 
			ans += t; 
			l -= t; 
			r -= t;
		}
		cout << ans << "\n";
	}
	return 0;
}
