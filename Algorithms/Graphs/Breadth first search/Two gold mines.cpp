#include <bits/stdc++.h>
using namespace std;
int n, d[114][114];
char c[114][114];
 
bool check(int i, int j) 
{
	return 0 <= i && 0 <= j && i < n && j < n && c[i][j] != '#';
}
 
int dist(int si, int sj, int di, int dj) 
{
	queue<tuple<int, int>> q({{si, sj}});
	memset(d, 63, sizeof d);
	d[si][sj] = 0;
	while(!q.empty()) 
    {
		auto[i, j] = q.front();
		q.pop();
		for(int dx = -1; dx <= 1; ++dx)
			for(int dy = -1; dy <= 1; ++dy)
				if(abs(dx) + abs(dy) == 1 && check(i + dx, j + dy) && d[i + dx][j + dy] > d[i][j]) 
                {
					d[i + dx][j + dy] = d[i][j] + 1;
					q.emplace(i + dx, j + dy);
				}
	}
	return d[di][dj];
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) 
    {
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> c[i];
		vector<pair<int, int>> players, mines;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(c[i][j] == '^')
					players.emplace_back(i, j);
				else if(c[i][j] == '*')
					mines.emplace_back(i, j);
		int one_player_do = min({dist(players[0].first, players[0].second, mines[0].first, mines[0].second), dist(players[0].first, players[0].second, mines[1].first, mines[1].second), dist(players[1].first, players[1].second, mines[1].first, mines[1].second), dist(players[1].first, players[1].second, mines[0].first, mines[0].second)}) + dist(mines[1].first, mines[1].second, mines[0].first, mines[0].second);
		int two_player_do = min(max(dist(players[0].first, players[0].second, mines[0].first, mines[0].second), dist(players[1].first, players[1].second, mines[1].first, mines[1].second)), max(dist(players[0].first, players[0].second, mines[1].first, mines[1].second), dist(players[1].first, players[1].second, mines[0].first, mines[0].second)));
		int ans = min(one_player_do, two_player_do);
		if(ans < 1e9)
			cout << "Yes" << endl << ans << endl;
		else
			cout << "No" << endl;
	}
}
