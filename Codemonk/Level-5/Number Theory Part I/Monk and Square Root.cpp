#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t; 
    cin >> t;
    while(t--)
    {
        long long n, m, ans = -1;
        cin >> n >> m;
        for(long long i = 0; i < m; i++)
        if((i * i) % m == n)
        {
            ans = i;
            break;
        }
        cout << ans << "\n";
    }
}
