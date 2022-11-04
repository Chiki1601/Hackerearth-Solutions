#include <bits/stdc++.h>
using namespace std;
int sum[200010][30][2];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, x = 0; 
	cin >> n >> q;
	vector<int> xs(n);
	for(int i = 0; i < n; i++)
	{
		int v; 
		cin >> v; 
		x ^= v; 
		xs[i] = x;
		for(int j = 0; j < 30; j++) 
			sum[i][j][(x&(1<<j)) != 0] = 1;
		if(i) 
			for(int j = 0; j < 30; j++) 
				for(int k = 0; k < 2; k++)
					sum[i][j][k] += sum[i - 1][j][k];
	}
	while(q--)
	{
		int l, r; 
		cin >> l >> r; 
		l--; 
		r--;
		int pre = l ? xs[l - 1] : 0;
		long long ans = 0;
		for(int i = 0; i < 30; i++)
		{
			int f=!(pre&(1<<i));
			long long now = sum[r][i][f] - (l ? sum[l - 1][i][f] : 0);
			ans += now*(1<<i);
		}
		cout << ans << "\n";
	}
}
