#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int n, q, u[333][500], sz[333], las = 0;
	vector<int> v, vv, idx[100002];
    cin >> n >> q;
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for(int i = 0; i < n; i++) 
	{
        int a;
        cin >> a;
        assert(1 <= a);
        assert(a <= 1000000000);
        v.push_back(a);
        vv.push_back(a);
    }
    sort(vv.begin(), vv.end());
    for(int i = 0; i < v.size(); i++) 
	{
        v[i] = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
        idx[v[i]].push_back(i);
    }
	bool ex[100002];
    for(int i = 0; i < n; i += 333) 
	{
        memset(ex, false, sizeof(ex));
        for(int j = i; j < n; j++) 
		{
            if(ex[v[j]])
				continue;
            ex[v[j]] = true;
            u[i / 333][sz[i / 333]] = v[j];
            sz[i / 333]++;
            if(sz[i / 333] == 500)
				break;
        }
    }
	set<int> s;
    while (q--) 
	{
        int a, b;
        cin >> a >> b;
        assert(1 <= a && a <= n && 1 <= b && b <= n);
        int l = (a + las) % n + 1, r = (b + las) % n + 1;
        l--;
        r--;
        assert(0 <= l && 0 <= r);
        int belong = l / 333, ans = INT_MAX, pr = -1;
        s.clear();
        bool en = false;
        for(int i = 0; i < sz[belong]; i++) 
		{  
            int val = u[belong][i];
            int lef = lower_bound(idx[val].begin(), idx[val].end(), l) - idx[val].begin(), rig = upper_bound(idx[val].begin(), idx[val].end(), r) - idx[val].begin();
            int oc = rig - lef;
            if(oc == 0)
				continue;
            if(s.count(oc)) 
			{
                en = true;
                break;
            }
            s.insert(oc);
        }
        if(en) 
		{
            puts("0");
            las = 0;
            continue;
        }
        if (s.size() == 1) 
		{
            puts("-1");
            las = -1;
            continue;
        }
        for (auto el : s) 
		{
            if (pr != -1)
                ans = min(ans, el - pr);
            pr = el;
        }
        cout << ans << endl;
        las = ans;
    }
    return 0;
}
