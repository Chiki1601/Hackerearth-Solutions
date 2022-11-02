#include<bits/stdc++.h>
using namespace std;
int A[20][20], n, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, cnt = 0;
bool vis[20][20];
 
bool isvalid(int x,int y)
{
	return (x > 0 && y > 0 && x <= n && y <= n && A[x][y] == 0);
}
 
void dfs(int i, int j)
{
	if(i == n && j == n)
		cnt++;
	A[i][j] = 1;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k], y = j + dy[k];
		if(isvalid(x, y) && vis[x][y] == 0)
			dfs(x, y);
	}
	A[i][j] = 0;
	return;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n;i++)
		{
			for(int j = 1; j <= n; j++)
				cin >> A[i][j];
		}
		cnt = 0;
		dfs(1, 1);
		cout << cnt << endl;	
	}
	return 0;
}
