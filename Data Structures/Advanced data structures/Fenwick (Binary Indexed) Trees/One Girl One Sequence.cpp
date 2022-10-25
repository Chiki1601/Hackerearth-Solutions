#include <bits/stdc++.h>
using namespace std;
int fen[1000008], n;
 
void add(int ind, int x)
{
	for(; ind <= n; ind += ind & -ind)
		fen[ind] += x;
	return;
}
 
int get(int ind)
{
	int sum = 0;
	for(; ind; ind -= ind & -ind)
		sum += fen[ind];
	return sum;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x;
	cin >> n >> x;
    pair<int, int> a[1000008];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	long long ans = 1LL * x * n, inv = 0;
	for(int i = n; i >= 1; i--) 
	{
		int ind = a[i - 1].second;
		inv += get(ind - 1);
		ans = min(ans, x * 1LL * (i - 1) + inv);
		add(ind, 1);
	}
	cout << ans << endl;
}
