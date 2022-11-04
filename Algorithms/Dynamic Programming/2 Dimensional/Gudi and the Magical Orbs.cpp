#include<bits/stdc++.h>
using namespace std;
int arr[100][100], dp[101][101][501];
 
int main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, N, M, K;
	cin >> t;
	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N >> M >> K;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				cin >> arr[i][j];
		for(int k = 0; k < arr[0][0]; k++)
			dp[1][1][k] = -1;
		for(int k = arr[0][0]; k <= K; k++)
			dp[1][1][k] = arr[0][0];
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
			{
				for(int k = arr[i - 1][j - 1]; k <= K; k++)
				{
					int temp = max(max(dp[i - 1][j][k - arr[i - 1][j - 1]], dp[i][j - 1][k - arr[i - 1][j - 1]]), dp[i - 1][j - 1][k - arr[i - 1][j - 1]]);
					if(temp == -1)
						continue;
					dp[i][j][k] = temp + arr[i - 1][j - 1];
				}	
			}
		}
		cout << dp[N][M][K] << endl;
	}
	return 0;
}
