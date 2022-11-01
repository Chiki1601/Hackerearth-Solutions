#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, a[100001], sz[100001];

int find(int u)
{
    if(u == a[u])
		return u;
    a[u] = find(a[u]);
    return a[u];
}

void unite(int A, int b)
{
    int r1 = find(A), r2 = find(b);
    if(r1 == r2)
		return;
    if(sz[r1] < sz[r2])
        swap(r1, r2);
    sz[r1] += sz[r2];
    a[r2] = r1;
    return;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  	for(int i = 0; i < 100001; i++) 
    {
        a[i] = i;
        sz[i] = 1;
    }
  	cin >> n >> m;
  	for(int i = 0; i < m; i++) 
  	{
      	cin >> u >> v;
      	if(find(u) != find(v))
          	unite(u, v);
  	}
  	long long mul = 1;
  	for(int i = 1; i <= n; i++)
  	{
      	if(find(i) == i)
          	mul = (mul * sz[i]) % 1000000007;
  	}
  	cout << mul << "\n";
}
