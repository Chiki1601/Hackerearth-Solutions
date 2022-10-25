#include <bits/stdc++.h>
using namespace std;
int f[1000002][10], n;
string s;
 
void update(int i, int j, int val) 
{
    int k = i;
    while(k <= n) 
    {
        f[k][j] += val;
        k += (k & (-k));
    }
}
 
int sum(int i, int j) 
{
    int k = i, ret = 0;
    while(k > 0) 
    {
        ret += f[k][j];
        k -= (k & (-k));
    }
    return ret;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) 
        update(i + 1, s[i] - '0', 1);
    int q;
    cin >> q;
    while(q--) 
    {
        int t; 
        cin >> t;
        if(t == 1) 
        {
            int x, y; 
            cin >> x >> y;
            update(x, s[x - 1] - '0', -1);
            s[x - 1] = '0' + y;
            update(x, y, 1);
        } 
        else 
        {
            int l, r, x, vals[10], mod = 0;
            cin >> l >> r >> x;
            for(int i = 0; i < 10; i++) 
                vals[i] = sum(r, i) - sum(l - 1, i);
            for(int i = 0; i < 10; i++)
                mod = (mod + i * vals[i]) % 9;
            vals[9 - mod]++;
            for(int i = 9; i >= 0; i--) 
            {
                if(x <= vals[i]) 
                {
                    cout << i << endl;
                    break;
                } 
                x -= vals[i];
            }
        }
    }
    return 0;
}
