#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n;
    unordered_map<string, bool> mp;
    cin >> n;
    while(n-->=0)
	{
        string s;
        getline(cin, s);
        long long i = 0;
        while(i < s.size())
		{
            if(s[i] == '=') 
				break;
            i++;
        }
        mp[s.substr(0, i)] = true;
    }
    cout << mp.size() - 1 << endl;
    return 0;
}
