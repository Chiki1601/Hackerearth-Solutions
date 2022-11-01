#include<bits/stdc++.h>
using namespace std;
bool jhooli[26];

int match_string(string a)
{
    bool match[26];
    memset(match, false, 26 * sizeof(bool));
    for(int i = 0; i <= a.length() - 1; i++)
    {   
        if(a[i] >= 97 && a[i] <= 122)
        	match[a[i] - 'a'] = 1;
        else if(a[i] >= 65 && a[i] <= 90)
        	match[a[i] - 'A'] = 1;
    }
    int ans = 0;
    for(int i = 0; i <= 25; i++)
    {
        if(match[i] && jhooli[i])
            ans++;
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    jhooli['l' - 'a'] = 1;
    jhooli['i' - 'a'] = 1;
    jhooli['t' - 'a'] = 1;
    jhooli['e' - 'a'] = 1;
    jhooli['j' - 'a'] = 1;
    jhooli['h' - 'a'] = 1;
    jhooli['o' - 'a'] = 1;
    while(t--)
    {
        int n, k;
        string a;
        cin >> n >> k;
        vector<pair<int, int> >v;
        vector<string> s;
        for(int i = 0; i<=n-1; i++)
        {
            cin >> a;
            s.push_back(a);
            int x = match_string(a);
            v.push_back(make_pair(x, i));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i <= k - 1; i++)
        	cout << s[v[i].second] << " ";
        cout << "\n";
    }
	return 0;
}
