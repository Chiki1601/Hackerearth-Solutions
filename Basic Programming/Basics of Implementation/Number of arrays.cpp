#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        int a[n];
        for(int i = 0; i < n; i++)
        cin >> a[i];
        int mi=*min_element(a, a + n), mx=*max_element(a, a + n);
        if(k == 1)
        {
            if(mx < q)
                cout << mx << endl;
            else 
                cout << "NO" << endl;
            continue;
        }
        else
        {
            if(mi < q)
                cout << mi << endl;
            else
                cout << "NO" << endl;
        }
    }
}
