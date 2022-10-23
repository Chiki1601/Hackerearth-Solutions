#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, t;
    cin >> n >> t;
    long long int arr[12];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int maxi = (1<<n);
    while(t--)
    {
        long long int l, r, ans = 0;
        cin >> l >> r;
        for(int i = 1; i < maxi; i++)
        {
            int bc = 0;
            long long int gc = 1;
            for(int j = 0; j < n; j++)
                if(i & (1<<j))
                {
                    bc += 1;
                    gc = (1ll * gc * arr[j]) / (__gcd(gc, arr[j]));
                }
            long long int cov = r / gc - ((l - 1) / gc);
            if(bc % 2 == 1) 
                ans += cov;
            else 
                ans -= cov;      
        }
        cout << ans << endl;
    }
}
