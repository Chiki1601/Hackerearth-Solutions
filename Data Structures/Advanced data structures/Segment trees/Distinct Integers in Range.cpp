#include <bits/stdc++.h>
using namespace std;
int n, q, arr[100002], brr[100002];
bitset<5005> st[2][100002 << 2], tmp, base;
 
void build(int node, int L, int R) 
{
	if(L == R) 
    {
		st[0][node][arr[L]] = 1;   
		st[1][node][brr[L]] = 1;
		return ;
	} 
	build(node << 1, L, ((L + R) >> 1));
	build(node << 1 | 1, ((L + R) >> 1) + 1, R);
	st[0][node] = st[0][(node << 1)] | st[0][node << 1 | 1];
	st[1][node] = st[1][(node << 1)] | st[1][node << 1 | 1];
}
 
void RFQ(int node, int L, int R, int i, int j, int k) 
{
	if(i > R || j < L) 
        return ;
	if(i <= L && R <= j) 
    {
	    tmp |= st[k][node];
	    return ;
	}
	RFQ((node << 1), L, ((L + R) >> 1), i, j, k);
	RFQ(node << 1 | 1, ((L + R) >> 1) + 1, R, i, j, k);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n ; ++i) 
        cin >> arr[i];
	for(int i = 0; i < n ; ++i) 
        cin >> brr[i];
	build(1, 0, n - 1);
	cin >> q;
	while(q--) 
    {
	    int a, b, c, d;
		cin >> a >> b >> c >> d;
    	RFQ(1, 0, n - 1, a - 1, b - 1, 0);
	    RFQ(1, 0, n - 1, c - 1, d - 1, 1);
	    cout << tmp.count() << endl;
	    tmp.reset();
	}
	return 0;
}
