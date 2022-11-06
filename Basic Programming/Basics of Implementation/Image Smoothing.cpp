#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, m, board[N][N], coef[N][N]; 
 
int get(int a,int b)
{
	if (a < 0 || b < 0)
		return 0;
	return board[a][b];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i <= m * 2; i++)
	{
		for(int j = 0; j <= m * 2; j++)
			assert(cin >> coef[i][j]);
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			assert(cin >> board[i][j]);
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int here = 0;
			for (int q = 0; q <= m * 2; q++)
			{
				for(int w = 0; w <= m * 2; w++)
					here += get(i - m + q, j - m + w) * coef[q][w];
			}
			if(j > 1)
				cout << " ";
			cout << here;
		}
		cout << endl;
  }
	return 0;
}
