#include<bits/stdc++.h>
using namespace std;
int BIT[27][200001];
 
void update(int loc, int x, int vl)
{
	for(int i = x; i <= 200001; i += (i & -i))
		BIT[loc][i] += vl;
}
 
int query(int loc, int x)
{
	int ans = 0;
	for(int i = x; i >= 1; i -= (i & -i))
		ans += BIT[loc][i];
	return ans;
}
 
int remocu(int loc, int x)
{
	int mid, lb = 1, ub = 200001, ans;
	while(lb <= ub)
    {
		mid = ((lb + ub) >> 1);
		if(query(loc, mid) >= x)
        {
			ans = mid;
			ub = mid - 1;
		}
		else
			lb = mid + 1;
	}
	update(loc, ans, -1);
	return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k, i, x, n;
	char c;
    bool vis[2000004];
    string s;
	cin >> s;
	cin >> n;
	for(i = 0; i < s.size(); i++)
		update(s[i] - 'a', i + 1, 1);
	while(n--)
    {
		cin >> x >> c;
		c -= 'a';
		int le = remocu(c, x);
		vis[le - 1] = 1;
	}
	for(i = 0; i < s.size(); i++)
    {
		if(vis[i] == 0)
			cout << s[i];
	}
	cout << endl;
	return 0;
}
