#include<bits/stdc++.h>
using namespace std;
bool visit[101][101][101];
int a[101][101][101], x, y, z, count1;
vector<pair<int, pair<int, int>>>vec;
 
void dfs(int i, int j, int k)
{
	count1--;
	if(i > 1 && a[i - 1][j][k] == 0 && visit[i - 1][j][k] == false)
	{
		visit[i - 1][j][k] = true;
		dfs(i - 1, j, k);
	}
	if(j > 1 && a[i][j - 1][k] == 0 && visit[i][j - 1][k] == false)
	{
		visit[i][j - 1][k] = true;
		dfs(i, j - 1, k);
	}
	if(k > 1 && a[i][j][k - 1] == 0 && visit[i][j][k - 1] == false)
	{
		visit[i][j][k - 1] = true;
		dfs(i, j, k - 1);
	}
	if(i < z && a[i + 1][j][k] == 0 && visit[i + 1][j][k] == false)
	{
		visit[i + 1][j][k] = true;
		dfs(i + 1, j, k);
	}
	if(j < x && a[i][j + 1][k] == 0 && visit[i][j + 1][k] == false)
	{
		visit[i][j + 1][k] = true;
		dfs(i, j + 1, k);
	}
	if(k < y && a[i][j][k + 1] == 0 && visit[i][j][k + 1] == false)
	{
		visit[i][j][k + 1] = true;
		dfs(i, j, k + 1);
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		count1 = 0;
		vec.clear();
		cin >> x >> y >> z;
		for(int i = 1; i <= z; ++i)
		{
			for(int j = 1; j <= x; j++)
			{
				for(int k = 1; k <= y; k++)
				{
					visit[i][j][k] = false;
					cin >> a[i][j][k];
					if(a[i][j][k] == 0)
					{
						count1++;
						if(i == 1 || j == 1 || k == 1 || j == x || i == z || k == y)
							vec.push_back(make_pair(i, make_pair(j, k)));
					}
				}
			}
		}
		for(int i = 0; i < vec.size(); i++)
		{
			if(!visit[vec[i].first][vec[i].second.first][vec[i].second.second])
			{
				visit[vec[i].first][vec[i].second.first][vec[i].second.second] = true;
				dfs(vec[i].first, vec[i].second.first, vec[i].second.second);
			}
		}
		cout << count1 << endl;
	}
	return 0;
}
