#include<bits/stdc++.h>
using namespace std;
int n, a[100005], bsize, Ly, Ry, st[400020][319], carry[100005];
 
void updateY(int x, int y, int posX)
{
	x++;
	while(x < 319)
	{
		st[posX][x] += y;
		x += (-x) & x;
	}
}
 
void updateCarry(int x, int y)
{
	x++;
	while(x < 100005)
	{
		carry[x] += y;
		x += (-x) & x;
	}
}
 
void updateX(int x, int y, int z, int posX = 1, int l = 0, int r = n - 1)
{
	updateY(y, z, posX);
	if(l == r)
		return;
	int mi = (l + r) / 2;
	if(l <= x and x <= mi) 
		updateX(x, y, z, 2 * posX, l, mi);
	else 
		updateX(x, y, z, 2 * posX + 1, mi + 1, r);
}
 
int getSumY(int posX, int pos)
{
	pos++;
	int ans = 0;
	while(pos > 0)
	{
		ans += st[posX][pos];
		pos &= pos - 1;
	}
	return ans;
}
 
int getSumCarry(int pos)
{
	pos++;
	int ans = 0;
	while(pos > 0)
	{
		ans += carry[pos];
		pos &= pos - 1;
	}
	return ans;
}
 
int queryY(int x, int y, int posX)
{
	if(x > y) 
		return 0;
	return getSumY(posX, y) - getSumY(posX, x - 1);
}
 
int queryCarry(int x, int y)
{
	return getSumCarry(y) - getSumCarry(x - 1);
}
 
int solveKthMex(int &k, int posX = 1, int l = 0, int r = n - 1)
{
	if(l == r)
	{
		k -= 1 - queryY(Ly, Ry, posX) - queryCarry(l, r);
		return l + k;
	}
	int mi = (l + r) / 2;
	int zeroesL = mi - l + 1 - queryY(Ly, Ry, 2 * posX) - queryCarry(l, mi);
	if(k <= zeroesL)
		return solveKthMex(k, 2 * posX, l, mi);
	else
	{
		k -= zeroesL;
		return solveKthMex(k, 2 * posX + 1, mi + 1, r);
	}
}
 
int getKthMex(int &k)
{
	int total = n - queryY(Ly, Ry, 1) - queryCarry(0, n - 1);
	if(total < k)
	{
		k -= total;
		return n + k - 1;
	}
	else 
		return solveKthMex(k);
}
 
int solve(int L, int R, int k)
{
	int lenp = 0, ans, positions[638];
	while(L % bsize and L <= R)
	{
		positions[lenp++] = a[L];
		L += 1;
	}
	Ly = L / bsize;
	Ry = Ly;
	while(L + bsize - 1 <= R)
	{
		Ry += 1;
		L += bsize;
	}
	while(L <= R)
	{
		positions[lenp++] = a[L];
		L += 1;
	}
	Ry -= 1;
	for(int i = 0; i < lenp; i++)
		updateCarry(positions[i], 1);
	ans = getKthMex(k);
	for(int i = 0; i < lenp; i++)
		updateCarry(positions[i], -1);
	return ans;
}
 
void modify(int x, int y)
{
	int valX = a[x], valY = a[y], bidX = x / bsize, bidY = y / bsize;
	updateX(valX, bidX, -1);
	updateX(valY, bidX, 1);
	updateX(valX, bidY, 1);
	updateX(valY, bidY, -1);
	swap(a[x], a[y]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int op, x, y, k, ans = 0, T = 1, q, len;
	cin >> n;
	bsize = sqrt(n);
	len = (n + bsize - 1) / bsize;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	for(int i = 0; i < n; i++)
		updateX(a[i], i / bsize, 1);
	cin >> q;
	while(q--)
	{
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y;
			x ^= ans;
			y ^= ans;
			x -= 1; 
			y -= 1;
			modify(x, y);
		}
		else
		{
			cin >> x >> y >> k;
			x ^= ans;
			y ^= ans;
			k ^= ans;
			assert(1 <= min(x, y) and max(x, y) <= n);
			x -= 1;
			y -= 1;
			if(x > y) 
				swap(x, y);
			ans = solve(x, y, k);
			cout << ans << "\n";
		}
	}
	return 0;
}
