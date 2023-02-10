#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
void solve()
{
    int n, sz = 0, q, x;
    cin >> n;
    oset<pair<int, int>> os;
    while(n--)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> x;
            os.insert({x, sz});
            sz++;
        }
        else
        {
            if(sz < 3)
                cout << "Not enough enemies" << endl;
            else
                cout << os.find_by_order(sz-sz/3)->first << endl;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
