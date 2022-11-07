#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	long long a[200001], pre[200001], suff[200001];
    cin >> n;
    for(int i = 1; i <= n; i++) 
		cin >> a[i];
    pre[1] = 0;
    for(int i = 2; i <= n; i++)
        pre[i] = (pre[i - 1] + a[i - 1]) / 2;
    suff[n] = 0;
    for(int i = n - 1; i >= 1; i--)
        suff[i] = (suff[i + 1] + a[i + 1]) / 2;
    long long  ans = -1;
    for(int i = 1; i <= n; i++)
        ans = max(ans, a[i] + suff[i] + pre[i]);
    cout << ans;
}
