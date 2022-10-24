#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, ans, w[1<<20], W[1<<20][3];
 
int get(int x)
{
	if(w[x] == x)
		return x;
	return w[x] = get(w[x]);
}
 
void merge(int a, int b)
{
	w[a] = b;
}
 
int get1(int x, int y)
{
	if (W[x][y] == x)
		return x;
	return get1(W[x][y], y);
}
 
void merge1(int a, int b, int c)
{
	W[a][c] = b;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		w[i] = W[i][1] = W[i][2] = i;
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
	for(int j = 1; j <= 2; j++)
		if(c&j)
		{
			int ta, tb;
			ta = get1(a, j);
			tb = get1(b, j);
			if(ta == tb)
				continue;
			merge1(ta, tb, j);
		}
		if(c != 3)
			continue;
		a = get(a);
		b = get(b);
		if(a == b)
			continue;
		merge(a, b);
		++ans;
	}
	ans = (n - 1 - ans) * 2 + ans;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 2; j++)
			if (W[i][j] == i)
				++cnt;
			if (cnt > 2)
			{
				cout << -1 << endl;
				return 0;
			}
	cout << m - ans << endl;
	return 0;
}
