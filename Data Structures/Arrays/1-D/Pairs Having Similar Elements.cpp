#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int* a= new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0, ct = 1, ctdis = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1])
            ct++;
        else if(a[i] == (a[i - 1] + 1))
        {
            ct++;
            ctdis++;
        }
        else
        {
            if(ct >= 2 && (ctdis >= 2))
                ans += (((ct) * (ct - 1)) / 2);
            ct = 1;
            ctdis = 1;
        }
    }
    if(ct >= 2 && (ctdis >= 2))
        ans+=(((ct)*(ct-1))/2);
    cout<<ans<<endl;
    return 0;
}
