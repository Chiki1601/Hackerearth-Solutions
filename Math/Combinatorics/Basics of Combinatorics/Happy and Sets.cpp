#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, sum = 1;
	cin >> n;
	vector <long long> v;
	v.resize(n);
	for(auto i = 0; i < n; i++)
	{
		cin >> v[i];
		sum = ((sum % 1000000007) * ((v[i] + 1) % 1000000007) % 1000000007);
	}
	cout << sum - 1;
}
