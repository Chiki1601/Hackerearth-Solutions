#include <bits/stdc++.h>
using namespace std;
int n[2], k, cur_k, pool, cnt[2][2000 << 1], a[2][2000];
pair <int, int> pos[2000 << 1];
long long res;
unordered_map <int, int> mp;
unordered_map <int, int>::iterator it;
    
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n[0] >> n[1] >> k;
    for(int i = 0; i < n[0]; ++i)
	{
        cin >> a[0][i];
        if((it = mp.find(a[0][i])) == mp.end())
            a[0][i] = mp[a[0][i]] = pool++;
        else
            a[0][i] = it->second;
    }
    for(int i = 0; i < n[1]; ++i)
	{
        cin >> a[1][i];
        if ((it = mp.find(a[1][i])) == mp.end())
            a[1][i] = mp[a[1][i]] = pool++;
        else
            a[1][i] = it->second;
    }
    memset(pos, -1, sizeof(pos));
    for(int i = 0; i < n[0]; ++i)
    	for(int j = 0; j < n[1]; ++j)
    		if(pos[i - j + 2000] == pair <int, int>(-1, -1))
        		pos[i - j + 2000] = pair <int, int>(i, j);
    		else
        	pos[i - j + 2000] = min(pos[i - j + 2000], pair <int, int>(i, j));
    for(int diff = -max(n[0], n[1]); diff < max(n[0], n[1]); ++diff)
    	if(pos[diff + 2000] != pair <int, int>(-1, -1))
		{
        	memset(cnt, 0, sizeof(cnt));
        	cur_k = 0;
        	for(int i0 = pos[diff + 2000].first, j0 = i0, i1 = pos[diff + 2000].second, j1 = i1; i0 < n[0] && i1 < n[1]; ++i0, ++i1)
			{
            	++cnt[0][a[0][i0]];
            	++cnt[1][a[1][i1]];
            	cur_k += cnt[1][a[0][i0]] + cnt[0][a[1][i1]] - (a[0][i0] == a[1][i1]);
            	while(cur_k - cnt[1][a[0][j0]] - cnt[0][a[1][j1]] + (a[0][j0] == a[1][j1]) >= k)
				{
                	cur_k -= cnt[1][a[0][j0]] + cnt[0][a[1][j1]] - (a[0][j0] == a[1][j1]);
                	--cnt[0][a[0][j0]];
                	--cnt[1][a[1][j1]];
                	++j0, ++j1;
            	}
            	if(cur_k >= k)
                	res += min(j0, j1) + 1;
        	}
    	}
    cout << res;
    return 0;
}
