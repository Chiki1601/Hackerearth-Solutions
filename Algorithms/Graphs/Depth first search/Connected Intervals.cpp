#include <bits/stdc++.h>
using namespace std;
int n, m, p[100500], rk[100500], ox[100500], ork[100500], ptr, nc,cnt1, cnt2, u[100500], v[100500], res[100500], cnt = 0;
bool b[100500];
vector<int> used;
 
void clear() 
{
    for(int i : used) 
	{
        p[i] = i; 
		rk[i] = 0; 
		b[i] = 0;
    }
    ptr = 0;
    nc = n;
    used.clear();
}
 
int get(int x) 
{
    while(x != p[x]) 
		x = p[x];
    return x;
}
 
int getf(int x) 
{
    return x == p[x] ? x : (p[x] = get(p[x]));
}
  
void unite(int x, int y) 
{
    ++cnt1;
    x = get(x), y = get(y);
    if(x == y) 
		return;
    if(rk[x] > rk[y]) 
		swap(x, y);
    ox[ptr] = x;
    ork[ptr] = rk[y];
    if(rk[x] == rk[y]) 
		++rk[y];
    p[x] = y;
    --nc;
    ++ptr;
}
 
void unitef(int x, int y) 
{
    ++cnt2;
    if(!b[x]) 
	{
		b[x] = 1; 
		used.push_back(x);
	}
    if(!b[y]) 
	{
		b[y] = 1; 
		used.push_back(y);
	}
    x = getf(x), y = getf(y);
    if(x == y) 
		return;
    if(rk[x] > rk[y]) 
		swap(x, y);
    if(rk[x] == rk[y]) 
		++rk[y];
    p[x] = y;
    --nc;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
	{
		cin >> u[i] >> v[i]; 
		--u[i]; 
		--v[i];
	}
    for(int i = 0; i < n; ++i)
	{
		p[i] = i; 
		rk[i] = 0; 
		b[i] = 0;
	}
    ptr = 0;
    nc = n;
    memset(res, -1, sizeof res);
    for(int L = 0; L < m; L += 400) 
	{
        assert(ptr == 0);
        clear();
        int R = min(m, L + 400);
        int r = R;
        for(int l = L; l < R; ++l) 
		{
            for(int i = l; i < R; ++i) 
			{
                unite(u[i], v[i]);
                if(nc == 1) 
				{
                    res[l] = i;
                    break;
                }
            }
            if(res[l] != -1 && r > R) 
                res[l] = r - 1;
            int r1 = r;
            if(res[l] == -1) 
			{
                while(r1 < m) 
				{
                    unite(u[r1], v[r1]);
                    if(nc == 1) 
					{
                        res[l] = r1;
                        ++r1;
                        break;
                    }
                    ++r1;
                }
            }
            if(res[l] == -1) 
                goto final;
            while(ptr) 
			{
				++nc;
				--ptr;
				int x = ox[ptr];
				int y = p[x];
				rk[y] = ork[ptr];
				p[x] = x;
			}
            while(r < r1) 
			{
                unitef(u[r], v[r]);
                ++r;
            }
        }
    }
    final:;
    long long ans = 0;
    for(int i = 0; i < m; ++i)
		if(res[i] != -1) 
        	ans += m - res[i];
    cout << ans << endl;
    return 0;
}
