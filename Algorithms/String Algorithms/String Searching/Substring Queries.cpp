#include <bits/stdc++.h>
using namespace std;
char str[200200];
long long sum[200200 << 2];
int mint[200200 << 2], maxt[200200 << 2], lazy[200200 << 2];
 
struct SuffixArray 
{
    vector<int> lcp;
    vector<vector<pair<int, int>>> rmq;
    int n, h;
    vector<int> sa, invsa;
    bool cmp(int a, int b)
	{
        return invsa[a+h] < invsa[b+h];
    }
    void ternary_sort(int a, int b)
	{
        if(a == b) 
			return;
        int pivot = sa[a + rand() % (b - a)], left = a, right = b;
        for(int i = a; i < b; i++)
            if(cmp(sa[i], pivot))
            	swap(sa[i], sa[left++]);
        for(int i = b-1; i >= left; i--)
            if(cmp(pivot, sa[i]))
                swap(sa[i], sa[--right]);
        ternary_sort(a, left);
        for(int i = left; i < right; i++)
            invsa[sa[i]] = right - 1;
        if(right - left == 1) 
			sa[left] = -1;
        ternary_sort(right, b);
    }
    SuffixArray(){}
    SuffixArray(vector<int> v): n(v.size()), sa(n) 
	{
        v.push_back(INT_MIN);
        invsa = v; iota(sa.begin(), sa.end(), 0);
        h = 0; ternary_sort(0, n);
        for(h = 1; h <= n; h *= 2)
            for(int j = 0, i = j; i != n; i = j)
                if(sa[i] < 0)
				{
                    while(j < n && sa[j] < 0) 
						j += -sa[j];
                    sa[i] = -(j - i);
                } 
				else 
				{
                    j = invsa[sa[i]] + 1;
                    ternary_sort(i, j);
                }
        for(int i = 0; i < n; i++)
            sa[invsa[i]] = i;
        lcp.resize(n);
        int res = 0, logn = 0;
        for(int i = 0; i < n; i++)
		{
            if(invsa[i] > 0) 
				while(v[i + res] == v[sa[invsa[i] - 1] + res]) 
					res++;
            lcp[invsa[i]] = res;
            res = max(res - 1, 0);
        }
		while((1<<(logn + 1)) <= n) 
			logn++;
        rmq.resize(logn + 1, vector<pair<int, int>> (n));
        for(int i = 0; i < n; i++) 
			rmq[0][i] = make_pair(lcp[i], i);
        for(int l = 1; l <= logn; l++)
            for(int i = 0; i+(1<<l) <= n; i++)
                rmq[l][i] = min(rmq[l - 1][i], rmq[l - 1][i + (1<<(l - 1))]);
    }
    pair<int ,int> rmq_query(int a, int b)
	{
        int size = b - a + 1, l = __builtin_clz(1) - __builtin_clz(size);
        return min(rmq[l][a], rmq[l][b - (1<<l) + 1]);
    }
    int get_lcp(int a, int b)
	{
        if(a == b) 
			return n - a;
        int ia = invsa[a], ib = invsa[b];
        return rmq_query(min(ia, ib) + 1, max(ia, ib)).first;
    }
};
 
void push(int id, int l, int r)
{
    if(lazy[id] != -1)
	{
        mint[id] = lazy[id];
        maxt[id] = lazy[id];
        sum[id] = 1ll * (r - l + 1) * lazy[id];
        if(l != r)
		{
            lazy[id<<1] = lazy[id];
            lazy[id<<1|1] = lazy[id];
        }
        lazy[id] = -1;
    }
}
 
long long get(int id, int l, int r, int x, int y)
{
    push(id, l, r);
    if(l > y || r < x) 
		return 0;
    if(x <= l && r <= y) 
		return sum[id];
    int mid = (l + r)>>1;
    return get(id<<1, l, mid, x, y) + get(id<<1|1, mid + 1, r, x, y);
}
 
void paint(int id, int l, int r, int x, int y, int v)
{
    push(id, l, r);
    if(l > y || r < x) 
		return;
    if(x <= l && r <= y && maxt[id] <= v) 
		return;
    if(x <= l && r <= y && mint[id] >= v)
	{
        lazy[id] = v;
        push(id, l, r);
        return;
    }
    int mid = (l + r)>>1;
    paint(id<<1, l, mid, x, y, v);
    paint(id<<1|1, mid + 1, r, x, y, v);
    mint[id] = min(mint[id<<1], mint[id<<1|1]);
    maxt[id] = max(maxt[id<<1], maxt[id<<1|1]);
    sum[id] = sum[id<<1] + sum[id<<1|1];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    int len = strlen(str);
    vector<int> vv;
    for(int e = 0; e < len; e++)
        vv.push_back(str[e]);
    for(int e = 0; e < 200200 << 2; e++)
	{
        maxt[e] = mint[e] = len<<1;
        lazy[e] = -1;
    }
    SuffixArray solver(vv);
    int n = len, q;
    vector<vector<pair<int, int>>> queries(len);
    cin >> q;
    vector<long long> rans(q);
    for(int e = 0; e < q; e++)
	{
        int l, r;
        cin >> l >> r; 
		l--; 
		r--;
        int sz = r - l + 1, pos = solver.invsa[l];
        int lo = 0, hi = pos, ans = -1;
        while(lo <= hi)
		{
            int mid = (lo + hi)>>1;
            if(solver.get_lcp(solver.sa[mid], l) >= sz) 
			{
				ans = mid; 
				hi = mid - 1;
			}
            else 
				lo = mid + 1;
        }
        l = solver.sa[ans];
        assert(ans != -1);
        queries[l].push_back(make_pair(sz, e));
    }
    vector<long long> dp(len, 0);
    for(int e = 0; e < len; e++)
	{
        dp[e] += len - solver.sa[e];
        if(e) 
            dp[e] += dp[e-1];
    }
    paint(1, 1, n, n, n, 0);
    for(int e = len - 1; e >= 0; e--)
	{
        int l = solver.sa[e];
        for(pair<int, int> iq : queries[l])
		{
            int sz = iq.first, lo = solver.invsa[l], hi = n - 1, ans = -1;
            while(lo <= hi)
			{
                int mid = (lo + hi)>>1;
                if(solver.get_lcp(solver.sa[mid], l) >= sz) 
				{
					ans = mid; 
					lo = mid + 1;
				}
                else 
					hi = mid - 1;
            }
            rans[iq.second] = 1ll * (ans - e + 1) * sz + get(1, 1, n, ans + 1, n);
            if(e) 
				rans[iq.second] += dp[e - 1];
        }
        paint(1, 1, n, e, n, solver.lcp[e]);
    }
    for(int e = 0; e < q; e++)
        cout << rans[e] << endl;
    return 0;
}
