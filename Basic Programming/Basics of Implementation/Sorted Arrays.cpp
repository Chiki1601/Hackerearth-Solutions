#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, a[1000001];
	long long int ans = 0;
	cin >> n;
	a[0] = 0;
	for(int i = 1; i <= n ; i++)
	{
		cin >> a[i];
		if(a[i] <= a[i - 1])
		{
			ans += a[i - 1] - a[i] + 1;
			a[i] = a[i - 1] + 1;
		}
	}
	cout << ans;
}
