#include <bits/stdc++.h>
using namespace std;
int s[1000005], f[1000005];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n + n; ++i)
    	cin >> s[i];
    f[1] = 1;
    for(int i = 3; i <= n + n; i += 2) 
    	f[i] = (1ll * f[i - 2] * i) % 1000000007;
    for(int i = 2; i <= n + n; ++i) 
	{
    	int cnt = f[n + n - 1];
    	cnt = (cnt + 1000000007 - (1ll * f[i - 2] * f[n + n - i] % 1000000007)) % 1000000007;
    	ans = (ans + 1ll * (s[i] - s[i - 1]) * cnt) % 1000000007;
    }
    cout << ans << endl;
    return 0;
}
