#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		long long x = (long long)((long long)sqrt(8 * n + 9) - 3) / 2;
		long long ans = 2 * (n - x);
		ans = min(min(ans, 2 * n), (n * (n + 1)) / 2);
		cout << ans << endl;
	}
	return 0;
}
