#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n;
    cin >> k >> n;
    long long v[n];
    for(int h = 0; h < n; h++)
        cin >> v[h];
    long long sum = 0, ans = 0;
    for(int h = n - k; h < n; h++)
    {
        sum += v[h];
        ans = max(ans, sum);
    } 
    for(int h = 0; h < k; h++)
    {
        sum -= v[(h - k + n) % n];
        sum += v[h];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
