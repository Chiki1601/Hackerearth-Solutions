#include<bits/stdc++.h>
using namespace std;
int n, q;
long long memo[1 << 20];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) 
    {
		int x;
		cin >> x;
		memo[x] += x;
	}
	for(int i = 0, p = 1; i < 20; i++, p <<= 1) 
    {
		for(int mask = 0; mask < (1 << 20); mask++) 
        {
			if(mask & p) 
                memo[mask] += memo[mask ^ p];
		}
	}
	cin >> q;
	while(q--)
    {
		int x;
		cin >> x;
		cout << memo[x ^ ((1 << 20) - 1)] << "\n";
	}
	return 0;
}
