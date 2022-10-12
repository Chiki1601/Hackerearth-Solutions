#include <bits/stdc++.h>
using namespace std;  
  
string convertToNewString(const string &s) 
{
    string newString = "@";
    for(int i = 0; i < s.size(); i++) 
        newString += "#" + s.substr(i, 1);
    newString += "#$";
    return newString;
}
 
string longestPalindromeSubstring(const string &s) 
{
    string Q = convertToNewString(s);
    int c = 0, r = 0, P[1000002], maxPalindrome = 0, centerIndex = 0; 
    memset(P, 0, sizeof(P));            
    for(int i = 1; i < Q.size() - 1; i++) 
    {
        int iMirror = c - (i - c);
        if(r > i) 
            P[i] = min(r - i, P[iMirror]);
        while(Q[i + 1 + P[i]] == Q[i - 1 - P[i]])
            P[i]++;
        if(i + P[i] > r) 
        {
            c = i;            
            r = i + P[i];
        }
    }
    for(int i = 1; i < Q.size() - 1; i++) 
    {
        if(P[i] > maxPalindrome) 
        {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
    return s.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, cnt = 0;
    cin >> n;
    string s = "";
    cin >> s;
    string ans = longestPalindromeSubstring(s);
    while(ans.length() % 2 == 0)
    {
        cnt++;
        string ss = "";
        for(int i = 0; i < ans.length() / 2; i++)
            ss += ans[i];
        ans = ss;
        ans = longestPalindromeSubstring(ans);
    }
    cout << cnt << endl;
    cout << ans << endl;
    return 0;
}
