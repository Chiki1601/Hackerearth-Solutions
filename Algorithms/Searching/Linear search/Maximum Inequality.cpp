#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t;
    while(t--)
    {   
        int n, prev = -1, ans = 0; 
        cin >> n;
        string s, t1, t2; 
        cin >> s;
        vector<bool>visited(n, false);
        for(int i = 0; i < n; i++)
        {
            int dig = s[i] - '0';
            if(dig != prev)
            {
                prev = dig;
                visited[i] = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                t1 += s[i];
            else
                t2 += s[i];
        }
        for(int i = 0; i < (int)t1.length() - 1; i++)
            ans += (t1[i] != t1[i + 1]);
        for(int i = 0; i < (int)t2.length() - 1; i++)
            ans += (t2[i] != t2[i + 1]);
        cout << ans << endl;
    } 
    return 0;
}
