#include<bits/stdc++.h>
using namespace std;
        
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, q;
    cin >> n >> q;
    long long a[n + 1] = {0}, b[n + 1] = {0};
    for(long long i = 0; i < n; i++)
        cin >> a[i];
    for(long long j = 0; j < n; j++)
        cin >> b[j];
    long long ans1[n + 1] = {0}, ans2[n + 1] = {0};
    for(long long i = n - 1; i >= 0; i--)
    {
        ans1[i] = ans1[std::min(n, i + 2)] + a[i] + b[i + 1];
        ans2[i] = ans2[std::min(n, i + 2)] + b[i] + a[i + 1];
    }
    for(long long i = 0; i < q; i++)
    {
        long long value, l, r;
        cin >> value >> l >> r;
        if(value == 1)
        {
            if((r - l) % 2 != 0)
                cout << ans1[l - 1] - ans1[r + 1 - 1] << endl;
            else
                cout << ans1[l - 1] - ans1[r - 1] + a[r - 1] << endl;
        }
        else
        {
            if((r - l) % 2 != 0)
                cout << ans2[l - 1] - ans2[r + 1 - 1] << endl;
            else
                cout << ans2[l - 1] - ans2[r - 1] + b[r - 1] << endl;
        }
    }
    return 0;
}
