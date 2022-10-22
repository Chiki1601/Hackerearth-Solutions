#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, a[100005], pref[100005], suf[100005];
 
long long int power(long long int a, long long int b)
{
    long long int value;
    if(b == 0)
        return 1;
    else if(b % 2 == 0)
    {
        value = power(a, b / 2) % 1000000007;
        return(value * value) % 1000000007;
    }
    else
    {
        value = power(a, b / 2) % 1000000007;
        return ((a * value) % 1000000007 * (value)) % 1000000007;
    }
}
 
string f(long long int n) 
{
    vector<long long int> v;
    long long int i;
    if(n == 0)
        return "00";
    string s = "0";
    while(n) 
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse((v).begin(), (v).end());
    for(i = 0; i < v.size(); i++) 
        s += (v[i] + '0');
    return s;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--) 
    {
        long long int n, m, k, ans = 0, i, sum = 0;
        cin >> n >> m >> k;
        for(i = 1; i < 1 + n; i++) 
        {
            cin >> a[i];
            pref[i] = a[i];
            suf[i] = a[i];
            sum += a[i];
        }
        sum *= m;
        if(sum <= k) 
        {
            long long int temp = (n * m) % 1000000007;
            ans = (temp * (temp + 1)) % 1000000007;
            ans = (ans * power(2, 1000000005)) % 1000000007;
            cout << ans << endl;
            continue;
        }
        sum /= m;
        for(i = 2; i < 1 + n; i++) 
            pref[i] += pref[i - 1];
        for(i = n - 1; i > 0; i--) 
            suf[i] += suf[i + 1];
        for(i = 1; i < 1 + n; i++) 
        {
            if(suf[i] >= k) 
            {
                long long int temp = -1, l = i, r = n;
                while(l <= r) 
                {
                    long long int mid = (l + r) / 2;
                    if((pref[mid] - pref[i - 1]) <= k) 
                    {
                        temp = mid;
                        l = mid + 1;
                    } 
                    else 
                        r = mid - 1;
                }
                if(temp != -1) 
                    ans = (ans + (m * (temp - i + 1))) % 1000000007;
                continue;
            }
            if((suf[i] + (m - 1) * sum) <= k) 
            {
                long long int temp = (m * (2 * (n - i + 1) + (m - 1) * n));
                temp /= 2;
                ans = (ans + temp) % 1000000007;
                continue;
            }
            long long int cnt = (k - suf[i]) / sum;
            cnt++;
            long long int temp = (cnt * (2 * (n - i + 1) + (cnt - 1) * n));
            temp /= 2;
            temp %= 1000000007;
            ans = (ans + temp) % 1000000007;
            cnt--;
            long long int val = (k - suf[i] - cnt * sum), l = 1, r = n, idx = 0;
            while(l <= r) 
            {
                long long int mid = (l + r) / 2;
                if(pref[mid] <= val) 
                {
                    idx = mid;
                    l = mid + 1;
                } 
                else 
                    r = mid - 1;
            }
            long long int no = (n - i + 1) + (cnt * n) + idx;
            no %= 1000000007;
            ans = (ans + (no * (m - cnt - 1))) % 1000000007;
        }
        cout << ans << endl;
    }
}
