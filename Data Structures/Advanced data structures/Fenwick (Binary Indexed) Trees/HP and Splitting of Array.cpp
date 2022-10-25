#include <bits/stdc++.h>
using namespace std;
 
void update(int pos, int val, int n, vector<int>&tree)
{
	tree[pos] += val;
	while((pos + (pos & (-pos))) <= n)
	{
		pos += (pos & (-pos));
		tree[pos] += val;
	}
}
 
long long query(int idx, vector<int>&tree)
{
	long long ans = tree[idx];
	while((idx & (idx - 1)) > 0)
	{
		idx = (idx & (idx - 1));
		ans += tree[idx];
	}
	return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int>arr(n), tree(1000001,0);
		long long ans = 0;
		for(int i = 0; i < n; i++) 
            cin >> arr[i];
		for(int i = n - 1; i >= 0; i--)
		{
			ans += (query(arr[i] - 1, tree));
			update(arr[i], 1, 1000000, tree);
		}
		for(int i = 0; i < n; i++)
		{
			int temp = query(arr[i] - 1, tree);
			ans = ans - (temp << 1) - 1 + n;
			cout << ans << " ";
		}
		cout << endl;
	}
}
