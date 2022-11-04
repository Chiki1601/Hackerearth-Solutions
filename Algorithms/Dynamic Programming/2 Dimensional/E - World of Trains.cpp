#include<bits/stdc++.h>
using namespace std;
int even[4005][4005], slop[4005][4005];
 
int add(int a, int b) 
{
	return ((a + b) % 1000000007 + 1000000007) % 1000000007;
}
 
int mul(int a, int b) 
{
	return (long long) a * b % 1000000007;
}
 
int main() 
{
	int n, len, goal, k;
	cin >> n >> len >> goal >> k;
	for(int i = 1; i <= n; ++i)
		for(int t = 0; t <= goal; ++t)
		{
			int x = mul(k - 1, add(even[i - 1][t], -even[max(0, i - len)][t]));
			if(i < len && t == 0) 
				x = add(x, k);
			else if(t == i - len + 1) 
				x = add(x, k);
			if(t) 
				x = add(x, mul(k - 1, slop[max(0, i - len)][t - 1]));
			if(i == n && t == goal) 
				cout << x << endl;
			even[i][t] = add(x, even[i - 1][t]);
			slop[i][t] = add(x, t ? slop[i - 1][t - 1] : 0);
	}
	return 0;
}
