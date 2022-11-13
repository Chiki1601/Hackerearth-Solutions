#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	{
        int n, k, value[26], per[26], need[26] = {};
        string s;
        cin >> n >> k >> s;
        vector<int> have[26];
        for(int i = 0; i < n; i++)
            have[s[i] - 'a'].push_back(i);
        for(int i = 0; i < 26; i++)
            cin >> value[i];
        iota(per, per + 26, 0);
        sort(per, per + 26, [&](int i, int j)
		{  
			return value[i] != value[j] ? value[i] > value[j] : i < j;  
		});
        set<int> picked;
        for_each(per, per + 26, [&](int i)
		{
            for(int j = 0; j < have[i].size(); j++)
                if(have[i].size() - j <= k || k && s[*picked.lower_bound(have[i][j])] - 'a' > i)
                    picked.insert(have[i][j]), k--;
        });
        for(auto i : picked)
            cout << s[i];
        cout << endl;
    }
}
