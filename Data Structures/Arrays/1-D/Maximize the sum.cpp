#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; 
	cin >> t;
    while(t--)
	{
        long long  n, k, ans = 0; 
		cin >> n >> k;
        unordered_map<long long , long long >m;
        for(int i = 0; i < n; i++)
		{
            int a; 
			cin >> a;
            m[a] += a;
        }
        vector<long long >v;
        for(auto i : m)
		{
            if(i.second > 0)
            v.push_back(i.second);
        }
        sort(v.begin(), v.end(), greater<long long >());
        for(int i = 0; i < min(k, (long long )v.size()); i++)
        ans += v[i];
        cout << ans << endl;
    }
}
