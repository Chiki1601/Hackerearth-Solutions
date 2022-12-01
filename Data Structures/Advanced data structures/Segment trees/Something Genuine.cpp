#include<bits/stdc++.h>
using namespace std;
long long st[200005 << 2][2] = {}, lazy[200005 << 2] = {};
 
int getMid(int a, int b) 
{
	return a + ((b - a) >> 1);
}
 
void lazyPropagate(int i, int d) 
{
	if(!lazy[i]) 
		return;
	long long tmp = 1LL * d * lazy[i];
	st[i][1] = (st[i][1] + (((((2 * st[i][0]) % 1000000007) + tmp) % 1000000007) * lazy[i]) % 1000000007) % 1000000007;
	st[i][0] = (st[i][0] + tmp) % 1000000007;
	if(d > 1) 
    {
		int i1 = i<<1|1;
		lazy[i1] += lazy[i];
		lazy[i1 + 1] += lazy[i];
	}
	lazy[i] = 0;
}
 
void update(int tl, int tr, int i, int ql, int qr) 
{
	lazyPropagate(i, tr - tl + 1);
	if(ql > qr) 
		return;
	if(ql == tl && qr == tr) 
    {
		lazy[i]++;
		lazyPropagate(i, tr - tl + 1);
		return;
	}
	int m = getMid(tl, tr), i1 = i<<1|1;
	update(tl, m, i1, ql, min(qr, m));
	update(m + 1, tr, i1 + 1, max(ql, m + 1), qr);
	st[i][0] = (st[i1][0] + st[i1 + 1][0]) % 1000000007;
	st[i][1] = (st[i1][1] + st[i1 + 1][1]) % 1000000007;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int pos[200005] = {}, n, k;
    long long res = 0;
    cin >> n;
	for(int i = 0; i < n; i++) 
    {
		cin >> k;
		update(0, n - 1, 0, pos[k], i);
		res += st[0][1];
		res %= 1000000007;
		pos[k] = i + 1;
	}
	cout << res;
	return 0;
}
