#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, vis[1000005];
    cin >> t;
    while(t--)
	{
        cin >> n;
        int a[n], sum[n + 1];
        memset(sum, 0, sizeof(sum));
        memset(vis, -1, sizeof(sum));
        for(int i = 0; i < n; ++i)
		{
            cin >> a[i];
            sum[i + 1] = sum[i] + a[i];
            sum[i + 1] %= n;
        }
        int l = 0, r = (int)1e9, templ = 0, tempr = (int)1e9;
        cout << endl;
        for(int i = 0; i <= n; i++)
		{
            if(vis[sum[i]] != -1)
			{
                templ = vis[sum[i]];
                tempr = i;
            }
            vis[sum[i]] = i;
            if((tempr - templ) < (r - l))
			{
                r = tempr;
                l = templ;
            }
        }
        cout << l + 1 << " " << r << endl;
    }
    return 0;
}
