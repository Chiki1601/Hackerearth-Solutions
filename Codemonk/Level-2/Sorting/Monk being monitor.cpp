#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int i, a[100001], n, req[100001], index = 0, diff;
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> a[i];
		unordered_map<int, int>mp;
		for(i = 0; i < n; i++)
			mp[a[i]]++;
		for(auto x : mp)
			req[index++] = x.second;
		sort(req, req + index);
        diff = req[index - 1] - req[0];
        if(diff > 0) 
        	cout << diff << endl;
		else
        	cout << -1 << endl;
	}
    return 0;
}
