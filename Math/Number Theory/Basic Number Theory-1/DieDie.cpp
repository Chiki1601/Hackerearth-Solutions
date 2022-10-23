#include<bits/stdc++.h>
using namespace std;
 
long long pw(long long a, long long b)
{
	if(b == 0)
		return 1;
	if(b % 2)
		return a * pw(a, b - 1) % 1000000007;
	return pw(a * a % 1000000007, b / 2);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int magic = pw(2, 1000000005), tests;
	cin >> tests;
	for (; tests; --tests)
	{
		long long n;
		cin >> n;
		cout << pw(magic, n - 1) << endl;
	}
	return 0;
}	
