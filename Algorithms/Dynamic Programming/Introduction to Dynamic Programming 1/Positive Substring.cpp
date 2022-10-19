#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using pdbs_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--)
	{
		string s;
        cin >> n >> s;
		int pref = 0;
		pdbs_set prefs;
		prefs.insert({pref, 0});
		long long int ans = 0;
        for(int i = 0; i < n; ++i)
		{
			pref += s[i] == '1' ? 1 : -1;
            ans += prefs.order_of_key({pref, 0});
			prefs.insert({pref, i + 1});
        }
        cout << ans << "\n";
    }
    return 0;
}
