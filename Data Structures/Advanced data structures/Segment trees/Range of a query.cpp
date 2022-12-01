#include<bits/stdc++.h>
using namespace std;
vector<long long> a(300005);
 
struct data 
{
    long long pref, suff, left, right, ans;
    bool all_same;
};
vector<data> t(1200020);
 
void print(data x)
{
	cout << x.pref << " " << x.suff << " " << x.left << " " << x.right << " " << x.ans << endl;
}
 
data make_data(long long val) 
{
    data res;
    res.pref = 1;
    res.suff = 1;
    res.left = val;
    res.right = val;
    res.ans = val;
    res.all_same = 1;
    return res;
}
 
data combine(data l, data r) 
{
    data res;
    res.ans = max(l.ans, r.ans);
    if(l.right == r.left)
    {
    	long long len = l.suff + r.pref, x = l.right;
    	if(len >= x)
    		res.ans = max(res.ans, x * (x + 1) / 2);
		else
			res.ans = max(res.ans, len * (2 * x - len + 1) / 2);
		res.pref = (l.all_same ? l.suff + r.pref : l.pref);
		res.suff = (r.all_same ? r.pref + l.suff : r.suff);
	}
	else
    {
		res.pref = l.pref;
		res.suff = r.suff;
	}
    res.left = l.left;
    res.right = r.right;
    res.all_same = (l.all_same && r.all_same && l.right == r.left);
    return res;
}
 
void build(long long v, long long tl, long long tr) 
{
    if(tl == tr) 
        t[v] = make_data(a[tl]);
    else 
    {
        long long tm = (tl + tr) / 2;
        build(v *  2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
 
void update(long long v, long long tl, long long tr, long long pos, long long new_val) 
{
    if(tl == tr)
        t[v] = make_data(new_val);
    else 
    {
        long long tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
 
data query(long long v, long long tl, long long tr, long long l, long long r) 
{
    if(l > r) 
        return make_data(0);
    if(l == tl && r == tr) 
        return t[v];
    long long tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
 
int main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long test_case = 1;
	for(int i = 1; i <= test_case; i++)
	{	
        long long n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while(q--)
        {
            long long type;
            cin >> type;
            if(type == 2)
            {
                long long x, y;
                cin >> x >> y;
                update(1, 1, n, x, y);
            }
            else
            {
                long long l, r;
                cin >> l >> r;
                data res = query(1, 1, n, l, r);
                cout << res.ans << " ";
            }
        }
        cout << endl;
    }
	return 0;
}
