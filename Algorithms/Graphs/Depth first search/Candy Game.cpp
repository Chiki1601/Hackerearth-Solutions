#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > E[5000];
int ans = (~0U >> 1), u[5000], d[5000][3], n;
 
void dfs(int v)
{
    int nv, tp, d1 = 0, d2 = 0; 
	d[v][0] = 0; 
	u[v] = 1;
    for(int i = 0; i < (int)E[v].size(); i++)
    {
    	nv = E[v][i].first, 
		tp = E[v][i].second;
    	if(u[nv]) 
         	continue;
    	else
         	dfs(nv);
    	d[v][0] += tp + d[nv][0];
    	d1 = min(d1, d[nv][1] + 1 - tp - d[nv][0] - tp);
    	d2 = min(d2, min((d[nv][2] + tp) - (d[nv][0] + tp), d[nv][1] - (d[nv][0] + tp)));
    }
    d[v][1] = d[v][0] + d1, d[v][2] = d[v][0] + d2;
}
 
int main()
{
    int x, y;
    cin >> n;
    if(n == 1)
    {
    	cout << 0 << endl;
    	return 0;
    }
    for(int i = 0; i < n - 1; i++)
    { 
    	cin >> x >> y;
    	x--; 
		y--;
    	E[x].push_back(make_pair(y, 0));
    	E[y].push_back(make_pair(x, 1));
    }
    for(int i = 0; i < n; i++)
    {
    	memset(u, 0, sizeof u);
    	dfs(i);
    	ans = min(ans, min(d[i][0], min(d[i][1], d[i][2])));
    }
    cout << ans << endl;
}
