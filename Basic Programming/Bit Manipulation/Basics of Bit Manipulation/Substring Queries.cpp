#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;
        while(n--)
        {
            string t;
            cin >> t;
            int a[130] = {0}, b[130] = {0};
            for(int i = 0; i < t.size(); i++)
                a[t[i]]++;
            int j = -1, x = 0;
            long long ans = 0;
            for(int i = 0; i < s.size(); i++)
            {
                b[s[i]]++;
                if(b[s[i]] == a[s[i]])
                    x++;
                if(x == t.size())
                {
                    while(1)
                    {
                        j++;
                        b[s[j]]--;
                        ans += s.size() - i;
                        if(b[s[j]] < a[s[j]])
                        {
                            x--;
                            break;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
}
