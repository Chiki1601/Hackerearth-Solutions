#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while(t--)
    {
        int n, m;
        long long int d,  money = LLONG_MAX;
        cin >> n >> m >> d;
        vector<long long int> arr(n), cost(m);
        for(auto &x : arr)
            cin >> x;
        for(auto &x : cost)
            cin >> x;
        sort((arr).begin(), (arr).end());
        sort((cost).begin(), (cost).end());
        int ans, l = 0, r = min(n, m);
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long int d_req = 0, total = 0;
            for (int i = 0; i < mid; i++)
            {
                d_req += max(0ll, cost[mid - i - 1] - arr[n - 1 - i]);
                total += cost[mid - i - 1];
            }
            if(d_req <= d)
            {
                l = mid + 1;
                ans = mid;
                money = max(0ll, total - d);
            }
            else
                r = mid - 1;
        }
        cout << ans << " " << money << endl;
    }
    return 0;
} 
