#include <bits/stdc++.h>
using namespace std;
int n, m, BIT[26][1000000];
 
void update(int c, int x, int k) 
{
    for(; x < n; x += (x & -x)) 
        BIT[c][x] += k;
}
 
int query(int c, int x) 
{
    int result = 0;
    for(; 0 < x; x -= (x & -x)) 
        result += BIT[c][x];
    return result;
}
 
int findChar(char cha, int occ) 
{
    int c = (cha - 'a'), L = 1, R = n - 1;
    while(L < R) 
    {
        int mid = (L + R) / 2;
        if(query(c, mid) >= occ) 
            R = mid;
        else 
            L = mid + 1;
    }
    return L;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s; 
    s = '.' + s;
    n = s.length();
    for(int i = 1; i < n; i++)
        update((int)s[i] - 'a', i, 1);
    cin >> m;
    while(m--) 
    {
        int occ; 
        char cha;
        cin >> occ >> cha;
        int idx = findChar(cha, occ);
        update((int) cha - 'a', idx, -1);
        s[idx] = '.';
    }
    for(char c : s) 
        if(c != '.') 
            cout << c;
    cout << endl;
}
