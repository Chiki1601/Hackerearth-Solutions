#include<bits/stdc++.h>
using namespace std;
map<long long, long long>F;
vector<long long>a(100005), tree(400021);
 
long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	else 
        return gcd(b, a % b);
}
 
long long f(long long n)
{
	if(F.count(n))
        return F[n];
	long long k = n / 2;
	if(n % 2 == 0)
	    return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % 1000000007;
	else 
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % 1000000007;
}
void build(long long s, long long e, long long index)
{
	if(s == e)
	{
		tree[index] = a[s];
		return;
	}
	long long mid = (s + e) >> 1ll;
	build(s, mid, 2 * index);
	build(mid + 1, e, 2 * index + 1);
	tree[index] = gcd(tree[2 * index], tree[2 * index + 1]) % 1000000007;
	return;
}
long long query(long long ss, long long se, long long qs, long long qe, long long index)
{
	if(qe < ss || qs > se)
		return 0;
	if(ss >= qs && se <= qe)
		return tree[index] % 1000000007;
	long long mid = (ss + se) >> 1ll;
	long long left = query(ss, mid, qs, qe, 2 * index), right = query(mid + 1, se, qs, qe, 2 * index + 1);
	return gcd(left, right) % 1000000007;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, q;
	F[0] = F[1] = 1;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build(0, n - 1, 1);
	while(q--)
	{
		long long l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << f(query(0, n - 1, l, r, 1) - 1) % 1000000007 << endl;	
	}
	return 0;
}
