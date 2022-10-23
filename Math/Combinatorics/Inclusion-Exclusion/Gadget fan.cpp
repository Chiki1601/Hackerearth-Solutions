#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        long long upw = min(n, k / 2), upd = min(n, k), ans = 0;
        ans += ((upw) * (upw + 1)) / 2;
        ans -= (upd * (upd + 1)) / 2;
        ans += ((upw) * (upw + 1)) / 2;
        ans += k * (upd - upw);
        cout << ans << endl;
    }
}
