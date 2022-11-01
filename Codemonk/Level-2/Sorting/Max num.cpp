#include <bits/stdc++.h>
using namespace std;

__int128 fac(int n)
{
    __int128 ans = 1;
    while(n)
        ans *= n--;
    return ans;
}

long long c(int n, int r)
{
    return fac(n) / fac(n - r) / fac(r);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	{
        int n, l;
        assert(cin >> n >> l);
        map<int, long long> inc;
        while(n--)
		{
            int x;
            assert(cin >> x);
            for(int i = 0; i < 30; i++)
                inc[i] += x & 1 << i;
        }
        map<long long, int, greater<long long>> have;
        for(int i = 0; i < 30; i++)
            have[inc[i]]++;
        have.erase(0);
        long long ans = 1;
        for(auto [v, n] : have)
		{
            int x = min<long long>(l, n);
            ans *= c(n, x);
            l -= x;
        }
        cout << (l ? -1 : ans) << "\n";
    }
}
