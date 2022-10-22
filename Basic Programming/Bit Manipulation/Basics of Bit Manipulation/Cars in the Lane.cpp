#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, ans = 0;
        cin >> n;
        while(n)
        {
            n &= (n - 1);
            ans += 1;
        }
        cout << (1<<ans) << endl;
    }
}
