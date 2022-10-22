#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, i;
    cin >> t;
    while(t--)
    {
		string s;
        cin >> s;
        int hsh[26] = {0}, n = s.size();
        for(i = 0; i < n; i++)
            hsh[s[i] - 'a']++;
        int m1 = min(hsh[1], hsh[17]), m2 = min(hsh[20],hsh[24]); 
        cout << min(m1, m2) << endl;
    }
}
