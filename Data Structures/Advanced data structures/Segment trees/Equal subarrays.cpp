#include <bits/stdc++.h>
using namespace std;
int mx[18][100010];
 
int get(int l, int r) 
{
    if(r <= l) 
		return 0;
    int lg = 31 - __builtin_clz(r - l);
    return max(mx[lg][l], mx[lg][r - (1 << lg)]);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, a[100010], ans = 0;
    cin >> n >> k;
	long long par[100010];
    for(int i = 0; i < n; ++i) 
	{
        cin >> a[i];
        mx[0][i] = a[i];
        par[i + 1] = par[i] + a[i];
    }
    for(int i = 1; i < 18; ++i)
        for(int j = 0; j < n; ++j) 
		{
            mx[i][j] = mx[i - 1][j];
            if(j + (1 << (i - 1)) < n)
                mx[i][j] = max(mx[i][j], mx[i - 1][j + (1 << (i - 1))]);
        }
    for(int i = 0; i < n; ++i) 
	{
        int b = i, e = n, mid;
        while(e - b > 1) 
		{
            mid = (b + e) >> 1;
            long long val = get(i, mid + 1) * (long long)(mid - i + 1) - (par[mid + 1] - par[i]);
            if(val <= k)
                b = mid;
            else
                e = mid;
        }
        ans = max(ans, e - i);
    }
    cout << ans << endl;
    return 0;
}
