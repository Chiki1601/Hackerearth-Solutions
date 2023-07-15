#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
	long long t;
	cin >> t;
	while(t--)
	{
		long long n, i, j, s{0}, k;
		cin >> n >> k;
		long long ar[n];
		for(i = 0; i < n; i++)
		{
			cin >> j;
			s += j;
		}
		cout << (k == 1 ? 0 : (long long)ceil(s / k)) << "\n";
	}
}
