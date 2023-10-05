#include <bits/stdc++.h>
using namespace std;
int N, cnt[100005], sz[100005], par[100005];

inline int root(int u) 
{
	if(u == par[u]) 
        return u;
	return root(par[u]);
}

inline bool merge(int u, int v) 
{
	if(u == -1) 
        return false;
	u = root(u), v = root(v);
	if(u == v) 
        return false;
	if(sz[u] < sz[v]) 
        swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
	return true;
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	memset(cnt, 0, sizeof(cnt));
	cin >> N;
    long long w = 0;
	for(int i = 1; i <= N; i++) 
    {
		int X; 
        cin >> X;
		if(++cnt[X] > 1) 
            w += X;
	}
	for(int i = 1; i <= 100000; i++) 
    {
        par[i] = i; 
        sz[i] = 1;
    }
	for(int i = 100000; i >= 1; i--) 
    {
		int prev = -1;
		for(int j = i; j <= 100000; j += i) 
            if(cnt[j]) 
            {
			    w += 1LL * merge(prev, j) * i;
			    prev = j;
		    }
	}
	cout << w;
	return 0;
}
