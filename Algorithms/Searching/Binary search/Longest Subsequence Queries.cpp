#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, n, q;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		vector<long long int> A(n), sum(n);
		for(int i = 0; i < n; i++)
			cin >> A[i];
		sort(A.begin(), A.end());
		sum[0] = A[0];
		for(int i = 1; i < n; i++)
			sum[i] = sum[i - 1] + A[i];
		while(q--)
		{
			long long int k;
			cin >> k;
			cout << lower_bound(sum.begin(), sum.end(), k) - sum.begin() << "\n";
		}
	}
	return 0;
}
