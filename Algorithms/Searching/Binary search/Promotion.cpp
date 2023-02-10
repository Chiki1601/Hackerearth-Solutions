#include<bits/stdc++.h>
using namespace std;
long long n, m, w[10005], t[10005], c[10005];
 
bool isPos(long long x)
{
    long long left = 0;
    int cap = (x / 2) + (x % 2);
    for(int i = 0; i < m; i++)
        left = max(0LL, c[i] + left - cap);
    if(left)
		    return false;
    return true;
}
 
int main()
{
    cin >> n >> m;
    for(long long i = 0; i < n; i++)
		    cin >> w[i];
    for(long long i = 0; i < m; i++)
        cin >> t[i];
    sort(t, t + m);
    for(int i = 0; i < n; i++)
        c[(lower_bound(t, t + m, w[i]) - t)]++;
    long long l = 0, r = 2 * n;
    int ans = 0;
    while(l < r)
	  {
        long long mi = (l + r) / 2;
        if(isPos(mi))
		        r = mi;
        else
            l = mi + 1;
    }
    cout << l << endl;
}
