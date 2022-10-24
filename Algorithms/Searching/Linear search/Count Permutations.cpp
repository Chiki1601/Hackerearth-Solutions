#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, a[100010];
    cin >> t;
    while(t--)
	{
		int n, cnt = 0;
		long long ans = 1;
		cin >> n;
		for(int i = 1; i <= n; ++i) 
		{
			cin >> a[i];
			if(a[i] < i || a[i - 1] > a[i]) 
				ans = 0;
			if(a[i] != a[i - 1]) 
				cnt += a[i] - a[i - 1] - 1;
			else 
				ans *= cnt--;
			ans %= 1000000007;
		}
		cout << ans << endl;
	}
    return 0;
}
