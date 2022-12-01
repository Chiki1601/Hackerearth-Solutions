#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, a[1000017], t, l, r, x;
    cin >> n >> q;
    while(q--)
	{
        cin >> t >> l >> r;
        l--;
        if(t < 4)
		{
            cin >> x;
            while(l < r)
                if(t == 1)
                    a[l++] |= x;
                else if(t == 2)
                    a[l++] &= x;
                else
                    a[l++] ^= x;
        }
        else if(t == 4)
            cout << accumulate(a + l, a + r, 0ll) << endl;
        else
            cout << accumulate(a + l, a + r, 0, [](int a, int b){  return a ^ b;  }) << endl;
    }
}
