#include <bits/stdc++.h>
using namespace std;
int n, m, pref[200005], st[8000020], lazy[800020];
 
void build(int node, int L, int R)
{
    if(L == R)
    {
        st[node] = pref[L];
        return;
    }
    int M = (L + R) / 2;
    build(node * 2, L, M);
    build(node * 2 + 1, M + 1, R);
    st[node] = min(st[node * 2], st[node * 2 + 1]);
}
 
void propagate(int node, int L, int R)
{   
    if(L != R)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    st[node] += lazy[node];
    lazy[node] = 0;
}
 
int query(int node, int L, int R, int i, int j)
{
    if(lazy[node])
        propagate(node, L, R);
    if(j < L || i > R)
        return 1000000000;
    if(i <= L && R <= j)
        return st[node];
    int M = (L + R) / 2;
    int left = query(node * 2, L, M, i, j), right = query(node * 2 + 1, M + 1, R, i, j);
    return min(left, right);
}
 
void update(int node, int L, int R, int i, int j, int val)
{
    if(lazy[node])
        propagate(node, L, R);
    if(j < L || i > R)
        return;
    if(i <= L && R <= j)
    {
        lazy[node] += val;
        propagate(node, L, R);
        return;
    }
    int M = (L + R) / 2;
    update(node * 2, L, M, i, j, val);
    update(node * 2 + 1, M + 1, R, i, j, val);
    st[node] = min(st[node * 2], st[node * 2 + 1]);
}
 
int check(int p, int idx, int mid)
{
    int mn = query(1, 0, n, idx, mid);
    return mn >= p;
}
 
int binsearch(int p, int lo, int hi)
{
    int idx = lo;
    while(lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if(check(p, idx, mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}
 
int check2(int p, int idx, int mid)
{
    int mn = query(1, 0, n, mid, n);
    return mn == p;
}
 
int binsearch2(int p, int lo, int hi)
{
    int idx = lo;
    while(lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if(check2(p, idx, mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}
 
int work(int idx)
{
    int p = query(1, 0, n, idx - 1, idx - 1), mn = query(1, 0, n, idx, n);
    if(mn < p)
    {
        int ans = binsearch(p, idx, n);
        ans = ans - idx + 1;
        if(ans % 2)
            ans--;
        return ans;
    }
    else if(mn > p)
        return 0;
    else
    {
        int ans = binsearch2(p, idx, n);
        ans = ans - idx + 1;
        if(ans % 2)
            ans--;
        return ans;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.size();
    for(int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if(s[i - 1] == '(')
            pref[i]++;
        else
            pref[i]--;
    }
    build(1, 0, n);
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        char ch;
        cin >> ch;
        int idx;
        cin >> idx;
        if(ch == 'C')
        {
            if(s[idx - 1] == '(')
            {
                update(1, 0, n, idx, n, -2); 
                s[idx - 1] = ')';
            }
            else
            {
                update(1, 0, n, idx, n, +2); 
                s[idx - 1] = '(';
            }
        }
        else
            cout << work(idx) << endl;
    }
    return 0;
}
