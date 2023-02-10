#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long l, r, n, ar[100100], dp[100100], sum_a[100100], sum_dp[100100];
	vector<long long> vc;
	cin >> n >> l >> r;
    for(long long i = 0; i < n; i++)
    	cin >> ar[i];
    for(long long i = 0; i < n; i++)
	{
    	sum_a[i + 1] = sum_a[i] + ar[i];
    	long long st = lower_bound(vc.begin(), vc.end(), sum_a[i + 1] - r) - vc.begin(), en = upper_bound(vc.begin(), vc.end(), sum_a[i + 1] - l) - vc.begin();
    	dp[i] = sum_dp[en] - sum_dp[st];
    	if(sum_a[i + 1] >= l && sum_a[i + 1] <= r)
        	dp[i]++;
    	dp[i] %= 1000000007;  
    	sum_dp[i + 1] = sum_dp[i] + dp[i];
    	vc.push_back(sum_a[i + 1]);
    }
    cout << dp[n - 1] << endl;
}
