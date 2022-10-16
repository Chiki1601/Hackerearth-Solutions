#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char *s;
    int *res, n, smallest, q, x;
    cin >> n;
    s = new char[n + n];
    res = new int[n];
    cin >> s;
    for(int i = 0; i < n; ++i)
        s[n + i] = s[i];
    res[0] = 0;
    smallest = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(s[smallest + j] > s[i + j])
            {
                smallest = i;
                break;
            }
            else if(s[smallest + j] < s[i + j])
                break;
        }
        res[i] = smallest;
    }
    cin >> q;
    while(q--)
    {
        cin >> x;
        smallest = (x > res[x]) ? res[x] : x;
        cout << smallest << endl;
    }
    return 0;
}
