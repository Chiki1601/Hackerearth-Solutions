#include<bits/stdc++.h>
using namespace std;
 
int main ()
{
    int t, mixi = 0, maxi = 0;
    cin >> t;
    string b;
    for(int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        b.append(s);
        int n = s.length(), k = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'C' && s[i + 1] == 'C' && i != n - 1)
                k++;
            else
            {
                k += 1;
                mixi = max(mixi, k);
                k = 0;
            }
        }
    }
    int q = b.length(), x = 0;
    char d = 'C';
    for(int j = 0; j < q; j++)
    {
        if(b[j] == d)
            x++;
        else
        {
            maxi = max(maxi, x);
            x = 0;
        }
    }
    maxi = max(maxi, x);
    if(mixi == 1)
        cout << "0" << " " << maxi << endl;
    if(mixi > 1)
        cout << mixi << " " << maxi << endl;
    return 0;
}
