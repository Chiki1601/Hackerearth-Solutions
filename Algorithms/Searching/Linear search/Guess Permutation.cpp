#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) 
	{
        int n, sum = 0, fl = 1; 
		cin >> n;
        vector<int> a(n), ans(n + 1, -1);
        for(int i = 0; i < n; i++) 
			cin >> a[i];
        map<int, int> m;
        m[0]++;
        for(auto u : a) 
		{
            sum += u;
            if(m.count(sum)) 
                fl = 0;
            m[sum] = 1;
        }
        if(fl) 
		{
            int l = 1, r = n + 1;
            while(l <= r) 
			{
                int mid = (r + l) / 2;
                vector<int> p(n + 1);
                int mx = mid, mn = mid;
                p[0] = mid;
                for(int i = 0; i < n; i++) 
				{
                    p[i + 1] = p[i] + a[i];
                    mx = max(mx, p[i + 1]);
                    mn = min(mn, p[i + 1]);
                }
                if(mx > n + 1) 
                    r = mid - 1;
                else if(mn < 1) 
                    l = mid + 1;
                else
				{
                    ans = p;
                    break;
                }
            }
        }
        if(ans[0] >= 1) 
		{
            for(int i = 0; i <= n; i++) 
                cout << ans[i] << " \n"[i == n];
        } 
		else 
            cout << "-1" << endl;
    }
    return 0;
}
