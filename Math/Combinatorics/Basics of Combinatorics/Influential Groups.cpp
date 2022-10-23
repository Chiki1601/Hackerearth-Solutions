#include <bits/stdc++.h>
using namespace std;
long long numInv[100011], facInv[100011], fac[100011];
 
long long nCr(long long n, long long r) 
{
	return ((fac[n] * facInv[r]) % 1000000007 * facInv[n - r]) % 1000000007;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	numInv[0] = numInv[1] = 1;
	for(int i = 2; i <= 100001; i++) 
        numInv[i] = numInv[1000000007 % i] * (1000000007 - 1000000007 / i) % 1000000007;
	facInv[0] = facInv[1] = 1;
	for(int i = 2; i <= 100001; i++) 
        facInv[i] = (numInv[i] * facInv[i - 1]) % 1000000007;
	fac[0] = 1;
	for(int i = 1; i <= 100001; i++) 
        fac[i] = (fac[i - 1] * i) % 1000000007;
	int n, q; 
    cin >> n >> q;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) 
        cin >> nums[i];
	sort(nums.begin(), nums.end());
	vector<long long> ans(n);
	ans[0] = 1;
	for(int i = 1; i < n; i++)
		ans[i] = (ans[i - 1] + nCr(n - 1, i)) % 1000000007;
	for(int i = 0; i < q; i++)
    {
		int k; 
        cin >> k;
		auto pt = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
		cout << ans[pt] << endl;
	}
}
