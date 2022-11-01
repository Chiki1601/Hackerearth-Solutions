#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, k, a, x, arr[1000001];
	cin >> n;
	for(i = 0; i < n; ++i) 
	    cin >> arr[i];
	sort(arr, arr + n);
	cin >> k;
	while(k--) 
	{
	    cin >> a >> x;
	    if(a == 0) 
	        cout << n - (lower_bound(arr, arr + n, x) - arr) << "\n";
	    else
	        cout << n - (upper_bound(arr, arr + n, x) - arr) << "\n";
	}
	return 0;
}
