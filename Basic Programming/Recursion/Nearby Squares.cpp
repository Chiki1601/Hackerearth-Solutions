#include <bits/stdc++.h>
using namespace std; 

long long f(long long i, vector<long long>& v, long long a, long long sum)
{
	if(i == -1)
		return abs((sum - a) * (sum - a) - a * a);
	return min(f(i - 1, v, a + v[i], sum), f(i - 1, v, a, sum));
}

int main()
{
	long long t = 1;
	cin >> t;
	for(long long i = 0; i < t; i++)
    {
		long long n, sum = 0;
        cin >> n;
        vector<long long> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        long long ans = f(n - 1, v,  0, sum);
        cout << ans << endl;
	}
	return 0;
}
