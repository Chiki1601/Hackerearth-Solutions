#include<bits/stdc++.h>
using namespace std;
 
long long binaryexponentiation(long long a, long long b)
{
	if(b == 0)
		return 1;
	long long res = binaryexponentiation(a, b / 2);
	if(b % 2) 
		return (res * res * a) % 1000000007;
	else 
		return (res * res) % 1000000007;
}
 
long long solve(long long field, long long power)
{
	power = (1<<power);
	if(power > field) 
		return 0;
	field = field - power + 1;
	long long ans = power * (field / (2 * power)) + min(power, (field % (2 * power)));
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n; 
	cin >> n;
	while(n--)
	{
		long long a, b, c, d, ans = 0; 
		cin >> a >> b >> c >> d;
		for(int i = 31; i >= 0; i--)
		{
			long long firstone = solve(b, i) - solve(a - 1, i);
			long long firstzero = b - a + 1 - firstone;
			long long secondone = solve(d, i) - solve(c - 1, i);
			long long secondzero = d - c + 1 - secondone;
			long long power = binaryexponentiation(2, i);
			long long temp = ((firstone * secondzero) % 1000000007 + (secondone * firstzero) % 1000000007) % 1000000007;
			temp = (temp * power) % 1000000007;
			ans = (ans + temp) % 1000000007;
		}
		cout << ans << endl;
	}
	return 0;
}
