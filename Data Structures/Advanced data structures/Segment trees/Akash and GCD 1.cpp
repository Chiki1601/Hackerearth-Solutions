#include <bits/stdc++.h>
using namespace std;
int tot[500005], gs[500005];
long long arr[1000006], b[1000006];
 
void update(int x, long long val) 
{
    for(; x <= 1000000; x += (x & -x)) 
        b[x] = (b[x] + val) % 1000000007;
}
 
long long query(int x)
{
    long long sum = 0;
    for(; x > 0; x -= (x & -x)) 
        sum = (sum + b[x]) % 1000000007;
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i <= 500000; i++) 
        tot[i] = i;
    for(int i = 2; i <= 500000; i++) 
        if(tot[i] == i) 
            for(int j = i; j <= 500000; j += i) 
                tot[j] -= tot[j] / i;
    for(int i = 1; i <= 500000; i++) 
        for(int j = i; j <= 500000; j += i) 
            gs[j] += i * tot[j / i];
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, gs[arr[i]]);
    }
    cin >> q;
    while(q--) 
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if(ch == 'U')
        {
            update(x, gs[y] - gs[arr[x]]);
            arr[x] = y;
        } 
        else 
        {
            long long ans = (query(y) - query(x - 1) + 2 * 1000000007) % 1000000007;
            cout << ans << endl;
        }
    }
    return 0;
}
