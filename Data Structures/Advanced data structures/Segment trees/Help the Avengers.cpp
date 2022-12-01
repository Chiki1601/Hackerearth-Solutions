#include <bits/stdc++.h>
using namespace std;
int f[100005], n, a[100005];
 
template<int MAXP> struct BitSieve 
{
	#define isOn(x) (p[x >> 6] & (1 << ((x & 63) >> 1)))
	#define turnOn(x) (p[x >> 6] |= (1 << ((x & 63) >> 1)))
	int p[(MAXP >> 6) + 1];
	BitSieve() 
    {
		for(int i = 3; i * i <= MAXP; i += 2) 
        {
			if(!isOn(i)) 
            {
				int ii = i * i, i2 = i << 1;
				for(int j = ii; j <= MAXP; j += i2) 
                    turnOn(j);
			}
		}
	}
	bool operator [] (const int x) 
    {
		return x > 1 && (x == 2 || ( (x & 1) && !isOn(x) ) );
	}
};BitSieve<(1000050)> prime;
 
void update(int u, int gt)
{
	for(int i = u; i < 100005; i += i & -i) 
        f[i] += gt;
}
 
int get(int u)
{
	int res = 0;
	for(int i = u; i > 0; i -= i & -i) 
        res += f[i];
	return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    for(int itest = 0; itest < test; ++itest)
    {
        cin >> n;
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            update(i, prime[a[i]]);
        }
        int q, u, v;
        char ch;
        cin >> q;
        for(int run = 0; run < q; ++run)
        {
            cin >> ch >> u >> v;
            if(ch == 'A')
                cout << get(v) - get(u - 1) << "\n";
            else
            {
                update(u, prime[v] - prime[a[u]]);
                a[u] = v;
            }
        }
    }
    return 0;
}
