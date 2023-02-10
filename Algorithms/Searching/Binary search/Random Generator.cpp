#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, p;
		cin >> n >> k >> p;
		long long int a[n], i;
		for(i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int flag = 0;
		for(i = 0; i < n; i++)
		{
			int ind1 = upper_bound(a, a + n, a[i] + 2 * p) - a;
			if(ind1 - i >= k)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
