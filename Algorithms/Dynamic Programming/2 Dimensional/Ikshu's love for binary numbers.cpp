#include <bits/stdc++.h>
using namespace std; 
long long nibonacci[70];
 
void gen_nibonacci(long long k)
{
	memset(nibonacci, 0, sizeof(nibonacci));
	nibonacci[1] = 1;
	nibonacci[2] = 1;
	for(long long i = 3; i < 70; i++)
	{
		for(long long j = i - 1; j > i - 1 - k && j > 0; j--)
				nibonacci[i] += nibonacci[j];
	}
}
 
int main()
{
	long long n, k;
	cin >> n >> k;
	gen_nibonacci(k);
	long long g = __gcd((1L << n) - nibonacci[n + 2], (long long)(1L<< n));
	cout << ((1L << n) - nibonacci[n + 2]) / g << "/" << (1L<<n) / g << endl;
}
