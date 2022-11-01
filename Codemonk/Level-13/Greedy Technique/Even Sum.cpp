#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	long long int cnt_ev = 0, a[100005], sum[100005], even[100005], odd[100005], ans = 0;
	even[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] % 2 == 0) 
			cnt_ev++;
		sum[i] = sum[i - 1] + a[i];
		if(sum[i] & 1)
		{
			odd[i] = odd[i - 1] + 1;
			even[i] = even[i - 1];
		}
		else
		{
			odd[i] = odd[i - 1];
			even[i] = even[i - 1] + 1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		long long int odr = odd[n] - odd[i], evr = even[n] - even[i];
		if(sum[i] & 1)
		{
			long long int right = (((odr * (odr + 1) / 2) % 1000000007) + ((evr * (evr - 1) / 2) % 1000000007)) % 1000000007;
			ans += (odd[i - 1] * right) % 1000000007;
		}
		else
		{
			long long int right = (((odr * (odr - 1) / 2) % 1000000007) + ((evr * (evr + 1) / 2) % 1000000007)) % 1000000007;
			ans += (even[i - 1] * right) % 1000000007;
		}
		ans %= 1000000007;
	}
	cout << ans << "\n";
}
