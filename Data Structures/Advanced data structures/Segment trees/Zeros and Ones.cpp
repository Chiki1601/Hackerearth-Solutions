#include<bits/stdc++.h>
using namespace std;
int tree[4000004], N;
 
int constructTree(int ss, int se, int si)
{
	if(ss == se)
	    return tree[si] = 1;
	int mid = (ss + se) >> 1, l = constructTree(ss, mid, 2 * si), r = constructTree(mid + 1, se, 2 * si + 1);
	return tree[si] = l + r;
}
 
void update(int ss, int se, int si, int ind)
{
	if(ss == se && se == ind)
	{
		tree[si] = 0;
		return ;
	}
	int mid = (ss + se) >> 1;
	if(ind >= ss && ind <= mid)
	    update(ss, mid, 2 * si, ind);
	else
	    update(mid + 1, se, 2 * si + 1, ind);
	tree[si] = tree[2 * si] + tree[2 * si + 1];
	return ;
}
 
int rangeQuery(int ss, int se, int si, int k)
{
	if(ss < 1 || se > N || tree[si] < k)
	    return -1;
	if(ss == se && k == 1)
	    return se;
	int leftNode = tree[2 * si], mid = (ss + se) >> 1;
	if(leftNode < k)
	    return rangeQuery(mid + 1, se, 2 * si + 1, k - leftNode);
	else
	    return rangeQuery(ss, mid, 2 * si, k);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n;
	N = n;
	constructTree(1, n, 1);
	cin >> q;
	while(q--)
	{
		int qt, x;
		cin >> qt >> x;
		if(qt == 0)
			update(1, n, 1, x);
		else
			cout << rangeQuery(1, n, 1, x) << endl;
	}
	return 0;
}
