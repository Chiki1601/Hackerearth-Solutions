#include<bits/stdc++.h>
using namespace std;
int n, m, sizes[1000005], comp[1005][1005], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char s[1005][1005];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int len = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i][j] == '#') 
				continue;
			if(comp[i][j]) 
				continue;
			queue<int> Q;
			int cnt = 0;
			comp[i][j] = ++len;
			Q.emplace(i); Q.emplace(j);
			while(!Q.empty())
			{
				int ux = Q.front(); 
				Q.pop();
				int uy = Q.front(); 
				Q.pop();
				cnt += s[ux][uy] == '*';
				for(int k = 0; k < 4; k++)
				{
					int vx = ux + dx[k], vy = uy + dy[k];
					if(vx < 0 or vy < 0 or vx >= n or vy >= m) 
						continue;
					if(s[vx][vy] == '#') 
						continue;
					if(comp[vx][vy]) 
						continue;
					Q.emplace(vx);
					Q.emplace(vy);
					comp[vx][vy] = len;
				}
			}
			sizes[len] = cnt;
		}
	}
	int ans = *max_element(sizes, sizes + len + 1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i][j] != '#') 
			continue;
			set<int> used;
			for(int k = 0; k < 4; k++)
			{
				int vx = i + dx[k], vy = j + dy[k];
				if(vx < 0 or vy < 0 or vx >= n or vy >= m) 
					continue;
				used.emplace(comp[vx][vy]);
			}
			int cur = 0, maxi1 = 0, maxi2 = 0;
			for(auto x : used)
			{
				if(maxi2 < sizes[x]) 
					maxi2 = sizes[x];
				if(maxi1 < maxi2) 
					swap(maxi1, maxi2);
			}
			ans = max(ans, maxi2 + maxi1);
 		}
	}
	cout << ans << endl;
	return 0;
}
