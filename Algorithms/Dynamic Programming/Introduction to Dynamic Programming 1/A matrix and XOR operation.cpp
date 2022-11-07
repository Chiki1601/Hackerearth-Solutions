#include <bits/stdc++.h>
using namespace std;
 
bool solve(long long int n, long long int m, long long int k) 
{
	if(k > n * m) 
		return false;
	for(long long int i = 0; i < n + 1; i++) 
	{ 
		long long int c1 = k - m * i, c2 = n - 2 * i;
		if(c2 == 0) 
			continue;
		if((c1 % c2 == 0) && ((c1 / c2) <= m) && ((c1 / c2) >= 0)) 
			return true;
	}
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int n, m, k;
		cin >> n >> m >> k;
		cout << (solve(n, m, k) ? "Yes" : "No") << endl;
	}
	return 0;
}
