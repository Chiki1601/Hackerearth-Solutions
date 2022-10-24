#include <bits/stdc++.h>
using namespace std;
int mat[1002][1002];
bool visited[1002][1002];
 
int helper(int i, int j)
{
	visited[i][j] = true;
	queue<pair<int, int>> q;
	q.push({i, j});
	int currsize = 1;
	while (q.size())
	{
		pair<int, int> rem = q.front();
		q.pop();
		int newx = rem.first, newy = rem.second;
		for(int i = -1; i <= 1; i++)         // FOR the nbr of current node
		{
			for (int j = -1; j <= 1; j++)
			{
				if(!visited[newx + i][newy + j] && mat[newx + i][newy + j] == 1)
				{
					currsize++;
					q.push({newx + i, newy + j});
					visited[newx + i][newy + j] = true;
				}
			}	
		}
	}
	return currsize;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(mat, 0, sizeof(mat));
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> mat[i][j];
		} 
		int ans = 0, counter = 0; // max no of elemnts in a onr go of BFS, no of times we perform BFS
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && mat[i][j] == 1)
				{
					ans = max(helper(i, j), ans);
					counter++;
				}
			}
		}
		cout << counter << " " << ans << endl;
	}
}
