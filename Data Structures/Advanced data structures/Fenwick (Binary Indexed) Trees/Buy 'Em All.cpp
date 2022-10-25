#include <bits/stdc++.h>
using namespace std; 
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, low, high, mid;
    long k, res = 0, now, zz;
    vector<long> v(200001), pre(200001);
    cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = n - 1; i >= 1; i--)
		pre[i] = pre[i + 2] + (v[i] * v[i + 1]);
	for(int i = n - 1; i >= 1; i--) 
    {
		low = 1, high = (n - i + 1) >> 1;
		while(low < high) 
        {
			mid = (low + high + 1) >> 1;
			now = pre[i] - pre[i + (mid << 1)];
			(now <= k) ? low = mid : high = (mid - 1);
		}
		if(pre[i] - pre[i + (low << 1)] <= k)
			res += low;
	}
	for(int i = n; i >= 1; i--) 
    {
		now = k - v[i];
		if(now >= 0) 
        {
			low = 0, high = (i - 1) >> 1;
			while(low < high) 
            {
				mid = (low + high + 1) >> 1;
				zz = pre[i - (mid << 1)] - pre[i];
				(zz <= now) ? low = mid : high = (mid - 1);
			}
			if(pre[i - (low << 1)] - pre[i] <= now)
				res += (low + 1);
		}
	}
	cout << res << endl;
}
