#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
 
struct node
{
    long long rf, lf, mf;
}tree[1000000];
 
void build(long long no, long long start, long long end)
{
    if(start == end)
    {  
		tree[no].lf = tree[no].rf = tree[no].mf = 1;
       	return ;
    }
    long long mid = (start + end)>>1;
    build(no * 2, start, mid);
    build(2 * no + 1, mid + 1, end);
    if(a[mid] == a[mid + 1])
    {
        tree[no].lf = tree[2 * no].lf + tree[2 * no + 1].lf * (a[start] == a[mid]);
        tree[no].rf = tree[2 * no + 1].rf + tree[2 * no].rf * (a[end] == a[mid + 1]);
        long long p = tree[2 * no].rf + tree[2 * no + 1].lf;
        tree[no].mf = max(p, max(tree[2 * no].mf, tree[2 * no + 1].mf));
    }
    else
    {
        tree[no].lf = tree[2 * no].lf;
        tree[no].rf = tree[2 * no + 1].rf;
        tree[no].mf = max(tree[2 * no + 1].mf, tree[2 * no].mf);
    }
}
 
long long query(long long no, long long start, long long end, long long l, long long r)
{
    if(start > end or start > r or l > end)
      	return 0;
    if(l <= start and end <= r)
      	return tree[no].mf ;
    long long mid = (start + end) / 2;
    long long p1 = query(2 * no, start, mid, l, r), p2 = query(2 *no + 1, mid + 1, end, l, r);
    if(a[mid] == a[mid + 1])
    {
        long long p = min(tree[2 * no].rf, mid - l + 1) + min(tree[2 * no + 1].lf, r - mid);
        return max(p, max(p1, p2));
    }
    else
    	return max(p1, p2);
}
 
int main()
{   
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;
    cin >> t;
    while(t--)
    { 
		long long n, q, i, l, r;
      	cin >> n >> q;
      	for(i = 1; i <= n; i++)
      		cin >> a[i];
      	build(1, 1, n);
      	while(q--)
      	{
        	cin >> l >> r;
        	cout << query(1, 1, n, l, r) << "\n";
      	}
    }
}
