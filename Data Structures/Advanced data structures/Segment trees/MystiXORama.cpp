#include <bits/stdc++.h>
using namespace std;

struct SegTree 
{
    long long int n;
    vector<long long int> t;
    SegTree(long long int n_) 
	{
        n = n_;
        t.resize(2 * n + 5, 0);
    }
    void modify(long long int p, long long int value) 
	{
      	for(t[p += n] = value; p > 1; p >>= 1) 
	  		t[p>>1] = t[p] + t[p^1];
    }
    long long int query(long long int l, long long int r) 
	{
      	r++; 
      	long long int res = 0;
      	for(l += n, r += n; l < r; l >>= 1, r >>= 1) 
	  	{
        	if(l & 1) 
				res += t[l++];
        	if(r & 1) 
				res += t[--r];
      	}
      	return res;
    }
};

struct Query 
{
    long long int l, r, x, y, ind;
};

int S;

bool cmp(Query A, Query B)
{
  	if(A.l / S != B.l / S) 
		return A.l < B.l;
  	return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int T;
    cin >> T;
    for(long long int tc = 1; tc <= T; tc++)
    {
		long long int n, q;
		cin >> n;
		vector<long long int> a(n + 1);
		for(long long int i = 1; i <= n; i++) 
			cin >> a[i];
		SegTree st(n + 5);
		S = sqrt(n);
		cin >> q;
		vector<long long int> ans(q), arr(n + 1);
		vector<Query> Q(q);
		map<long long int, long long int> freq;
		for(long long int i = 0; i < q; i++) 
		{
			long long int l, r, x, y;
			cin >> Q[i].l >> Q[i].r >> Q[i].x >> Q[i].y;
			Q[i].ind = i;
		}
		sort(Q.begin(), Q.end(), cmp);
		auto check = [&](long long int ind, long long int f) 
		{
			arr[freq[a[ind]]] ^= a[ind];
			st.modify(freq[a[ind]], arr[freq[a[ind]]]);
			freq[a[ind]] += f;
			arr[freq[a[ind]]] ^= a[ind];
			st.modify(freq[a[ind]], arr[freq[a[ind]]]);
		};
		long long int curL = Q[0].l, curR = Q[0].l - 1;
		for(long long int i = 0; i < q; i++) 
		{
			while(curL > Q[i].l) 
				check(--curL, 1);
			while(curR < Q[i].r) 
				check(++curR, 1);
			while(curL < Q[i].l) 
				check(curL++, -1);
			while(curR > Q[i].r) 
				check(curR--, -1);
			ans[Q[i].ind] = st.query(Q[i].x, Q[i].y);
		}
		for(long long int i = 0; i < q; i++) 
			cout << ans[i] << "\n";
	}
	return 0;  
}
