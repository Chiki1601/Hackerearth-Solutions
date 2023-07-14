  #include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1;
    while(tc--)
	{
       	long long n, i, q, l, r;
       	cin >> n;
       	long long a[n + 2], b[n + 2];
		a[0] = b[0] = 0;
       	for(i = 1; i <= n; i++)
	   	{
        	cin >> a[i];
        	b[i] = a[i];
        	a[i] += a[i - 1];
        	b[i] ^= b[i - 1];
       	}
        cin >> l >> r;
        long long cur = (a[r] - a[l - 1] - (b[r] ^ b[l - 1]));
        long long ll = l, rr = r, md, an, mx = (r - l + 1), lf = l, rt = r;
        for(i = l; i <= r; i++)
		{
            ll = i, rr = r, an = -1;
            while(ll <= rr)
			{
                md = (ll + rr) / 2;
                if((a[md] - a[i - 1] - (b[md] ^ b[i - 1])) == cur)
				{
                    an = md;
                    rr = md - 1;
                }
                else 
                    ll = md + 1;
            }
            if(an != -1 && (an - i + 1) < mx)
			{
                mx = (an - i + 1);
                lf = i;
                rt = an;
            }
        }
        cout << lf << " " << rt << "\n";
    }
}
