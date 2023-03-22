#include <bits/stdc++.h>
using namespace std;    

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n), vis(n);
    for(auto &i : v) 
		cin >> i;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++) 
        ans |= (v[0] | v[i]) << 1;
    cout << ans << "\n";
    return 0;

}
