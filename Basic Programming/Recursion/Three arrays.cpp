#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[10014], b[10014], c[10014], l[10014], r[10014];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 0; i < 3; i++)
        cin >> l[i] >> r[i];
    for(int i = l[0]; i <= min(l[0] + m, r[0]); i++)
        for(int j = l[1]; j <= min(l[1] + m, r[1]); j++)
            for(int k = l[2]; k <= min(l[2] + m, r[2]); k++)
			      {
                int cnt = 0;
                for(int l = 0; l < n; l++)
                    cnt += ((long long) i * a[l] + (long long) j * b[l] - (long long) k * c[l]) % m == 0;
                cerr << cnt << endl;
                if(cnt == ::k)
                    return cout << i << ' ' << j << ' ' << k << '\n', 0;
             }
    cout << "-1" << endl;
}
