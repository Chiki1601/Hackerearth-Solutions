#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long int a, b, n;
    cin >> a >> b >> n;
	  long long int lcm = (a * b) / __gcd(a, b);
	  long long int cycle = (n * lcm) / (lcm / a + lcm / b - 1);
	  long long int arr[4] = {(cycle / a) * a, (cycle / a) * a + a, (cycle / b ) * b,						(cycle / b) * b + b};
	  for(auto i = 0; i <= 3; i++)
    {
		    if(arr[i] / a + arr[i] / b - arr[i] / lcm == n)
        {
			      cout << arr[i] << endl;
			      break;
		    }
	  }
}
 
int32_t main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  while(t--)
	      solve();
	  return 0;
}
