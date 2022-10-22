#include<bits/stdc++.h>
using namespace std;
long long n, q, a[100010], p[100010], s[100010];
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for(long long i = 1; i <= n; i++) 
        cin >> a[i];
	for(long long i = 1; i <= n; i++) 
        p[i] = max(p[i - 1], a[i]);
	for(long long i = n; i; i--) 
        s[i] = max(s[i + 1], a[i]);
	for(long long i = 1, l, r; i <= q; i++) 
    {
        cin >> l >> r;
        cout << max(p[l - 1], s[r + 1]) << "\n";
    }
	return 0;
}
