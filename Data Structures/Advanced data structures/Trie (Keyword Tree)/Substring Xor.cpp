#include <bits/stdc++.h>
using namespace std;
     
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, mask = 0, a[100005], b[1 << 21];
    long long m;
    cin >> n >> m;
    m = ((long long) n) * (n + 1) / 2 - m + 1;
    for(int i = 1; i <= n; ++i) 
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] ^ x;
    }
    for(int i = 20; i >= 0; --i) 
    {
        mask <<= 1;
        memset(b, 0, sizeof(b));
        long long num = 0;
        for(int j = 0; num < m && j <= n; ++j) 
        {
            num += b[(a[j] >> i) ];
            ++b[(a[j] >> i)^mask];
        }
        if(num < m) 
        {
            m -= num;
            mask |= 1;
        }
    }
    cout << mask << endl;
}
