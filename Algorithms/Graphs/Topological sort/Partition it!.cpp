#include <bits/stdc++.h>
using namespace std;
 
long long bpow(long long x, long long n, long long mod) 
{
    long long ans = 1;
    while(n > 0) 
	{
        if(n & 1) 
			ans *= x;
        x *= x;
        ans %= mod;
        x %= mod;
        n /= 2;
    }
    return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) 
	{
        int P, N;
        cin >> P >> N;
        vector<int>divs;
        int sz = sqrt(P - 1), num = P - 1, maxLen  = 0, A[1011], dp[1011];
        for(int j = 1; j <= sz; j++) 
		{
            if(num % j == 0) 
				divs.push_back(j), divs.push_back(num/j);
        }
        sort(divs.begin(), divs.end());
        vector<int>periods;
        for(int i = 0; i < N; i++) 
		{
            assert(cin >> A[i]);
            assert(A[i] >= 1 and A[i] < P);
            long long cur = 1;
            for(auto d : divs) 
			{
                if(bpow(A[i], d, P) == 1)
				{
                    periods.push_back(d);
                    break;
                }
            }
        }
        sort(periods.begin(), periods.end());
        for(int i = N - 1; i >= 0;i--) 
		{
            dp[i] = 1;
            for(int j = i + 1; j < N; j++) 
			{
                if(periods[j] % periods[i] == 0) 
					dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        cout << maxLen << endl;
    }
}
