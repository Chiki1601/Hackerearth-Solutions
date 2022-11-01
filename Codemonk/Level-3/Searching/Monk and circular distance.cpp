#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long q, n, x, y, r;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = ceil(sqrt(x * x + y * y));
    }
    sort(a, a + n);
    cin >> q;
    while(q--)
    {
        cin >> r;
        cout << (int)(upper_bound(a, a + n, r) - a) << "\n";
    }
    return 0;
}
