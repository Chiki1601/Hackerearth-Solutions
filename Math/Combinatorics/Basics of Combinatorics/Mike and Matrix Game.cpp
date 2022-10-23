#include <bits/stdc++.h>
using namespace std;
double fact[1005];
int n, k;
 
double get(int num)
{
	return exp(fact[num] + fact[k] + fact[n - k] - (fact[n] + fact[k - 1] + fact[num - (k - 1)]));
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, x, arr[1005][1005];
    double P, p, ans;
    for(i = 1; i < 1005; i++)
    	fact[i] = fact[i - 1] + log(i);
    cin >> n >> k >> x;
    for(i = 0; i < n; i++)
    	for(j = 0; j < n; j++)
    		cin >> arr[j][i];
    ans = 0;
    for(i = 0; i < n; i++)
	{
    	sort(arr[i], arr[i] + n);
    	P = 1;
    	for(j = 0; j < n; j++)
		{
    		if(arr[i][j] + x < arr[i][n - 1] || j < k - 1)
    			continue;
    		p = get(j);
    		ans += p * (arr[i][j] + x);
    		P -= p;
    	}
    	ans += P * (arr[i][n - 1]);
    }
	cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
