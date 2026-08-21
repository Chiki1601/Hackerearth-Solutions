include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t;
    while(t--)
    {   
        int n, k, maxm = 0; 
        cin >> n >> k;
        map<int, int> ok;
        string s; 
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            ok[s[i] - 'a']++;
            maxm = max(maxm, ok[s[i] - 'a']);
        }
        if(ok.size() >= k and maxm >= k)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
