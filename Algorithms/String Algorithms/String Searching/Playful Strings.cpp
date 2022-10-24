#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
    assert(1 <= T && T <= 50);
    while(T--)
    {
        string s;
        cin >> s;
        assert(1 <= s.length() && s.length() <= 50);
        for(auto& c: s)
            assert('a'<= c && c <= 'z');
        bool ok = true;
        for(int i = 1; i < (int)s.length(); i++)
        {
            int x = s[i - 1] - 'a', y = s[i] - 'a';
            if(!(abs(x - y) == 1 || abs(x - y) == 25))
                ok = false;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
