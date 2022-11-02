#include<bits/stdc++.h>
using namespace std;
int arr[100009][3] = {};
 
void foo(int cur, int n)
{
    if(cur > n / 2)
    {
        arr[cur][1] = arr[cur][2] = 0;
        return;
    }
    foo(cur * 2, n);
    foo(cur * 2 + 1, n);
    arr[cur][1] = max(arr[cur * 2][1], arr[cur * 2][2]) + arr[cur * 2][0];
    arr[cur][2] = max(arr[cur * 2 + 1][1], arr[cur * 2 + 1][2]) + arr[cur * 2 + 1][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    assert(t >= 1 && t <= 500);
    while(t--)
    {
        int n, i, ans = -INT_MAX;
        cin >> n;
        assert(n >= 0 && n <= 511);
        assert((n & (n + 1)) == 0);
        for(i = 1; i <= n; i++)
            cin >> arr[i][0];
        foo(1, n);
        for(i = 1; i <= n; i++)
            ans = max(ans, arr[i][0] + arr[i][1] + arr[i][2]);
        cout << ans << endl;
    }
    return 0;
}
