#include<bits/stdc++.h>
using namespace std;
int t, n, l, r, st[1000005 << 2][4] = {}, lazy[1000005 << 2] = {}, emp[4] = {}, a[4];
 
int getMid(int a, int b) 
{
	return a + ((b - a) >> 1);
}
 
void build(int tl, int tr, int i = 0) 
{
	if(tl == tr) 
    {
		st[i][0] = 1;
		return;
	}
	int m = getMid(tl, tr), i1 = i << 1 | 1;
	build(tl, m, i1);
	build(m + 1, tr, i1 + 1);
	for(int j = 0; j < 4; j++) 
		st[i][j] = st[i1][j] + st[i1 + 1][j];
}
 
void lazyPropagate(int i, bool ch) 
{
	if(!lazy[i]) 
		return;
	int tmp[4];
	copy(st[i], st[i] + 4, tmp);
	for(int j = 0; j < 4; j++) 
    {
		int ii = (j+lazy[i])%4;
		if(ii < 0) 
			ii += 4;
		st[i][ii] = tmp[j];
	}
	if(ch) 
    {
		int i1 = i << 1 | 1;
		lazy[i1] += lazy[i];
		lazy[i1 + 1] += lazy[i];
	}
	lazy[i] = 0;
}
 
void update(int tl, int tr, int i, int ql, int qr, int val) 
{
	lazyPropagate(i, tl ^ tr);
	if(ql > qr)
		return;
	if(ql == tl && qr == tr) 
    {
		lazy[i] += val;
		lazyPropagate(i, tl ^ tr);
		return;
	}
	int m = getMid(tl, tr), i1 = i << 1 | 1;
	update(tl, m, i1, ql, min(qr, m), val);
	update(m + 1, tr, i1 + 1, max(ql, m + 1), qr, val);
	for(int j = 0; j < 4; j++) 
		st[i][j] = st[i1][j] + st[i1+1][j];
}
 
void get(int tl, int tr, int i, int ql, int qr) 
{
	lazyPropagate(i, tl ^ tr);
	if(ql > qr) 
		return;
	if(ql == tl && qr == tr) 
    {
		for(int j = 0; j < 4; j++) 
			a[j] += st[i][j];
		return;
	}
	int m = getMid(tl, tr), i1 = i << 1 | 1;
	get(tl, m, i1, ql, min(qr, m));
	get(m + 1, tr, i1 + 1, max(ql, m + 1), qr);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t;
	build(0, n - 1);
    char c;
	while(t--) 
    {
		cin >> c >> l >> r;
		l--, r--;
		if(c == 'Q') 
        {
			memset(a, 0, sizeof(a));
			get(0, n - 1, 0, l, r);
			int res = 0;
			for(int i = 0; i < 4; i++) 
				res = max(res, a[i]);
			cout << res << endl;
			continue;
		}
        long long k;
		cin >> k;
		k %= 4;
		update(0, n - 1, 0, l, r, (c == 'C') ? k : -k);
	}
}
