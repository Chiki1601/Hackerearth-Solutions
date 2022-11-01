#include<bits/stdc++.h>
using namespace std;
 
bool comp(pair<int, int> p1, pair<int, int> p2) 
{
    return p1.first < p2.first;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
	{
        int n, m;
        cin >> n >> m;
        vector<int> l(m);
        for(int i = 0; i < m; i++) 
            cin >> l[i];
        vector<pair<int, int>> wc(n);
        for(int i = 0; i < n; i++) 
            cin >> wc[i].first;
        long long hi = 0, ans = -1, lo = 1;
        for(int i = 0; i < n; i++) 
		{
            cin >> wc[i].second;
            hi += wc[i].second;
        }
        sort(l.begin(), l.end());
        sort(wc.begin(), wc.end(), comp);
        while(lo <= hi) 
		{
            long long mid = lo + (hi - lo) / 2;
            int j = n - 1;
            long long x = wc[j].second;
            for(int i = m - 1; i >= 0 && j >= 0; i--) 
			{
                long long left = mid;
                while(j >= 0 && left > 0 && l[i] >= wc[j].first) 
				{
                    long long y = x <= left ? x : left;
                    x -= y;
                    left -= y;
                    if(x == 0) 
					{
                        j--;
                        if(j >= 0) 
                            x = wc[j].second;
                    }
                }
                if(j >= 0 && l[i] < wc[j].first) 
                    break;
            }
            if(j < 0) 
			{
                ans = mid;
                hi = mid - 1;
            } 
			else 
                lo = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
