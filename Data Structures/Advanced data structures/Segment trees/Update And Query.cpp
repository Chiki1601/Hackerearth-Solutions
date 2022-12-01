#include<bits/stdc++.h>
using namespace std;
long long y, a, b, arr[200005], st[200005 << 2][2];
 
int getMid(int a, int b) 
{
	return a + ((b - a) >> 1);
}
 
void build(int tl, int tr, int i = 0) 
{
	if(tl == tr) 
    {
		st[i][0] = st[i][1] = arr[tl];
		return;
	}
	int m = getMid(tl, tr), i1 = i<<1|1;
	build(tl, m, i1);
	build(m + 1, tr, i1 + 1);
	st[i][0] = min(st[i1][0], st[i1 + 1][0]);
	st[i][1] = max(st[i1][1], st[i1 + 1][1]);
}
 
void update(int tl, int tr, int i, int pos, long long val) 
{
	if(pos > tr || pos < tl) 
		return;
	if(tl == tr) 
    {
		st[i][0] = st[i][1] = arr[tl] = val;
		return;
	}
	int m = getMid(tl, tr), i1 = i<<1|1;
	update(tl, m, i1, pos, val);
	update(m + 1, tr, i1 + 1, pos, val);
	st[i][0] = min(st[i1][0], st[i1 + 1][0]);
	st[i][1] = max(st[i1][1], st[i1 + 1][1]);
}
 
int getInd(int tl, int tr, int i, long long val, bool j) 
{
	if(tl == tr)
		return tl;
	int m = getMid(tl, tr), i1 = i<<1|1;
	if((j && st[i1][1] > val) || (!j && st[i1][0] < val)) 
		return getInd(tl, m, i1, val, j);
	if((j && st[i1 + 1][1] > val) || (!j && st[i1 + 1][0] < val)) 
		return getInd(m + 1, tr, i1 + 1, val, j);
}
 
void compute(int tl, int tr, int i, int ql, int qr, long long mn, long long mx) 
{
	if(ql > qr || (a != -1 && b != -1)) 
		return;
	if(ql == tl && qr == tr) 
    {
		if(a == -1 && st[i][0] < mn) 
			a = getInd(tl, tr, i, mn, 0);
		if(b == -1 && st[i][1] > mx) 
			b = getInd(tl, tr, i, mx, 1);
		return;
	}
	int m = getMid(tl, tr), i1 = i<<1|1;
	compute(tl, m, i1, ql, min(qr, m), mn, mx);
	compute(m + 1, tr, i1 + 1, max(ql, m + 1), qr, mn, mx);
}
 
long long get(int tl, int tr, int i, int ql, int qr, int j) 
{
	if(ql > qr)
		return (j) ? -1000000007 : 1000000007;
	if(ql == tl && qr == tr) 
		return st[i][j];
	int m = getMid(tl, tr), i1 = i<<1|1;
	if(j) 
		return max(get(tl, m, i1, ql, min(qr, m), j), get(m + 1, tr, i1 + 1, max(ql,  m + 1), qr, j));
	return min(get(tl, m, i1, ql, min(qr, m), j), get(m + 1, tr, i1 + 1, max(ql, m + 1), qr, j));
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t, x;
	cin >> n >> t;
	for(int i = 0; i < n; i++) 
		cin >> arr[i];
	build(0, n - 1);
	char ch;
	while(t--) 
    {
        cin >> ch >> x >> y;
		x--;
		if(ch == 'Q') 
        {
			a = b = -1;
			long long mn = arr[x] - y, mx = arr[x] + y;
			if(mn > mx) 
				cout << "-1" << " " << "-1" << endl;
			else 
            {
				compute(0, n - 1, 0, x, n - 1, mn, mx);
				int r = min(a, b);
				if(r == -1)
					r = (a != -1) ? a : ((b != -1) ? b : n);
				long long res = max(get(0, n - 1, 0, x, r - 1, 1) - arr[x], arr[x]-get(0, n - 1, 0, x, r - 1, 0));
				cout << r - x << " " << res << endl;
			}
			continue;
		}
		update(0, n - 1, 0, x, y);
	}
	return 0;
}
