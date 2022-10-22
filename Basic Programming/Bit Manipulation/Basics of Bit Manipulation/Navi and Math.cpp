#include <bits/stdc++.h>
using namespace std;
 
long long power(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    while (exponent > 0) 
	  {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
 
int main()
{
    int t;
    cin >> t;
    assert(1 <= t && t <= 10);
    for (int tt = 1; tt <= t; tt++) 
	  {
        int n;
        cin >> n;
        assert(2 <= n && n <= 16);
        vector <long long int > a(n + 1);
        for (int i = 0; i < n; i++) 
		    {
            cin >> a[i];
            assert(1 <= a[i] && a[i] <= 10000000);
        }
        int p = 1 << n;
        long long ans = INT_MIN;
        for (int i = 1; i < p; i++) 
		    {
            long long mul = 1, add = 0;
            int ctr = 0;
            for (int j = 0; j < n; j++) 
			      {
                if (i & 1 << j) 
				        {
                    ctr++;
                    add = (add + a[j]) % 1000000007;
                    mul = (mul * a[j]) % 1000000007;
                }
            }
            if (ctr >= 2 ) 
			      {
                long long int temp = power(add, 1000000005, 1000000007);
                temp = (temp * mul) % 1000000007;
                ans = max(ans, temp);
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
}
