#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<pair<int, int>>> v(k);
    while(n--)
    {
        int l, r, z;
        cin >> l >> r >> z;
        l--,r--,z--;
        v[z].insert(make_pair(l, r));
    }
    long long arr[m + 1] = {0}, ans = 1, cnt = 0;
    for(int i = 0; i < k; i++)
    {
        auto s = v[i];
        for(auto it = s.begin(); it != s.end(); it++)
        {
            int x = it->first, y = it->second;
            it++;
            while(it != s.end() && it->first <= y)
            {
                y = max(y, it->second);
                it++;
            }
            it--;
            arr[x]++,arr[y + 1]--;
        }
    }
    for(int i = 0; i < m; i++)
	{
        cnt += arr[i];
        ans = (ans * (k - cnt)) % 1000003;
    }
    cout << ans;
}
