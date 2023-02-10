#include <bits/stdc++.h>
using namespace std;
char s[100100], t[100100];
int n, vow[100100], nv, m, a[100100], q;
long long c[100100];
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = strlen(s);
    for(int i = 0; i < n; ++i) 
    {
        int is_v = ('a' == s[i] || 'e' == s[i] || 'i' == s[i] || 'o' == s[i] || 'u' == s[i]);
        vow[i + 1] = vow[i] + is_v;
        if (is_v) 
            t[nv++] = s[i];
    }
    cin >> m;
    for(int i = 0; i < m && cin >> a[i]; ++i)  
    {
        int x = abs(a[i]);
        if (a[i] < 0) 
            c[i + 1] = c[i] + (vow[n] - vow[x]);
        else
            c[i + 1] = c[i] + vow[x + 1];
    }
    cin >> q;
    for (long long k; q-- > 0 && cin >> k; ) 
    {
        if (k > c[m]) 
            cout << -1 << endl;
        else 
        {
            int i = lower_bound(c, c + m + 1, k) - c;
            long long x = k - c[i - 1];
            if (a[i - 1] < 0) 
            {
                int v = vow[abs(a[i - 1])];
                cout << t[v + x - 1] << endl;
            } 
            else
                cout << t[x - 1] << endl;
        }
    }
    return 0;
}
