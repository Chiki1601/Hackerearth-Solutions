#include <bits/stdc++.h>
using namespace std;
#define int long long
 
string f(int n)
{
    string ans = "";
    while(n > 0)
    {
        if(n % 2)
            ans = "1" + ans;
        else 
            ans = "0" + ans;
        n /= 2;
    }
    if(ans == "")
        return "0";
    return ans;
}
 
int g(string s)
{
    int n = s.size(), i, ans = 0;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '1')
            ans += (1<<(n - 1 - i));
    }
    return ans;
}
 
signed main() 
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; 
    cin >> t;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i <= 31; i++)
    {
        int j = (i + 1) / 2;
        for(int k=(1<<(j - 1)); k < (1<<j); k++)
        {
            string a = f(k);
            string b = a;
            if(i % 2)
                b.pop_back();
            reverse(b.begin(), b.end());
            a += b;
            v.push_back(g(a));
        }
    }
    sort(v.begin(), v.end());
    int m = v.size();
    while(t--)
    {
        int n; 
        cin >> n;
        int l = lower_bound(v.begin(), v.end(), n) - v.begin(), u = (upper_bound(v.begin(), v.end(), n) - v.begin()) - 1;
        if(v[l] == n)
            cout << "0" << endl;
        else
            cout << min(n - v[u], v[l] - n) << endl;        
    }
	return 0;
}
