#include <bits/stdc++.h>
using namespace std;
int BIT[1000006];
 
void upd(int idx, int val)
{
    for(int i = idx; i <= 1000000; i += (i & (-i)))
    	BIT[i] += val;
}
 
int query(int val)
{
    int ret = 0;
    while(val)
	{
        ret += BIT[val];
        val -= (val & (-val));
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, a[1000006], b[1000006];
    cin >> n;
    for(i = 1; i <= n; i++)
    	cin >> a[i];
    for(i = 1; i <= n; i++)
    	cin >> b[i];
    for(i = 1; i <= n; i++)
        upd(b[i], 1);
    long long int ans = 0;
    for(i = 1; i <= n; i++)
	{
        upd(b[i], -1);
        ans += (query(a[i] - 1));
    }
    cout << ans;
}
