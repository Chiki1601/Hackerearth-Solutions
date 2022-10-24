#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long t;
    cin >> t;
    while(t--)
	{
        long long n;
        unordered_map<char, long long> gg;
        char cur;
        for(long long i = 1; i <= 26; i++) 
			cin >> cur, gg[cur] = i;
        cin >> n;
        vector<pair<string, string>> v(n);
        for(long long i = 0; i < n; i++)
		{
            cin >> v[i].second;
            v[i].first = "";
            for(long long j = 0; j < v[i].second.size(); j++)
                 v[i].first += (char)(gg[v[i].second[j]] - '0');
        }
        sort(v.begin(), v.end());
        for(long long i = 0; i < n; i++)
            cout << v[i].second << endl;
    }
}
