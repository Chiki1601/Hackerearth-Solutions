#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int t, n, i, a, b, sum;
	cin >> t;
	while(t--)
	{
		cin >> n;
		long long int ans[n];
		sum = 0;
		for(i = 0; i < n; i++)
		{
			cin >> a >> b;
			ans[i] = (a + b);
			sum += b;
		}
		sort(ans, ans + n);
		reverse(ans, ans + n);
		cout << ans[0] + ans[1] - sum << endl;
	}
}
