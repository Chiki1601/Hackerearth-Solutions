#include<bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t; 
    cin >> t;
    while(t--)
    {   
        long long int n; 
        cin >> n;
        long long int a[n], ans = 0;
        for(long long int i = 0; i < n; i++)
            cin >> a[i];
        long long int ok = a[0];
        for(long long int i = 1; i < n; i++)
            ok = __gcd(ok, a[i]);
        for(long long int i = 0; i < n; i++)
            ans += (a[i] / ok - 1LL);
        cout << ans << "\n";
    }
    return 0;
}
