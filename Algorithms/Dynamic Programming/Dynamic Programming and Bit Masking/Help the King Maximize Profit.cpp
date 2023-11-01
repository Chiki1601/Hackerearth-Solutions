#include<bits/stdc++.h>
using namespace std;
int dp[25][7][7][128][128];

int dif(int inmask, int exmask, int n, int m, bool introv, int pos)
{
    int ans = 0, neigh = 0, cnt = 0, row = pos / m, col = pos % m;
    if(row > 0)
	{
        int upPos = m - 1;
        if(inmask&(1<<upPos) || exmask & (1<<upPos))
		{
            if(inmask & (1<<upPos))
			{
                cnt++;
                neigh -= 90;
            }
            else
			{
                cnt++;
                neigh += 60;
            }
        } 
    }
    if(col > 0)
	{
        int leftPos = 0;
        if(inmask & (1<<leftPos) || exmask & (1<<leftPos))
		{
            if(inmask & (1<<leftPos))
			{
                cnt++;
                neigh -= 90;
            }
            else
			{
                cnt++;
                neigh += 60;
            }
        }
    }
    return ((introv) ? -90 * cnt : 60 * cnt) + neigh;
}

int rec(int pos, int i, int e, int inmask, int exmask, int n,int m)
{
    int n_inmask = (inmask<<1) & 63, n_exmask = (exmask<<1) & 63;
    if(pos == (n * m)) 
		return 0;
    if(dp[pos][i][e][inmask][exmask] != -1) 
		return dp[pos][i][e][inmask][exmask];
    int a = rec(pos + 1, i, e, n_inmask, n_exmask, n, m), b = 0, c = 0;
    if(i > 0) 
	{
        b = 360 + rec(pos + 1, i - 1, e, n_inmask + 1, n_exmask, n, m);
        int p = dif(inmask, exmask, n, m, 1, pos);
        b += p;
    }
    if(e > 0) 
	{
        int p = dif(inmask, exmask, n, m, 0, pos);
        c = 120 + rec(pos + 1, i, e - 1, n_inmask, n_exmask + 1, n, m) + p;
    }
    return dp[pos][i][e][inmask][exmask]=max({a, b, c});      
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, x, y, 0, 0, m, n) << endl;
}
