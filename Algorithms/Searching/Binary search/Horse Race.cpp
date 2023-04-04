#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t > 0)
    {
        t--;
        long long n, m, x;
        cin >> n >> m >> x;
        vector<long long> bk(m, 0);
        for(long long i = 0; i < n; i++)
        {
            long long v;
            cin >> v;
            v--;
            if(v < m)
                bk[v]++;
        }
        long long l = 0, r = n;
        while(l <= r)
        {
            long long te = (l + r) / 2, mop = 0;
            if(te * m > n)
            {
                r = te - 1;
                continue;
            }
            for(auto &nx : bk)
                mop += max(0ll, te - nx);
            if(mop <= x)
                l = te + 1;
            else
                r = te - 1;
        }
        cout << r << endl;
    }
    return 0;
}
