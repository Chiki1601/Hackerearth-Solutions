#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t; 
    while (t--) 
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        auto lex_min_pref = [&] () 
        {
            int i = 1, j = 1;
            while(j < n) 
            {
                if(s[j] < s[j % i]) 
                {
                    ++j;
                    i = j;
                } 
                else if(s[j] == s[j % i]) 
                    ++j;
                else
                    break;
            }
            return s.substr(0, i);
        };
        string r = lex_min_pref();
        while (r.length() < n + k) 
            r += r;
        cout << r.substr(0, n + k) << endl;
    }
    return 0;
}
