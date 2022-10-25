#include <bits/stdc++.h>
using namespace std;
int n;
long long f[1234567], h[1234567];
 
void add(long long *f, int x, long long y) 
{
    for(int i = x; i < 1234567; i |= i + 1) 
        f[i] += y;
}
 
long long get(long long *f, int x) 
{
    long long ret = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1) 
        ret += f[i];
  return ret;
}
 
long long getans(int x, int k) 
{
    long long ans = get(f, x - k) * (long long) k;
    ans += get(h, x) - get(h, x - k);
    ans -= (get(f, x) - get(f, x - k)) * ((n - x - 1) - 1);
    return ans;
}
 
int main() 
{
    int q, a[1234567];
    assert(2 == scanf("%d%d", &n, &q));
    for(int i = 0; i < n; i++) 
    {
        assert(1 == scanf("%d", a + i));
        add(f, i, a[i]);
      add(h, i, (long long) a[i] * (n - i - 1));
    }
    for(int i = 0; i < q; i++) 
    {
        int op;
        assert(scanf("%d", &op) == 1);
        if(op == 1) 
        {
            int l, r, k;
            assert(3 == scanf("%d%d%d", &l, &r, &k));
            --l;
            ++k;
            cout << getans(r - 1, k) - getans(l - 1, k) << endl;
        } 
        else 
        {
            int x, y;
            assert(2 == scanf("%d%d", &x, &y));
            --x;
            add(f, x, y - a[x]);
            add(h, x, (long long) (y - a[x]) * (n - x - 1));
            a[x] = y;
        }
    }
}
