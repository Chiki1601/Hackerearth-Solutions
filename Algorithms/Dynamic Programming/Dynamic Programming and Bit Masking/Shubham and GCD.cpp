#include <bits/stdc++.h>
using namespace std;
long long prefix[100001];
 
int main()
{
	int n, f[100001];
	long long answer = 0; 
    memset(f, -1, sizeof(f));
    for(int i = 2; i <= 100000; ++ i) 
	{
        if(f[i] == -1) 
		{
            for(int j = i; j <= 100000; j += i) 
			{
                if(f[j] == -1) 
                    f[j] = i;
            }
        }
    }
    assert(scanf("%d", &n) == 1 && 1 <= n && n <= 100000);
    for(int i = 0; i < n; ++ i) 
	{
        int ai;
        assert(scanf("%d", &ai) == 1 && 1 <= ai && ai <= 100000);
        vector<int> factors;
        for(int x = ai; x > 1; x /= f[x]) 
		{
            if(factors.size() == 0 || f[x] != factors.back()) 
                factors.push_back(f[x]);
        }
        long long sum = 0;
        for(int mask = 0; mask < 1 << factors.size(); ++ mask) 
		{
            int sign = __builtin_popcount(mask) & 1 ? -1 : 1, prod = 1;
            for(int j = 0; j < factors.size(); ++ j) 
			{
                if(mask >> j & 1)
                    prod *= factors[j];
            }
            prefix[prod] += (i + 1);
            sum += sign * prefix[prod];
        }
        sum = (long long)(1 + i + 1) * (i + 1) / 2 - sum;
        answer += sum * (n - i);
        if(answer > 1000000000000000000LL) 
            answer = 1000000000000000000LL + 1;
    }
    if(answer > 1000000000000000000LL) 
        cout << -1 << endl;
    else 
        cout << answer << endl;
    return 0;
}
