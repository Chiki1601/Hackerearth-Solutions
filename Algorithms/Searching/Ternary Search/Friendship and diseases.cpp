#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, n, m, f[10009], d[10009];
    string g [109];
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++) 
        cin >> f [i];
	for(int i = 1; i <= k; i++) 
        cin >> d [i];
	for(int i = 0; i < n; i++) 
        cin >> g [i];
	vector <int> ind (k);
	iota(ind.begin(), ind.end(), 1);
	sort(ind.begin(), ind.end(), [&](int x, int y){ return f [x] > f [y]; });
	vector <pair <int, int>> pos;
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
	        if(g [i][j] == '.') 
                pos.push_back({i + 1, j + 1});
	vector <pair <int, int>> ans(k + 1);
	for(auto i : ind)
	{
		if(pos.empty()) 
            break;
		ans [i] = pos.back();
		pos.pop_back();
	}
	for(int i = 1; i <= k; i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
