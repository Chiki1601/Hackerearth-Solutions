#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int n, a[100007], b[100007];
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = -a[i];
	}
	b[0] = a[0];
	int k = 1;
	for(int i = 1; i < n; i++)
	{
		int res = lower_bound(b, b + k, a[i]) - b;
		b[res] = a[i];
		if(res == k) 
			k++;
	}
	cout << k << endl;
	return 0;
}
