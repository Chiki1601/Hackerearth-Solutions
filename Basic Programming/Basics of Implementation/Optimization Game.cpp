#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long int n, i, ans = 0;
        cin >> n;
        vector<long long> arr(n + 200);
        for(i = 0; i < n; i++)
            cin >> arr[i];
        for(i = 0; i < n + 199; i++)
        {
            arr[i + 1] += arr[i]/2;
            arr[i] %= 2;
            ans += arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}
