#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--)
	{
        string s, t;
        cin >> n >> s >> t;
        vector<int> cnt(26, 0);
        for(auto ch: t)
            cnt[ch-'a']++;
        int wildcard = 0;
        for(auto ch: s)
            if(ch == '?')
                wildcard++;
            else
                cnt[ch-'a']--;
        for(int i = 0; i < 26; ++i)
            wildcard -= max(0, cnt[i]);
        cout << (wildcard < 0 ? "No" : "Yes") << endl;
    }
    return 0;
}
