#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, s = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s += x;
    }
    long long ans = (s * s) / 4;
    cout << ans;
}
