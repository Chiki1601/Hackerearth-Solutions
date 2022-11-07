#include <bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
		cin >> a[i];
    for(int i = 0; i < n; i++)
		cin >> b[i];
    cin >> q;
    long long x[400001] = {0}, y[400001] = {0}, s = 0;
    x[0] = 1;
    y[0] = 1;
    for(int j = 0; j < n; j++)
    {
        s += a[j];
        for(int i = s; i >= a[j]; i--)
            x[i] = (x[i] + x[i - a[j]]) % 1000000007;
	}
    long long s2 = 0;
    for(int j = 0; j < n; j++)
    {
        s2 += b[j];
        for(int i = s2; i >= b[j]; i--)
            y[i] = (y[i] + y[i - b[j]]) % 1000000007;
    }
    long long Y[400002] = {0};
    Y[0] = 0;
    for(int i = 1; i <= 400001; i++)
    	Y[i] = Y[i - 1] + y[i - 1];
    long long ans = 0;
    for(int i = 0; i <= s; i++)
    {
        long long t = (Y[min(400001, i + q + 1)] - Y[max(0, i - q)] + 1000000007) % 1000000007;
        ans = (ans + (x[i] * t) % 1000000007 + 1000000007) % 1000000007;
    }
    cout << ans << endl;
    return 0;
}
