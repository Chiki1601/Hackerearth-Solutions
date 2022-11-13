#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, str;
    cin >> s >> str;
    int ans = 0;
    for(int h = 0; h < n; h++)
    {
        int c = 0;
        while(h < n and s[h] != str[h])
        {
            c++;
            h++;
        }
        if(c)
            ans++;
    }
    cout << ans << endl;
}
