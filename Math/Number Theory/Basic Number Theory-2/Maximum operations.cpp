#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long test;
 	cin >> test;
 	while(test--)
	{
 		long long a, b, n;
 		cin >> a >> b >> n;
 		if(n % 3 == 1) 
		 	cout << a << endl;
 		else if(n % 3 == 2) 
		 	cout << b << endl;
 		else
		{
 			long long xor_ = a ^ b, bits = (int)log2(max(a, b)) + 1, all_ones = (1LL<<(bits)) - 1;
 			long long xnor_ = all_ones ^ xor_;
 			cout << (max(xor_, xnor_)) << endl;
 		}
 	}
}
