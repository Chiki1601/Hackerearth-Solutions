#include <bits/stdc++.h>
using namespace std;
string s;
int tag[100001][22], mxPow, n;
 
void buildSA(string &s) 
{
    n = s.size();
	pair<int, pair<int, int>> v[100001];
    for(int i = 0; i < n; i++)
	{
        v[i].first = s[i] - 'a' + 1;
        v[i].second.first = -1;
        v[i].second.second = i;
        tag[i][0] = v[i].first;
    }
    int len = 1, j = 0;
    while(len < n) 
	{
        len += len;
        j++;
        for(int i = 0; i < n; i++)
		{
            v[i].first = tag[i][j - 1];
            if(i + len / 2 < n) 
				v[i].second.first = tag[i + len / 2][j - 1];
            else 
				v[i].second.first = -1;
            v[i].second.second = i;
        }
        sort(v, v + n);
        int tagId = 1;
        tag[v[0].second.second][j] = 1;
        for(int i = 1; i < n; i++)
		{
            if(v[i].first != v[i - 1].first || v[i].second.first != v[i - 1].second.first) 
                tagId++;
            tag[v[i].second.second][j] = tagId;
        }
    }
    mxPow = j;
}
 
int lcp(int x, int y) 
{
    int res = 0;
    for(int i = mxPow; i >= 0; i--) 
	{
        if(tag[x][i] == tag[y][i]) 
		{
            res += 1 << i;
            x += 1 << i;
            y += 1 << i;
        }
        if(x >= n || y >= n) 
			break;
    }
    return res;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
    cin >> t;
    assert(t >= 1 && t <= 10);
    while(t--) 
	{
        cin >> s;
        buildSA(s);
        int n = s.size();
		vector<pair<int, int>> ranks;
		assert(n > 0 && n <= 100000);
        ranks.clear();
        for(int i = 0; i < n; i++)
            ranks.push_back(make_pair(tag[i][mxPow], i));
        sort(ranks.begin(), ranks.end());
        long long int ans = 0;
        for(int i = 0; i < n; i++) 
		{
            int mx = 0;
            if(i - 1 >= 0) 
				mx = max(mx, lcp(ranks[i - 1].second, ranks[i].second));
            if(i + 1 < n) 
				mx = max(mx, lcp(ranks[i + 1].second, ranks[i].second));
            ans += n - ranks[i].second - mx;
        }
        cout << ans << endl;
    }
    return 0;
}
