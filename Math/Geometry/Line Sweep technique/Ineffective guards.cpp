#include<bits/stdc++.h>
using namespace std;
 
int main()
{    
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    int n, m;
    cin >> n >> m; 
    vector<pair<int, int>> g(n), j;
    for(int i = 0; i < n; ++i)
        cin >> g[i].first >> g[i].second;
    for(int i = 0; i < m; ++i)
	{
        int x, y;
        cin >> x >> y;
        bool ef = true;
        for(int k = 0; k < j.size(); ++k)
            if(abs(j[k].second - y) <= x - j[k].first)
			{
                ef = 0;
                break;
            }
        	if(ef)
            	j.push_back({x,y});
    }
    sort(g.begin(), g.end());
    sort(j.begin(), j.end());
    set<int> eff;
    for(int i = 0; i < j.size(); ++i)
	{
        int idx = -1, cnt = 0;
        for(int k = 0; k < g.size() && g[k].first < j[i].first; ++k)
            if(abs(g[k].second - j[i].second) <= j[i].first - g[k].first)
            {   
				cnt++;
			 	idx = k;
			}
        if(cnt == 1)
            eff.insert(idx);
    }
    cout << n - eff.size();
}
