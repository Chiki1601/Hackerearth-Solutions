#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		long long a[n] = {0};
		for(long long i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		long long ans = 0;
		for(long long i = 0; i < n; i++)
		 	ans = (ans + ((a[i] * i) - (a[i] * (n - i - 1))) % 1000000007) % 1000000007;
		cout << (ans * a[n - 1]) % 1000000007 << endl;
	}
}
