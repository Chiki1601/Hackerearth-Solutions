#include <bits/stdc++.h>
using namespace std; 
bool prime[100008]; 

struct DSU 
{
    vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1)
    { 
        iota(f.begin(), f.end(), 0); 
    }
    int leader(int x) 
    {
        while(x != f[x]) 
            x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) 
    { 
        return leader(x) == leader(y); 
    }
    bool merge(int x, int y) 
    {
        x = leader(x);
        y = leader(y);
        if(x == y) 
            return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) 
    { 
        return siz[leader(x)]; 
    }
};

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for(int i = 2; i * i <= 100007; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i * i; j <= 100007; j += i)
                prime[j] = false;
        }
   }
   int n;
   cin >> n;
   DSU d(n + 1);
   vector<vector<int>> g(n + 1);
   for(int i = 1; i < n; i++)
   {
		int a, b;
		cin >> a >> b;
		if(prime[a] == true && prime[b] == true)
			continue;
		else if(prime[a] == true)
			g[a].push_back(b);
		else if(prime[b] == true)
			g[b].push_back(a);
		else
			d.merge(a, b);
   }
   long long ans = 0ll;
   for(int i = 1; i <= n; i++)
   {
		if(prime[i])
		{
			long long in_group = 1ll;
			for(auto rel : g[i])
				in_group = in_group + d.size(rel);
			for(auto rel : g[i])
			{
				long long ex = d.size(rel);
				ans = ans + ex * 1ll * (in_group - ex);
				in_group = in_group - ex;
			}
		}
   }
   cout << ans << "\n";
}
