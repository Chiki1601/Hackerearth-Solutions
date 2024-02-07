#include<bits/stdc++.h>
using namespace std;
int T, n, a[1000005], pre[1000005], suf[1000005], f[1000005][20];

inline int calc(int l, int r)
{
    int len = r - l + 1, now = l, ans = 0;
    for(int i = 0; i < 20; i++)
        if (len >> i & 1) 
        {    
            ans |= f[now][i];
            now += (1 << i);
        }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) 
        {
            cin >> a[i];
            f[i][0] = a[i];
        }
        for(int j = 1; j <= 19; j++)
            for(int i = 1; i <= n; i++)
                if(i + (1 << (j - 1)) <= n) 
                    f[i][j] = f[i][j - 1]|f[i + (1 << (j - 1))][j - 1];
        for(int i = 1; i <= n; i++) 
            pre[i] = pre[i - 1] | a[i];
        suf[n + 1] = 0;
        for(int i = n; i; i--) 
            suf[i] = suf[i + 1]|a[i];
        int now = 0, r = 0, ans1 = n + 1;
        for(int i = 1; i <= n; i++)
        {
            while(r < n && (pre[i - 1] | suf[r + 1]) > now) 
                now |= a[++r];
            if((pre[i - 1]|suf[r + 1]) == now) 
                ans1 = min(ans1, r - i + 1);
            now = calc(i + 1, r);
        }
        if(ans1 == n + 1) 
            cout << -1 << "\n";
        else 
        {
            int ans2 = 0;
            for(int i = 1; i <= n; i++)
            {
                if(i + ans1 - 1 > n) 
                    break;
                if(calc(i, i + ans1 - 1) == (pre[i - 1] | suf[i + ans1])) 
                    ans2++;
            }
            cout << ans1 << " " << ans2 << "\n";
        }
    }
    return 0;
}
