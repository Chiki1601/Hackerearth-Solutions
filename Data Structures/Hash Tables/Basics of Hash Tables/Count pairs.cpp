#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, k, p, i, ans = 0;
        cin >> n >> k >> p;
        vector<long long> arr(n);
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= p;
        }
        sort(arr.begin(), arr.end());
        vector<pair<long long, long long>> vec;
        for(i = 0; i < n ; i++)
        {
            long long j = i, cnt = 0;
            while(j < n && arr[j] == arr[i])
                cnt++, j++;
            long long x = arr[i];
            if((3 * x * x % p) == k)
                ans += cnt * (cnt - 1) / 2;
            long long y = (((x * x % p) * x % p - k * x % p) % p + p) % p;
            vec.push_back({y, cnt});
            i = j - 1;
        }
        sort(vec.begin(), vec.end());
        for(i = 0; i < vec.size() ; i++)
        {
            long long j = i, lin = 0, sqr = 0;
            while(j < vec.size() && vec[i].first == vec[j].first)
                lin += vec[j].second, sqr += vec[j].second * vec[j].second, j++;
            ans += (lin * lin - sqr) / 2;
            i = j - 1;
        }
        cout << ans << endl;
    }
}
