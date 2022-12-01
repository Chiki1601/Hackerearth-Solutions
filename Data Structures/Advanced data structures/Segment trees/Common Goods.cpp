#include<bits/stdc++.h>
using namespace std;
int t, n, k, m, tmp, b[100005], st[100005 << 2];
 
int getMid(int a, int b) 
{
	return a + ((b - a) >> 1);
}
 
void build(int tl, int tr, int i = 0) 
{
	if(tl == tr) 
    {
		st[i] = b[tl];
		return;
	}
	int m = getMid(tl, tr), i1 = i<<1|1;
	build(tl, m, i1);
	build(m + 1, tr, i1 + 1);
	st[i] = max(st[i1], st[i1 + 1]);
}
 
int get(int tl, int tr, int i, int ql, int qr) 
{
	if(ql > qr) 
		return 0;
	if(tl == ql && tr == qr) 
		return st[i];
	int m = getMid(tl, tr), i1 = i << 1 | 1;
	return max(get(tl, m, i1, ql, min(qr, m)), get(m + 1, tr, i1 + 1, max(ql, m + 1), qr));
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) 
    {
		cin >> arr[i];
		b[i] = 100005;
	}
	cin >> m >> tmp;
	int l[m], r[m];
	for(int i = 0; i < m; i++) 
		cin >> l[i] >> r[i];
	cin >> t;
	for(int i = 0; i < t; i++) 
    {
		cin >> k;
		if(!(--arr[k - 1])) 
			b[k - 1] = i;
	}
	build(0, n - 1);
	int cnt[t] = {}, prev = 0;
	for(int i = 0; i < m; i++) 
    {
		int tmp = get(0, n - 1, 0, l[i] - 1, r[i] - 1);
		if(tmp != 100005) 
			cnt[tmp]++;
	}
	for(int i = 0; i < t; i++) 
		cout << (prev += cnt[i]) << " ";
	return 0;
}
