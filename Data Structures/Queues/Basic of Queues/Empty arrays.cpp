#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int>arr(n + 1), brr(n + 1), pos(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    for(int i = 1; i <= n; ++i)
        pos[arr[i]] = i;
    for(int i = 1; i <= n; ++i)
        cin >> brr[i];
    int t = n;
    for(int i = 1; i <= n; ++i)
    {
        int temp = pos[brr[i]];
        ans += temp;
        for(int j = 1; j <= n; ++j)
        {
            if(pos[arr[j]] > temp)
                pos[arr[j]] -= temp;
            else if(pos[arr[j]] < temp)
                pos[arr[j]] = t - temp + pos[arr[j]];
        }
        --t;
    }
    cout << ans << endl;
}
