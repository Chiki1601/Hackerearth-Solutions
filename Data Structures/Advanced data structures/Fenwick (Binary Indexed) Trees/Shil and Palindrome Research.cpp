#include <bits/stdc++.h>
using namespace std;
int BIT[26][500100], a[26][500100], n, q;
 
void update(int x, int val, int pos)
{
    for(; x <= n; x += x & -x)
        BIT[pos][x] += val;
}
 
int query(int x, int pos)
{
    int sum = 0;
    for( ; x > 0; x -= x & -x)
        sum += BIT[pos][x];
    return sum;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        update(i + 1, 1, s[i]-'a');
    while(q--)
    {
        int ty, l, r;
        char ch;
        cin >> ty;
        if(ty == 1)
        {
            cin >> l >> ch;
            update(l, 1, ch - 'a');
            update(l, -1, s[l - 1] - 'a');
            s[l - 1] = ch;
        }
        else
        {
            cin >> l >> r;
            int od = 0;
            for(int j = 0; j < 26; j++)
            {
                int cnt = query(r, j) - query(l - 1, j);
                if(cnt % 2) 
                    od++;
            }
            if(od == 0 && (r - l + 1) % 2 == 0) 
                cout << "yes" << endl;
            else if(od == 1 && (r - l + 1) % 2) 
                cout << "yes" << endl;
            else 
                cout << "no" << endl;
         }
    }
}
