#include <bits/stdc++.h> 
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q, l, r; 
	cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) 
		cin >> a[i];
    vector<int> presum(n + 1, 0);
    for(int i = 0; i < n; i++) 
		presum[i + 1] = presum[i] ^ a[i];
    while(q --)
	{
        cin >> l >> r;
        l--; 
		r--;
        cout << (presum.back() ^ presum[r + 1] ^ presum[l]) << "\n";
    }
    return 0;
}
