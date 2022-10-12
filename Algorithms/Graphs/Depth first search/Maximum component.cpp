#include<bits/stdc++.h>
using namespace std;
int par[400005], szz[400005], map_c[400005];
set<int> unq_c;

int find(int x)
{
	while(par[x] != x)
		x = par[x] = par[par[x]];
	return x;
}
 
void _union(int x, int y)
{
	int sx = szz[x], sy = szz[y];
	map_c[sx]--;
	map_c[sy]--;
	if(map_c[sx] == 0)
		unq_c.erase(sx);
	if(map_c[sy] == 0)
		unq_c.erase(sy);
	if(sx > sy)
    {
		par[y] = x;
		szz[x] += sy;
		map_c[szz[x]]++;
		unq_c.insert(szz[x]);
	}
    else
    {
		par[x] = y;
		szz[y] += sx;
		map_c[szz[y]]++;
		unq_c.insert(szz[y]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, t, i, j, x, y, k, ans, kk;
    cin >> n >> q;
	map_c[1] = n;
	unq_c.insert(1);
	unq_c.insert(0);
	auto it = unq_c.begin(), itt = it;
	for(i = 1; i <= n; i++)
    {
		szz[i] = 1;
		par[i] = i;
	}
	while(q--)
    {
		cin >> t;
		if(t == 1)
        {
            cin >> x >> y;
			x = find(x);
			y = find(y);
			if(x != y)
				_union(x, y);
		}
        else
        {
            cin >> k;
			kk = k + 1;
			ans = 0;
			itt = unq_c.end();
			itt--;
			while(*itt != 0 && kk > 0)
            {
				x=*itt;
				y = map_c[x];
				if(y >= kk)
                {
					ans += (kk * x);
					kk = 0;
				}
                else
                {
					ans += (y * x);
					kk -= y;
				}
				itt--;
			}
			if(kk == 1)
				ans++;
			cout << ans << "\n";
		}
	}
	return 0;
}
