#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int t = 1;
    cin >> t;
    while(t--)
    {
		long long int n, k, sum = 0, curr = 0, ans = 0;
		cin >> n >> k;
		vector<long long int> v(n), diff;
		for(auto &x : v)
		{
			cin >> x;
			diff.push_back((x ^ k) - x);
			sum += x;
		}
		for(auto &x : diff)
		{
			curr += x;
			curr = max(0LL, curr);
			ans = max(ans, curr);
		}
		cout << sum + ans << endl;
	}
	return 0;
}
