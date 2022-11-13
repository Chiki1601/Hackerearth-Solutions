#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for(int c = 1; c <= tc; c++) 
    {
        int n, pref = 0, ans = 0;
        cin >> n;
        vector<int> arr(n), suff(n + 1, 1000000007), pos;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = n - 1; i >= 0; i--) 
            suff[i] = min(suff[i + 1], arr[i]);
        for(int i = 0; i < n; i++) 
        {
            if(pref <= arr[i] && arr[i] <= suff[i + 1]) 
                pos.push_back(i);
            pref = max(pref, arr[i]);
        }
        if(pos.empty()) 
            ans = n * n;
        else 
        {
            ans = pos.front() * pos.front();
            for(int i = 1; i < pos.size(); i++) 
            {
                int k = pos[i] - pos[i - 1] - 1;
                ans += k * k;
            }
            int k = n - 1 - pos.back();
            ans += k * k;
        }
        cout << ans << endl;
    }
    return 0;
}
