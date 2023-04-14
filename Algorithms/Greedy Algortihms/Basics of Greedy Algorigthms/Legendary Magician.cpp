#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;
    while(t--)
    {   
        int n, ans = 0, prev = 0; 
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i].first;
        for(int i = 0; i < n; i++)
            cin >> a[i].second;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)
        {
            if(a[i].first > prev)
            {
                prev = a[i].second;
                ans++;
            }
            else
                prev = min(prev, a[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}
