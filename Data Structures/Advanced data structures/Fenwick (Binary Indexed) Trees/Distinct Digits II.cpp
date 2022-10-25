#include <bits/stdc++.h>
using namespace std;
int tree[11][100005] = {0};
 
void update(int distinct, int pos, int val)
{
    for(int i = pos; i < 100005; i += (i & -i))
        tree[distinct][i] += val;
}
 
int get(int distinct, int pos)
{
    int ans = 0;
    for(int i = pos; i > 0; i -= (i & -i))
        ans += tree[distinct][i];
    return ans;
}
 
int query(int distinct, int l, int r)
{
    int ans = get(distinct, r) - get(distinct, l-1);
    return ans;
}
 
int countDistinct(long long a)
{
    bool d[10] = {0};
    int f, res = 0;
    if(a == 0) 
        return 1;
    while(a > 0)
    {
        f = a % 10; 
        a /= 10;
        if(d[f] == false) 
            res++;
        d[f] = true;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, i, dif, l, r; 
    string st;
    cin >> n;
    long long a[100005];
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        dif = countDistinct(a[i]);
        update(dif, i, 1);
    }
    cin >> q;
    while(q--)
    {
        cin >> st >> l >> r;
        if(st == "MAX")
        {
            int res = 0;
            for(i = 10; i > 0; i--)
            {
                res = query(i, l, r);
                if(res > 0) 
                    break;
            }
            cout << i << " " << res << "\n";
        }
        if(st == "MIN")
        {
            int res = 0;
            for(i = 1; i < 11; i++)
            {
                res = query(i, l, r);
                if(res > 0) 
                    break;
            }
            cout << i << " " << res << "\n";
        }
        if(st == "ADD")
        {
            dif = countDistinct(a[l]);
            update(dif, l, -1);
            a[l] = (a[l] + r) % 1000000007;
            dif = countDistinct(a[l]);
            update(dif, l, 1);
        }
        if(st == "MUL")
        {
            dif = countDistinct(a[l]);
            update(dif, l, -1);
            a[l] = (a[l] * r) % 1000000007;
            dif = countDistinct(a[l]);
            update(dif, l, 1);
        }
        if(st == "REP")
        {
            dif = countDistinct(a[l]);
            update(dif, l, -1);
            a[l] = r % 1000000007;
            dif = countDistinct(a[l]);
            update(dif, l, 1);
        }
    }
}
