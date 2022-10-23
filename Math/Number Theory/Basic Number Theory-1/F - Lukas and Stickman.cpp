#include<bits/stdc++.h>
using namespace std;
 
int pwr(int a, int b) 
{
  	int r = 1;
   	while(b) 
	{
   		if(b % 2) 
		   	r = (long long)r * a % 1000000007;
   		a = (long long)a * a % 1000000007;
   		b /= 2;
    }
    return r;
}
    
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    set<long long> s;
	long long count_not_ambiguous[1000005], res = 0;
    for(int i = 0; i < n; ++i) 
	{
    	int a;
    	cin >> a;
    	s.insert(a);
    	count_not_ambiguous[a]++;
    }
    for(long long a : s) 
		for(long long b : s) 
		{
    		long long mul;
    		if(a != b) 
				mul = count_not_ambiguous[a] * count_not_ambiguous[b] % 1000000007;
    		else 
				mul = count_not_ambiguous[a] * (count_not_ambiguous[b] - 1) % 1000000007;
    		mul = mul * (a + b - 2) % 1000000007;
    		long long tmp1  = (a - 1) * (a - 2) / 2 % 1000000007, tmp2 = (b - 1) * (b - 2) / 2 * (b - 3) / 3 % 1000000007;
    		res += mul * tmp1 % 1000000007 * tmp2 % 1000000007;
    		res %= 1000000007;
    	}
    res = res * pwr(n - 2, 1000000005) % 1000000007;
    cout << res << endl;
    return 0;
}
