#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, mn = INT_MAX, sum = 0;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			mn = min(mn, arr[i]);
		}
		cout << mn - 1 << " " << sum - n << endl;
	}
}
