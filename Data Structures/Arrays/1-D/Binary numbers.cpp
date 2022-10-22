#include <bits/stdc++.h>
using namespace std;
long long cnt[41];
 
void solve() 
{
    long long k;
    cin >> k;
    long long pos = lower_bound(cnt, cnt + 40, k) - cnt;
    string s;
    if(cnt[pos] > k) 
        pos--;
    for(long long i = pos; i >= 1; i--)
    {
        if(k >= cnt[i])
        {
            k -= cnt[i];
            s.push_back('1');
        }
        else 
            s.push_back('0');
    }
    cout << s << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cnt[0] = 0;
    cnt[1] = 1;
    cnt[2] = 2;
    for(long long i = 3; i <= 40; i++) 
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
