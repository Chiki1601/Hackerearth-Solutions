#include <bits/stdc++.h>
using namespace std;
 
int binExpoIter(long long a, long long b, long long m) 
{
	int ans = 1; 
	while (b > 0) 
    {
 		if (b & 1) 
			ans  = (ans * 1LL * a) % m;
		a = (a * 1LL * a) % m;
		b >>= 1;
	}
	return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long a, b;
	cin >> a >> b;
	int ans = binExpoIter(a, b, 1000000007);
	cout << ans << endl;
	return 0;
}
