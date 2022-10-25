#include<bits/stdc++.h>
using namespace std;
long long int t, n, a[100005], b[100005], c[100005], bit[100005], lft[100005], rght[100005];
 
void upd(long long int idx)
{
    while(idx < 100004)
    {
        bit[idx]++;
        idx += (idx & (-idx));
    }
}
 
long long int qry(long long int idx)
{
    long long int sm = 0;
    while(idx > 0)
    {
        sm += bit[idx];
        idx -= (idx & (-idx));
    }
    return sm;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int i, j, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            c[a[i]] = i;
        }
        for(i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] = c[b[i]];
        }
        long long int ans = 0;
        memset(bit, 0, sizeof bit);
        for(i = 1; i <= n; i++)
        {
            lft[i] = qry(b[i] - 1);
            upd(b[i]);
        }
        memset(bit, 0, sizeof bit);
        for(i = n; i >= 1; i--)
        {
            rght[i] = qry(100002) - qry(b[i]);
            upd(b[i]);
        }
        for(i = 1; i <= n; i++)
            ans += lft[i] * rght[i];
        cout << ans << "\n";
    }   
    return 0;
}
