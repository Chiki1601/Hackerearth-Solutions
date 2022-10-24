#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, ans = 2;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n; i++)
        {
            if(arr[i] >= ans)
                ans += 2;
        }
        cout << ans << endl;
    }         
}
