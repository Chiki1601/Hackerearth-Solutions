#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, m, l, r, c, p, q, s;
        cin >> n >> m >> l >> r >> c >> p >> q >> s;
        long long ppl[n + 5] = {0};
        for(int i = 0; i < m; ++i)
        {
         	ppl[l] += c;
         	ppl[r + 1] -= c;
         	long long l1 = (l * p + r) % n + 1, r1 = (r * q + l) % n + 1;
         	if(l1 > r1)
    			swap(l1 , r1);
    		long long c1 = (c * s) % 1000000 + 1;
    		l = l1;
    		r = r1;
    		c = c1;
        }
        long long ind = 1, mx = ppl[1];
        long long curr = ppl[1];
        for(long long i = 2; i <= n; ++i)
        {
         	curr += ppl[i];
         	if(curr > mx)
         	{
         		mx = curr;
         		ind = i;
         	}
        }
        cout << ind << " " << mx << endl;
    }
}
