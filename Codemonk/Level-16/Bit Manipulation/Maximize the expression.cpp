#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	long long res = 0, arr[100000]; 
	int n; 
	cin >> n;
  	for(int i = 0; i < n; ++i) 
	  	cin >> arr[i];
  	for(int i = 0; i < n; ++i)
	{ 
		long long x; 
		cin >> x; 
		arr[i] ^= x; 
	}
  	for(int i = 0; i < n; ++i)
	{ 
		long long x; 
		cin >> x; 
		res += (~arr[i] & x) ? (arr[i] ^ (~arr[i] & x)) : (arr[i] ^ (x & -x)); 
	}
  	cout << res;
  	return 0;
}
