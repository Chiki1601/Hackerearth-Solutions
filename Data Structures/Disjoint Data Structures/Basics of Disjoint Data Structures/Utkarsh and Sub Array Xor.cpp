#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> pr;
long long n;
 
long long bin(long long x, long long y) 
{
    if(y == 0) 
        return 1;
    long long u = bin(x, y / 2);
    if(y % 2 == 0) 
        return u * u % 1000000007;
    else 
        return u * u * x % 1000000007;
}
 
long long dsuFind(long long x) 
{
    if(pr.find(x) == pr.end() || pr[x] == x)
        return x;
    long long res = dsuFind(pr[x]);
    pr[x] = res;
    return res;
}
 
void dsuUnite(long long u, long long v) 
{
    long long A = dsuFind(u), B = dsuFind(v);
    if(rand() % 2) 
        pr[A] = B;
    else 
        pr[B] = A;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    assert(1 <= n && n <= 1000000000 * 1E6);
    int k;
    cin >> k;
    assert(k <= 1E6);
    assert(k <= (long long)n * (n - 1) / 2);
    long long ans = bin(2, n);
    for(int i = 0; i < k; i++) 
	{
        long long u, v;
        cin >> u >> v;
        assert(u <= v);
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        u--;
        if(dsuFind(u) != dsuFind(v) ) 
		{
            ans = ans * bin(2, 1000000005) % 1000000007;
            dsuUnite(u, v);
        }
        cout << ans << endl;
    }
    return 0;
}
