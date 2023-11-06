#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while(t--)
	{
        int n;
		cin >> n;
        vector<int> v(100005), vv(100005);
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++)
		{
            int a, b;
			cin >> a >> b;
            v[a]++;
            vv[b]++;
            p.push_back({a, b});
        }
        for(int i = 1; i < 100005; i++)
		{
            v[i] += v[i - 1];
            vv[i] += vv[i - 1];
        }
        int ans = n;
        for(int i = 0; i < n; i++)
		{
            int val = v[p[i].second] - vv[p[i].first - 1] - 1;
            ans = min(ans, val);
        }
        cout << ans << "\n";
    }
    return 0;
}
