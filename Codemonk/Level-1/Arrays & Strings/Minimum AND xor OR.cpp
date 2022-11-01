#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long int A[n], ans = INT_MAX;
		for(int i = 0; i < n; i++)
			cin >> A[i];
		sort(A, A + n);
		for(int i = 0; i < n - 1; i++)
			ans = min(ans, A[i] ^ A[i + 1]);
		cout << ans << endl;
	}
	return 0;
}
