#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, ans, cnt[26];
    string s;
    cin >> t;
    while(t--) 
	{
        cin >> s;
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        int n = (int)s.size();
        for(int i = 0; i < n; i++) 
			cnt[s[i] - 'a']++;
        for(int i = 0; i < 26; i++) 
            ans += (cnt[i] % 2);
        ans--;
        ans = max(ans, 0);
        cout << ans << endl;
    }
    return 0;
}
