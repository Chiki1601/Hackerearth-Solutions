#include <bits/stdc++.h>
using namespace std;
int cnt[5000010], inv[5000010];
 
int modpow(long long int a, long long int b, long long int mod)
{
    long long int res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res % mod;
}
 
int main()
{
  	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, p;
   	long long int ans = 0, x;
   	cin >> n >> p;
   	for(int i = 0; i < n; i++)
    {
 		cin >> x; 
        x %= p; 
        cnt[x]++; 
        inv[x] = modpow(x, p - 2, p);
  	}
   	for(int i = 1; i < 100000; i++)
    {
  		if(cnt[inv[i]] == 0) 
            ans += cnt[i];
   		else if(inv[i] > i) 
            ans += max(cnt[i], cnt[inv[i]]);
   	}
  	cout << ans + cnt[0] << endl;
   	return 0;
}
