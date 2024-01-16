#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string str;
        cin >> str;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) 
            mp[str[i]]++;
        int cnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
            cnt += (it->second & 1);
        cout << max(0, cnt - 1) << endl;
    }
    return 0;
}
