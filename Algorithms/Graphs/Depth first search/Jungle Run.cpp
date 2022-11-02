#include<bits/stdc++.h>
using namespace std;
int mn = 100000;
 
void dfs(vector<vector<int>>a, int i, int n, int j, int m, int cnt)
{
	if(i < 0 || j < 0 || i > n || j > m || a[i][j] == 0)
		return;
		cnt++;
	if(a[i][j] == 2)
	{
		mn = min(mn, cnt);
		cnt = 0;
		return;
	}
	a[i][j] = 0;
	dfs(a, i + 1, n, j, m, cnt);
	dfs(a, i - 1, n, j, m, cnt);
	dfs(a, i, n, j + 1, m, cnt);
	dfs(a, i, n, j - 1, m, cnt);
	a[i][j] = 1;
}
 
int main()
{
	int n;
	cin >> n;
	vector<vector<char>>a(n, vector<char>(n));
	vector<vector<int>> b(n, vector<int>(n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 'P')
				b[i][j] = 1;
			else if(a[i][j] == 'T')
				b[i][j] = 0;
			else if(a[i][j] == 'E')
				b[i][j] = 2;		
		}
	}		
	b[0][0] = 1;
	dfs(b, 0, n - 1, 0, n - 1, 0);
	cout << mn - 1 << endl;
}
