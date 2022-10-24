#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int c = 0, n = str.size();
        for(int i = 0; i < n; i++)
        {
            if(str[i]=='1' || str[i]=='0' || str[i]=='8')
                c++;
        }
        string dtr = str;
        reverse(dtr.begin(), dtr.end());
        if(c == n && dtr == str)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}
