#include<bits/stdc++.h>
using namespace std;
int phi[10000005];
 
int phis(int n)
{
    if(phi[n] != -1)
		return phi[n];
    int ans = n, t = n;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ans /= i;
            ans *= (i - 1);
            while(n % i == 0)
				n /= i;
        }
    }
    if(n != 1)
    {
        ans /= n;
        ans *= (n - 1);
    }
    return phi[t] = ans;
}
 
long long pow_(long long a, long long b, long long m)
{
    long long res = 1;
    while(b)
    {
        if(b & 1)
        res = (res * a) % m;
        a = (a * a) % m;
        b>>=1;
    }
    return res;
}
 
long long solve(long long x, long long k, long long m)
{
    if(m == 1)
    	return 0;
    if(k == 0)
    	return 1;
    return pow_(x, solve(x, k - 1, phis(m)), m);
}
 
int main()
{
    memset(phi, -1, sizeof(phi));
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);   
    int t;
    cin >> t;
    while(t--)
    {
        long long x, k, m;
        cin >> x >> k >> m;
        cout << solve(x, k, m) << endl;
    }
    return 0;
}
