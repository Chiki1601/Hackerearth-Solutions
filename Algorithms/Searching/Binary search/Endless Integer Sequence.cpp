#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, cnt = 1; 
	cin >> q;
    ordered_multiset dels;
    for(int i = 0; i < q; i++)
	{
        int x, y; 
		cin >> x >> y;
        if(x == 1)
            dels.insert(y);
        else
		{
            int l = 1, ans = -1, r = 1000000005;
            for(int j = 0; j < 30; j++)
			{
                int mid = l + (r - l) / ((long long)2LL), before = 0;
                if(!dels.empty())
                    before = dels.order_of_key(mid);
                int curCount = mid - before;
                if(curCount <= y)
				{
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
