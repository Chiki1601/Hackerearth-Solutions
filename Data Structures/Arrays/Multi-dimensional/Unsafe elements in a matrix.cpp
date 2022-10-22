#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	{
        int n, m;
        cin >> n >> m;
        vector<int> rmx(n, INT_MIN), cmx(m, INT_MIN), rmn(n, INT_MAX), cmn(m, INT_MAX);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
			{
                int x;
                cin >> x;
                rmx[i] = max(rmx[i], x);
                cmx[j] = max(cmx[j], x);
                rmn[i] = min(rmn[i], x);
                cmn[j] = min(cmn[j], x);
            }
        int mx = *max_element(rmx.begin(), rmx.end()), mn = *min_element(rmn.begin(), rmn.end()), r = 0, c = 0;
        for(int i = 0; i < n; i++)
            r += rmn[i] != mn && rmx[i] != mx;
        for(int i = 0; i < m; i++)
            c += cmn[i] != mn && cmx[i] != mx;
        cout << c * r << endl;
    }
}
