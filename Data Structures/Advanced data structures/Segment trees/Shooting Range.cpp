#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> lazy;
long long ans[100005], add[100005];
int n, q, k[100005], a[10][100005], b[10][100005], sz = 1;
 
struct tree
{
  	int l, r, s;
} T[5000250];
 
void Add(int l, int r, int x)
{
  	if(l > r) 
	  	return;
  	int L = lower_bound(lazy.begin(), lazy.end(), make_pair(l, -1)) - lazy.begin(), R = lower_bound(lazy.begin(), lazy.end(), make_pair(r + 1, -1)) - lazy.begin() - 1;
  	add[L] += x;
  	add[R + 1] -= x;
}
 
void upd(int x, int v = 1, int tl = 1, int tr = 1000000000)
{
  	if(tl == tr)
  	{
    	T[v].s++;
    	return;
  	}
  	int tm = (tl + tr) / 2;
  	if(x <= tm)
  	{
    	if(!T[v].l) 
			T[v].l = ++sz;
    	upd(x, T[v].l, tl, tm);
  	}
  	else
  	{
    	if(!T[v].r) 
			T[v].r = ++sz;
    	upd(x, T[v].r, tm + 1, tr);
  	}
  	T[v].s = 0;
  	if(T[v].l) 
	  	T[v].s += T[T[v].l].s;
  	if(T[v].r) 
	  	T[v].s += T[T[v].r].s;
}
 
int get(int x, int v = 1, int tl = 1, int tr = 1000000000)
{
  	if(tl == tr) 
	  	return tl;
  	int tm = (tl + tr) / 2;
  	int now = tm - tl + 1 - T[T[v].l].s;
  	if(now >= x) 
	  	return get(x, T[v].l, tl, tm);
  	else 
	  	return get(x - now, T[v].r, tm + 1, tr);
}
 
int main()
{
  	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  	cin >> n;
  	for(int i = 1; i <= n; i++)
  	{
    	cin >> k[i];
    	for(int j = 0; j < k[i]; j++) 
			cin >> a[j][i] >> b[j][i];
  	}
  	cin >> q;
  	for(int i = 1; i <= q; i++)
  	{
    	int x; 
		cin >> x;
    	if(1000000000 - T[1].s < x) 
			continue;
    	x = get(x);
    	upd(x);
    	lazy.push_back(make_pair(x, i));
  	}
  	sort(lazy.begin(), lazy.end());
  	for(int i = 1; i <= n; i++)
  	{
    	int cur = 0;
    	for(int j = 0; j < k[i]; j++)
    	{
      		Add(cur + 1, cur + a[j][i], b[j][i]);
      		cur += a[j][i];
    	}
  	}
  	for(int i = 0; i < lazy.size(); i++)
  	{
    	if(i) 
			add[i] += add[i - 1];
    	ans[lazy[i].second] = add[i];
  	}
  	for(int i = 1; i <= q; i++) 
	  	cout << ans[i] << endl;
  return 0;
}
