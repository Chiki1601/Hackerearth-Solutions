#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tt, n;
	cin >> tt;
	while(tt--) 
	{
		cin >> n;
		long long sum = 0;
		bool ok = true;
		for(int i = 1; i <= n; i++) 
		{
			int x; cin >> x;
			sum += x;
			ok &= (sum >= 1LL * i * (i + 1) / 2);
		}
		ok &= (sum == 1LL * n * (n + 1) / 2);
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}
