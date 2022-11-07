#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long t = 0, i = 0, n = 0, ecnt = 0, erange = 0, tsum = 0, p = 0, mrange = 0, st = 0, et = 0, ts = 0, cost[26] = {};
    cin >> t;
    while(t--) 
	{
        cin >> n;
        for(i = 1; i <= 26; ++i) 
			cin >> cost[i];
        p = n * 12;
        ecnt = p / 26;
        erange = abs(p - (26 * ecnt));
        if(ecnt > 0) 
			mrange = 26;
        else 
			mrange = erange;
        tsum = 0;
        for(i = 1; i <= mrange; ++i) 
		{
            st = cost[i];
            et = cost[i] + max(ecnt-1, 0LL);
            ts = ((et * (et + 1)) / 2) - (((st) * (st - 1)) / 2);
            tsum += ts;
            if(i <= erange && ecnt > 0) 
				tsum += cost[i] + ecnt;
        }
        cout << tsum << endl;
    }
    return 0;
}
