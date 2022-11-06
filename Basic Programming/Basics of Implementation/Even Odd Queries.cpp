#include <bits/stdc++.h>
using namespace std; 
int ct[100005][2];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, q, i;
        cin >> n >> q;
        for(int i = 1; i < n + 1; i++)
        {
            int x;
            cin >> x;
            ct[i][x % 2] = ct[i - 1][x % 2] + 1;
            ct[i][1 - x % 2] = ct[i - 1][1 - x % 2];
        }
        while(q--)
        {
            int l, r, k;
            cin >> k >> l >> r;
            int q = r - l + 1, p = ct[r][k] - ct[l - 1][k];
            if(p == 0 || p == q)
                cout << p / q << endl;
            else
            {
                int g = __gcd(p, q);
                p /= g;
                q /= g;
                cout << p << " " << q << "\n";
            }
        }
    }
    return 0;
}
