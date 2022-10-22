#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long int  t;
    cin >> t;
    while(t--)
	{
        string s;
        cin >> s;
        int hsh[26] = {0}, ct = 0;
        for(int i = 0; i < s.size(); i++)
            hsh[s[i] - 'a']++;
        for(int i = 0; i < 26; i++)
		{
            if(hsh[i] >= 2)
                ct++;
        }
        if(ct > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
