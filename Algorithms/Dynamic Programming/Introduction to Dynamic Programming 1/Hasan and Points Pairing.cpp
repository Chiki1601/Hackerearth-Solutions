#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x[18], y[18];
	double d[18][18], dp[1<<18];
 	cin >> n;
	for(int i = 0; i < n * 2; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n * 2; i++)
		for(int j = 0; j < n * 2; j++)
			d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
 	int N = n * 2;
	for(int i = 0; i < (1<<N); i++)
		dp[i] = 1000000000;
 	dp[0] = 0;
 	for(int i = 0; i < (1<<N); i++)
	{
		if(dp[i] > 100000000)
			continue;
		for(int q = 0; q < N; q++)
			if(!(i & (1<<q)))
			{
				for(int j = q + 1; j < N; j++)
				{
					if(i & (1<<j))
						continue;
					int nmask = (i | (1<<j) | (1<<q));
					dp[nmask] = min(dp[nmask], dp[i] + d[j][q]);
				}
				break;
			}
	}
	cout << fixed << setprecision(6) << dp[(1<<N) - 1] << endl;
	return 0;
}
