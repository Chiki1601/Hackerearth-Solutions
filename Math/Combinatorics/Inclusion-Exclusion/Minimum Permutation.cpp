#include <bits/stdc++.h>
using namespace std;

int minPermutation(int n, vector<int> &a)
{
	a.push_back(a.back());
	for(int i = n - 1; i > 0; i--)
		a[i] = a[i - 1];
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(pos[a[i]] == 0)
			pos[a[i]] = i;
		if(i + 1 <= n && a[i] < a[i + 1])
			return 0;
	}
	long long ans = 1, last = n + 1;
	for(int i = 1; i <= n; i++)
	{
		if(pos[i] == 0)
		{
			if(i == 1)
				ans = 0;
			else if(((n - i + 1) - last + 1) > 0)
				ans = (ans * ((n - i + 1) - last + 1)) % 1000000007;
			else
				ans = 0;
		}
		else
			last = pos[i];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &ele : a)
			cin >> ele;
		cout << minPermutation(n, a) << "\n";
	}
}
