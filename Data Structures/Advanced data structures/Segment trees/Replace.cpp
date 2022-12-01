#include <bits/stdc++.h>
using namespace std;
int a[12000007], sets[12000007], tt;
stack<int> garbage;
 
struct node 
{
	int l, r, s; 
};node seg[12000007];
 
int new_node() 
{
	int u;
	if(garbage.size()) 
    {
        u = garbage.top(); 
        garbage.pop();
    }
	else 
        u = ++tt;
	seg[u].l = seg[u].r = seg[u].s = 0;
	return u;
}
 
void add(int & cur, int l, int r, int j, int x) 
{
	if(cur == 0) 
        cur = new_node();
	if(l == r) 
		seg[cur].s += x;
	else 
    {
		if(j <= ((l + r) >> 1)) 
            add(seg[cur].l, l, ((l + r) >> 1), j, x);
		else 
            add(seg[cur].r, ((l + r) >> 1) + 1, r, j, x);
		seg[cur].s = (seg[cur].l? seg[seg[cur].l].s : 0) + (seg[cur].r? seg[seg[cur].r].s : 0);
	}
}
 
void split(int t1, int & t2, int l, int r, int x) 
{
	if(!t1) 
        return;
	t2 = new_node();
	if(((l + r) >> 1) == x) 
		swap(seg[t1].r, seg[t2].r);
	else if(((l + r) >> 1) < x) 
		split(seg[t1].r, seg[t2].r, ((l + r) >> 1) + 1, r, x);
	else 
    {
		swap(seg[t1].r, seg[t2].r);
		split(seg[t1].l, seg[t2].l, l, ((l + r) >> 1), x);
	}
	if(l == r) 
    {
		if(x < ((l + r) >> 1)) 
            swap(seg[t1].s, seg[t2].s);
	} 
    else 
    {
		seg[t1].s = (seg[t1].l? seg[seg[t1].l].s : 0) + (seg[t1].r? seg[seg[t1].r].s : 0);
		seg[t2].s = (seg[t2].l? seg[seg[t2].l].s : 0) + (seg[t2].r? seg[seg[t2].r].s : 0);		
	}
}
 
void merge(int & t1, int t2) 
{
	if(!t1 or !t2) 
        return void(t1 = (t1? t1 : t2));
	merge(seg[t1].l, seg[t2].l);
	merge(seg[t1].r, seg[t2].r);
	seg[t1].s += seg[t2].s;
	garbage.push(t2);
}
 
int query(int cur, int l, int r, int a, int b) 
{
	if(r < a or l > b or !cur) 
        return 0;
	if(l >= a and r <= b) 
		return seg[cur].s;
	else 
		return query(seg[cur].l, l, ((l + r) >> 1), a, b) + query(seg[cur].r, ((l + r) >> 1) + 1, r, a, b);
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; 
    cin >> n >> q;
	for(int i = 1; i <= n; ++i) 
    {
		cin >> a[i];
		add(sets[a[i]], 1, n, i, 1);
	}
	while(q--) 
    {
		int op, l, r, x, y; 
        cin >> op;
		if(op == 1) 
        {
			cin >> l >> r >> x >> y;
			int aux1 = 0, aux2 = 0;
			split(sets[x], aux1, 1, n, l - 1);
			split(aux1, aux2, 1, n, r);
			merge(sets[x], aux2);
			merge(sets[y], aux1);
		} 
        else 
        {
			cin >> l >> r >> x;
			cout << query(sets[x], 1, n, l, r) << "\n";
		}	
	}
}
