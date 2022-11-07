#include<bits/stdc++.h>
using namespace std;
int n, h, a[210031], x[210031], dp[210031], answ, t[840124];
vector<pair<int, int>> order;
 
void update(int v, int tl, int tr, int ps, int val)
{
	if(tl == tr)
	{
		t[v] = max(t[v], val);
		return ;
	}
	int tm = tl + tr;
	tm /= 2;
	if(ps <= tm)
		update(v * 2, tl, tm, ps, val);
	else
		update(v * 2 + 1, tm + 1, tr, ps, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}
 
int get(int v, int tl, int tr, int l, int r)
{
	if(l > r)
		return 0;
	if(tl == l && tr == r)
		return t[v];
	int tm = tl + tr;
	tm /= 2;
	return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> x[i];
		x[i] += 100000;
		order.push_back(make_pair(a[i], x[i]));
	}
	sort(order.begin(), order.end());
	for(int i = 0; i < order.size(); i++)
	{
		if(i > 0 && order[i].first != order[i - 1].first)
		{
			int j = i - 1;
			for(int q = j; q >= 0; --q)
			{
				if(order[q].first != order[j].first)
					break;
				update(1, 0, 200000, order[q].second, dp[q]);
			}
		}
		int l_thold, r_thold;
		if(order[i].second < 100000)
		{
			l_thold = 100001; 
			r_thold = 200000;
		}
		else
		{
			l_thold = 0; 
			r_thold = 99999;
		}
		l_thold = max(l_thold, order[i].second - h);
		r_thold = min(r_thold, order[i].second + h);
		int here = get(1, 0, 200000, l_thold, r_thold);
		dp[i] = here + 1;
	}
	int ans = 0;
	for(int i = 0; i < order.size(); i++)
		ans = max(ans, dp[i] - 1);
	cout << ans << endl;
	cin.get(); 
	cin.get();
	return 0;
}
