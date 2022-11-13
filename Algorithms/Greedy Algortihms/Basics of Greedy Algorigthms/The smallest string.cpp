#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            if((26 - (s[i] - 'a')) <= k && s[i] != 'a')
            {
            	  k -= (((26 - (s[i] - 'a'))));
            	  s[i] = 'a';
            }
        }
        s[n - 1] += (k % 26);
        cout << s << endl;  
    }
}
