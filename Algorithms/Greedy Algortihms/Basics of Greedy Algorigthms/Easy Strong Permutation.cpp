#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long nums[100005], n, sum;
	cin >> n; 
	for(int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0; i < n / 2; ++i)
        sum -= 2 * nums[i], sum += 2 * nums[n - 1 - i];
    cout << sum << endl;
}
