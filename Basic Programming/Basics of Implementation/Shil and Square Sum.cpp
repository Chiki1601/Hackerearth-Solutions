#include<bits/stdc++.h>
using namespace std;
long long ar[1200050], pref[1200050], s, deriv;
 
int main()
{
  	ios_base::sync_with_stdio(0);
  	int n, k;
  	cin >> n >> k;
  	for(int i = 1; i <= n; i++)
    	  cin >> ar[i];
  	for(int i = 1; i <= n; i++)
  	{
    	  pref[i] = pref[i - 1] + ar[i];
    	  pref[i] %= 1000000007;
  	}
  	for(int i = 1; i <= k; i++)
    	  s += 1ll * i * i % 1000000007 * ar[i] % 1000000007;
  	s %= 1000000007;
  	cout << s;
  	for(int i = 2; i <= k; i++)
    	  deriv += (2 * i - 1)*ar[i] % 1000000007;
  	for(int i = 2; i <= n - k + 1; i++)
  	{
    	  s = s - ar[i - 1] + 1000000007;
    	  s %= 1000000007;
    	  s -= deriv;
    	  while (s < 0)
      		  s += 1000000007;
    	  deriv = deriv - 3 * ar[i] + 1000000007;
    	  deriv %= 1000000007;
    	  deriv -= 2 * (pref[i + k - 1] - pref[i]) % 1000000007;
    	  while (deriv < 0)
      		  deriv += 1000000007;
    	  s += ar[i + k - 1] * k % 1000000007 * k % 1000000007;
    	  s %= 1000000007;
    	  deriv += (2 * k + 1) * 1ll * ar[i + k - 1] % 1000000007;
    	  deriv %= 1000000007;
    	  cout << " " << s;
  	}
  	cout << endl;
    return 0;
}
