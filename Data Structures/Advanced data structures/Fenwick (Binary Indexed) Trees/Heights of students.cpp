#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
long long A[100005];
 
int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed;
    int t, n;
    cin >> t;
    while(t--) 
    {
        cin >> n;
        long long ans = 0, tmp, mn = INT_MIN;
        for(int i = 0; i < n; ++i) 
            cin >> A[i];
        indexed_set<long long> is;
        for(int i = n - 1; i >= 0; --i)
        {
            tmp = is.order_of_key(A[i]) - is.size() + is.order_of_key(A[i]+1);
            mn = max(mn,tmp);
            ans += is.order_of_key(A[i]);
            is.insert(A[i]);
        }
        cout << ans - mn << endl;
    }
    return 0;
}
