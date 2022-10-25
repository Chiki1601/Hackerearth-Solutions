#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> os;
 
int pos(int p)
{
    auto s = os.lower_bound(p);
    if(s == os.end())
        return os.size();
    return os.order_of_key(p);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a[1000014], x, q;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
	{
        cin >> a[i];
        if(a[i] == x)
            os.insert(i);
    }
    cin >> q;
    while(q--)
	{
        int t;
        cin >> t;
        if(t == 1)
		{
            int l, r, k;
            cin >> l >> r >> k;
            l--, k--;
            if(pos(l) == n || pos(l) + k >= pos(r))
                cout << "-1\n";
            else
                cout << *os.find_by_order(pos(l) + k) + 1 << '\n';
        }
        else
		{
            int i, v;
            cin >> i >> v;
            i--;
            if(a[i] == x)
                os.erase(i);
            a[i] = v;
            if(a[i] == x)
                os.insert(i);
        }
    }
}
