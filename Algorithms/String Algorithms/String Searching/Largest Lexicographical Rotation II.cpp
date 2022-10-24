#include <bits/stdc++.h>
using namespace std;
 
string min_cyclic_string(string s) 
{
    s += s;
    int n = s.size(), i = 0, ans = 0;
    while(i < n / 2) 
    {
        ans = i;
        int j = i + 1, k = i;
        while(j < n && s[k] >= s[j]) 
        {
            if(s[k] > s[j])
                k = i;
            else
                k++;
            j++;
        }
        while(i <= k)
            i += j - k;
    }
	string ans_ = s.substr(ans, n / 2);
    return ans_;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1; 
	while(t--) 
    {
        string s; 
        cin >> s;
        cout << min_cyclic_string(s) << endl;
    }
	return 0;
}
