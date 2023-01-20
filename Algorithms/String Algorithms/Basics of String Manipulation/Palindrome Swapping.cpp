
#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    string s, t; 
    cin >> s >> t;
    int n = (int)s.length();
    for(int i = 0; i < n / 2; i++)
    {
        vector<char>ok = {s[i], t[i], s[n - i - 1], t[n - i - 1]};
        sort(ok.begin(), ok.end());
        s[i] = ok[0];
        t[i] = ok[1];
        s[n - i - 1] = ok[2];
        t[n - i - 1] = ok[3];
    }
    if(s != t)
        cout << "NO" << "\n";
    else
        cout << "YES" << "\n";
    return 0;
}
