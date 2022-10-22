#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int T; 
	  cin >> T; 
	  while(T--)
    {
      	long long int n; 
	  	  cin >> n;
      	vector<long long int>a(n);
      	long long int odd = 0;
      	for(int i = 0; i < n; i++)
	  	  {
          	cin >> a[i];
          	odd += (a[i] & 1);
      	}
      	long long int ans = min(odd, n - odd);
      	cout << ans << endl;
    }
    return 0;
}
