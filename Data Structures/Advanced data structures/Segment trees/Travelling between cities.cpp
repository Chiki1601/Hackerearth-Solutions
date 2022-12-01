#include<bits/stdc++.h>
using namespace std;
vector<int> st[1000001];
int comp[10000001];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t, a[1000001];
    cin >> t;
    while(t--)
    {
        vector<pair<int, int> > v;
        int n, k, q, idx = 1;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            v.push_back(make_pair(a[i], i));
        }
        sort(v.begin(), v.end());
        comp[v[0].second] = 1;
        st[1].push_back(v[0].second);
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i].first - v[i - 1].first <= k)
                comp[v[i].second] = comp[v[i - 1].second];
            else
                comp[v[i].second] = ++idx;
            st[comp[v[i].second]].push_back(v[i].second);
        }
        for(int i = 1; i <= idx; i++)
            sort(st[i].begin() , st[i].end());
        while(q--)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int id = comp[x];
            cout << upper_bound(st[id].begin(), st[id].end(), r) - upper_bound(st[id].begin(), st[id].end(), l - 1) << endl;
        }
        for(int i = 1; i <= idx; i++)
            st[i].clear();
        v.clear();
    }
}
