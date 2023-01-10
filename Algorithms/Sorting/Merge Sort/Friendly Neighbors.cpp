#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	{
        int n, cnt = 0, ans = INT_MAX, mark[100014];
        cin >> n;
        fill(mark, mark + n, false);
        map<int, int> mp;
        for(int i = 0; i < n; i++)
		{
            int k;
            cin >> k;
            while(k--)
			{
                int x;
                cin >> x;
                mp[x] = i;
            }
        }
        auto ptr = mp.begin();
        for(auto [x, i] : mp)
		{
            if(!mark[i]++)
                cnt++;
            if(cnt == n)
			{
                while(mark[ptr -> second] > 1)
				{
                    mark[ptr -> second]--;
                    ptr++;
                }
                ans = min(ans, x - ptr -> first);
            }
        }
        cout << 2 * ans << endl;
    }
}
